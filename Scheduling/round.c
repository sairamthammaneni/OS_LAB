#include <stdio.h>

int main() {
    int i, j, n, timeQuantum;
    int burstTime[10], waitingTime[10], turnaroundTime[10], remainingTime[10];
    int total = 0;
    float avgWT = 0, avgTAT = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter Burst Time for process %d: ", i + 1);
        scanf("%d", &burstTime[i]);
        remainingTime[i] = burstTime[i];
    }

    printf("Enter the Time Quantum: ");
    scanf("%d", &timeQuantum);

    int time = 0;
    while (1) {
        int done = 1;
        for (i = 0; i < n; i++) {
            if (remainingTime[i] > 0) {
                done = 0;
                if (remainingTime[i] > timeQuantum) {
                    time += timeQuantum;
                    remainingTime[i] -= timeQuantum;
                } else {
                    time += remainingTime[i];
                    turnaroundTime[i] = time;
                    waitingTime[i] = turnaroundTime[i] - burstTime[i];
                    remainingTime[i] = 0;
                }
            }
        }
        if (done)
            break;
    }

    printf("\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for (i = 0; i < n; i++) {
        avgWT += waitingTime[i];
        avgTAT += turnaroundTime[i];
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, burstTime[i], waitingTime[i], turnaroundTime[i]);
    }

    printf("Average Waiting Time: %.2f\n", avgWT / n);
    printf("Average Turnaround Time: %.2f\n", avgTAT / n);

    return 0;
}
