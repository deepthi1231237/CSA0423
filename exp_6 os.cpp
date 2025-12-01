#include <stdio.h>

struct Process {
    int pid, bt, at, priority;
    int rt;   // remaining time
};

int main() {
    int n, completed = 0, time = 0, i, minP, totalWT = 0, totalTAT = 0;
    float avgWT, avgTAT;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for(i = 0; i < n; i++) {
        printf("\nProcess %d\n", i+1);
        printf("Enter arrival time: ");
        scanf("%d", &p[i].at);
        printf("Enter burst time: ");
        scanf("%d", &p[i].bt);
        printf("Enter priority (lower number = higher priority): ");
        scanf("%d", &p[i].priority);

        p[i].pid = i+1;
        p[i].rt = p[i].bt;
    }

    printf("\nGantt Chart (Process Execution Order):\n");

    while(completed != n) {
        minP = -1;

        for(i = 0; i < n; i++) {
            if(p[i].at <= time && p[i].rt > 0) {
                if(minP == -1 || p[i].priority < p[minP].priority)
                    minP = i;
            }
        }

        if(minP == -1) {
            time++;
            continue;
        }

        printf("P%d -> ", p[minP].pid);

        p[minP].rt--;
        time++;

        if(p[minP].rt == 0) {
            completed++;
            int tat = time - p[minP].at;  // Turnaround time
            int wt = tat - p[minP].bt;    // Waiting time

            totalWT += wt;
            totalTAT += tat;
        }
    }

    avgWT = (float)totalWT / n;
    avgTAT = (float)totalTAT / n;

    printf("\n\nAverage Waiting Time = %.2f", avgWT);
    printf("\nAverage Turnaround Time = %.2f\n", avgTAT);

    return 0;
}
10:19 am
Forwarded
#include <stdio.h>

struct Process {
    int pid, bt, at, wt, tat, finished;
};

int main() {
    int n, time = 0, completed = 0, i, shortest;
    float avgWT = 0, avgTAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("\nProcess %d\n", i + 1);
        printf("Enter Arrival Time: ");
        scanf("%d", &p[i].at);
        printf("Enter Burst Time: ");
        scanf("%d", &p[i].bt);

        p[i].finished = 0;
    }

    printf("\nExecution Order (Gantt Chart):\n");

    while (completed != n) {
        shortest = -1;

        for (i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].finished == 0) {
                if (shortest == -1 || p[i].bt < p[shortest].bt) {
                    shortest = i;
                }
            }
        }

        if (shortest == -1) {
            time++;
            continue;
        }

        printf("P%d -> ", p[shortest].pid);
        time += p[shortest].bt;
        p[shortest].tat = time - p[shortest].at;
        p[shortest].wt = p[shortest].tat - p[shortest].bt;
        p[shortest].finished = 1;
        completed++;
    }

    printf("\n\nProcess\tAT\tBT\tWT\tTAT\n");

    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", 
            p[i].pid, p[i].at, p[i].bt, p[i].wt, p[i].tat);

        avgWT += p[i].wt;
        avgTAT += p[i].tat;
    }

    avgWT /= n;
    avgTAT /= n;

    printf("\nAverage Waiting Time = %.2f", avgWT);
    printf("\nAverage Turnaround Time = %.2f\n", avgTAT);

    return 0;
}