#include <stdio.h>


struct Process {
    int pid;        
    int burstTime;  
    int remainingTime; 
};

// Function to execute processes using Round Robin scheduling
void roundRobin(struct Process processes[], int n, int quantum) {
    int currentTime = 0; // Current time
    int completed = 0;   // Number of completed processes

    // Continue until all processes are completed
    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (processes[i].remainingTime > 0) {
                // Execute the process for the current quantum or its remaining time, whichever is smaller
                int executeTime = (processes[i].remainingTime < quantum) ? processes[i].remainingTime : quantum;
                processes[i].remainingTime -= executeTime;
                currentTime += executeTime;

                printf("Process %d is executed for %d units. Current time: %d\n", processes[i].pid, executeTime, currentTime);

                if (processes[i].remainingTime <= 0) {
                    completed++;
                }
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];
    int quantum;

    for (int i = 0; i < n; i++) {
        processes[i].pid = i;
        printf("Enter burst time for Process %d: ", i);
        scanf("%d", &processes[i].burstTime);
        processes[i].remainingTime = processes[i].burstTime;
    }

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    printf("\nRound Robin Scheduling:\n");
    roundRobin(processes, n, quantum);

    return 0;
}