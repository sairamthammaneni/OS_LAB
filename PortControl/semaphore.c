#include <stdio.h>
#include <stdlib.h> 
#include<pthread.h> 
#include<semaphore.h>
#include<unistd.h>
#define MAX_PORTS 5 
sem_t port_semaphore;
void *open_port(void *port)
{
    int port_number = *((int *)port);
    printf("Attempting to open port %d\n", port_number);

    // Wait until a port becomes available
    sem_wait(&port_semaphore);
    printf("Port %d is opened\n", port_number);

    // Simulate some work on the open port
    sleep(2);

    // Release the port
    sem_post(&port_semaphore);
    printf("Port %d is closed\n", port_number);
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[MAX_PORTS];
    int port_numbers[MAX_PORTS];

    // Initialize the semaphore with the maximum number of ports
    sem_init(&port_semaphore, 0, MAX_PORTS);

    // Create threads to open and use the ports
    for (int i = 0; i < MAX_PORTS; i++)
    {
        port_numbers[i] = i + 1;
        if (pthread_create(&threads[i], NULL, open_port, &port_numbers[i]) != 0)
        {
            perror("Failed to create thread");
            exit(1);
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < MAX_PORTS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    // Destroy the semaphore
    sem_destroy(&port_semaphore);
    return 0;
}
