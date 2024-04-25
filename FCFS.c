#include <stdio.h>
struct process
{
    int pid;
    int bursttime;
    int waitingtime;
    int turnouttime;
} p[10];
int main()
{
    int total_process;
    int totalturn, totalwait;
    float avgwaitingtime, avgturnouttime;
    printf("Enter the number of processes you want: ");
    scanf("%d", &total_process);
    for (int i = 0; i < total_process; i++)
    {
        printf("Enter the Burst Time for p%d: ", (i + 1));
        scanf("%d", &p[i].bursttime);
        p[i].pid = i + 1;
    }
    p[0].waitingtime = 0;
    for (int i = 0; i < total_process; i++)
    {
        p[i + 1].waitingtime = p[i].bursttime + p[i].waitingtime;
        p[i].turnouttime = p[i].waitingtime + p[i].bursttime;
    }
    totalturn = totalwait = 0;
    for (int i = 0; i < total_process; i++)
    {
        totalturn += p[i].turnouttime;
        totalwait += p[i].waitingtime;
    }
    avgwaitingtime = (float)totalwait / total_process;
    avgturnouttime = (float)totalturn / total_process;

    for (int i = 0; i < 33; i++)
    {
        if (i == 15)
        {
            printf("First Come First Serve Scheduling");
        }
        else
        {
            printf("-");
        }
    }
    printf("\n\nProcess Number            Burst-Time            Waiting-Time");
    for (int i = 0; i < total_process; i++)
    {
        printf("\n      P%d\t              %2d\t             %2d", (i + 1), p[i].bursttime, p[i].waitingtime);
    }
    printf("\n\n");
    for (int i = 0; i < 65; i++)
    {
        printf("-");
    }
    printf("\n\n");
    printf("Average Waiting Time: %f", avgwaitingtime);
    printf("\n\n");
    printf("Average Turnout Time: %f", avgturnouttime);
    printf("\n\n");
    for (int i = 0; i < 55; i++)
    {
        if (i == 25)
        {
            printf("Gantt Chart");
        }
        else
        {
            printf("-");
        }
    }
    printf("\n\n");
    int totalb = 0;
    for (int i = 0; i < total_process; i++)
    {
        totalb = totalb + p[i].bursttime;
    }
    totalb = totalb + (2 * total_process) +(total_process + 1);
    for (int i = 0; i < totalb; i++)
    {
        printf("-");
    }
    printf("\n|");
    for (int i = 0; i < total_process; i++)
    {
        printf("P%d", (i + 1));
        for (int j = 0; j < p[i].bursttime; j++)
        {
            printf("-");
        }
        printf("|");
    }
    printf("\n");
    for (int i = 0; i < totalb; i++)
    {
        printf("-");
    }
    printf("\n0");
    for (int i = 0; i < total_process; i++)
    {
        for (int j = 0; j < p[i].bursttime + 1; j++)
        {
            printf(" ");
        }
        printf("%2d",p[i].turnouttime);

    }
}