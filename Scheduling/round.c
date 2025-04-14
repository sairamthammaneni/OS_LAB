#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, n, bu[10], wa[10], tat[10], t, ct[10], max;
    float awt = 0, att = 0, temp = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &bu[i]);
        ct[i] = bu[i];
    }

    printf("Enter the Time Slice: ");
    scanf("%d", &t);

    max = bu[0];
    for (i = 1; i < n; i++)
        if (max < bu[i])
            max = bu[i];

    for (j = 0; j < (max / t) + 1; j++)
    {
        for (i = 0; i < n; i++)
        {
            if (bu[i] != 0)
            {
                if (bu[i] <= t)
                {
                    tat[i] = temp + bu[i];
                    temp += bu[i];
                    bu[i] = 0;
                }
                else
                {
                    bu[i] -= t;
                    temp += t;
                }
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        wa[i] = tat[i] - ct[i];
        att += tat[i];
        awt += wa[i];
    }

    printf("\n+---------+-------------+---------------+-------------------+\n");
    printf("| Process | Burst Time  | Waiting Time  | Turnaround Time   |\n");
    printf("+---------+-------------+---------------+-------------------+\n");

    for (i = 0; i < n; i++)
    {
        printf("|   %3d   |     %3d     |     %3d       |       %3d         |\n", i + 1, ct[i], wa[i], tat[i]);
    }

    printf("+---------+-------------+---------------+-------------------+\n");

    printf("\nAverage Turnaround Time: %.2f", att / n);
    printf("\nAverage Waiting Time   : %.2f\n", awt / n);

    return 0;
}
