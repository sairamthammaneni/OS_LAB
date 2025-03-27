#include <stdio.h> 
#include <stdlib.h>

int main() {
    int p[20], bt[20], pri[20], wt[20], tat[20], i, k, n, temp;
    float wtavg = 0, tatavg = 0;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        p[i] = i + 1; // Process ID starting from 1
        printf("Enter the Burst Time & Priority of Process %d: ", i + 1);
        scanf("%d %d", &bt[i], &pri[i]);
    }

    // Sorting processes based on priority (Lower number = Higher priority)
    for (i = 0; i < n; i++) {
        for (k = i + 1; k < n; k++) {
            if (pri[i] > pri[k]) {
                // Swap Priority
                temp = pri[i];
                pri[i] = pri[k];
                pri[k] = temp;

                // Swap Burst Time
                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;

                // Swap Process ID
                temp = p[i];
                p[i] = p[k];
                p[k] = temp;
            }
        }
    }

    // Calculate Waiting Time and Turnaround Time
    wt[0] = 0;
    tat[0] = bt[0];
    wtavg = 0;
    tatavg = tat[0];

    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }

    // Display results
    printf("\nPROCESS\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME");
    for (i = 0; i < n; i++) {
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", p[i], pri[i], bt[i], wt[i], tat[i]);
    }

    printf("\n\nAverage Waiting Time: %.2f", wtavg / n);
    printf("\nAverage Turnaround Time: %.2f\n", tatavg / n);

    return 0;
}
