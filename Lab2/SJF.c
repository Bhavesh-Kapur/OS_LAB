#include <stdio.h>

struct Process {
    int pid;
    int burst_time;
};

void swap(struct Process *xp, struct Process *yp) {
    struct Process temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sjf(struct Process processes[], int n) {
   
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].burst_time > processes[j + 1].burst_time) {
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }

    
    int waiting_time = 0;
    for (int i = 0; i < n; i++) {
        waiting_time += processes[i].burst_time;
        printf("Process %d: Waiting Time = %d, Turnaround Time = %d\n",
               processes[i].pid, waiting_time - processes[i].burst_time, waiting_time);
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].pid = i + 1;
    }

    sjf(processes, n);

    return 0;
}
