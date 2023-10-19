#include<stdio.h>

void swap(int *x, int *y){       //function to swap the two processes based upon the arrival time 
    int temp = *x;
    *x=*y; 
    *y=temp;
}

void display(int BT[], int AT[],int n,int wt[],int ct[],int tat[],float avgtat,float avgwt) {
    printf("Process\tBurst Time\tArrival Time\tCmpletion time\tTurn Around Time\t Waiting Time \n");
    for (int i = 0; i < n; i++) {
        printf("%d\t  %d\t\t     %d\t\t\t%d\t\t%d\t\t\t%d\n", i + 1, BT[i], AT[i],ct[i],tat[i],wt[i]);
    }
}

void sjf(int bt[], int at[], int n) {
    int wt[n], tat[n], ct[n];
    float avg_wt = 0, avg_tat = 0;

    ct[0] = at[0] + bt[0];
    for (int i = 1; i < n; i++) {
        ct[i] = ct[i - 1] + bt[i];
    }

    for (int i = 0; i < n; i++) {
        wt[i] = ct[i] - at[i] - bt[i];
    }

    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        avg_wt =avg_wt+ wt[i];
        avg_tat =avg_tat+ tat[i];
    }

    avg_wt =avg_wt/n;
    avg_tat =avg_tat/n;

display(bt,at,n,wt,tat,ct,avg_tat,avg_wt);
    
}

int main(){                                 //main method/body
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);

    int BT[n],AT[n];
    for (int i = 0; i < n; i++)                        //input values for the array BT,AT
    {
        printf("Enter the Arrival time for %d :",(i+1));
        scanf("%d",&AT[i]);
        printf("Enter the Burst time for %d :",(i+1));
        scanf("%d",&BT[i]);
    }
    

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (AT[j] > AT[j + 1]) {
                swap(&AT[j], &AT[j + 1]);
                swap(&BT[j], &BT[j + 1]);
        }
        
    }   
}
sjf(BT,AT,n);
}