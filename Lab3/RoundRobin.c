#include <stdio.h>

void calculateWaitingTime(int n, int burst_time[], int time_slice, int waiting_time[]) {
    int remaining_burst_time[n];
    for (int i = 0; i < n; i++) {
        remaining_burst_time[i] = burst_time[i];
    }

    int total_time = 0;
    int flag = 1;

    while (1) {
        int done = 1;

        for (int i = 0; i < n; i++) {
            if (remaining_burst_time[i] > 0) {
                done = 0;

                if (remaining_burst_time[i] > time_slice) {
                    total_time += time_slice;
                    remaining_burst_time[i] -= time_slice;
                    printf("|P%d(%d)", i + 1, total_time);
                } else {
                    total_time += remaining_burst_time[i];
                    waiting_time[i] = total_time - burst_time[i];
                    remaining_burst_time[i] = 0;
                    printf("|P%d(%d)", i + 1, total_time);
                }
            }
        }

        if (done == 1)
            break;
    }
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int burst_time[n];
    int waiting_time[n];

    printf("Enter burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Burst time for Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    int time_slice;
    printf("Enter the time slice: ");
    scanf("%d", &time_slice);

    // Calculate waiting times and display Gantt chart
    calculateWaitingTime(n, burst_time, time_slice, waiting_time);

    // Display the process details and waiting time
    printf("\n\nProcess\tBurst Time\tWaiting Time\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\n", i + 1, burst_time[i], waiting_time[i]);
    }

    return 0;
}