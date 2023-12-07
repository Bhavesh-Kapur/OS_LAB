#include<stdio.h>
void insertionSort(int arr1[],int arr2[], int n) {
    int i, key1, j,key2,z;
    for (i = 1; i < n; i++) {
        key1 = arr1[i];
        key2 = arr2[i];
        j = i - 1;
        while (j >= 0 && arr1[j] > key1) {
            arr1[j + 1] = arr1[j];
             arr2[j + 1] = arr2[j];
            j = j - 1;
        }
        arr1[j + 1] = key1;
        arr2[j + 1] = key2;   
    }
}
void printArray(int arr1[],int arr2[], int n,int c[],int turn[],int wwt[]) {
    int i;
    printf("Processes       Arrival time       Burst Time        Completeion Time        Turn Around Time        Waitting time\n");
    for (i = 0; i < n; i++){
    printf("%d Process: \t     ",(i+1));
        printf("%d ", arr1[i]);
    printf("\t \t \t");
        printf("%d ", arr2[i]);
      printf("\t \t    ");
        printf("%d ", c[i]);
         printf("\t \t           ");
        printf("%d ", turn[i]);
         printf("\t \t \t ");
        printf("%d ", wwt[i]);
    printf("\n");
    }
}
/*int complettion(int arrr[],int n)
{
 int completion_time[n],i;
 completion_time[0]=0;
 for(i=0;i<n;i++)
 {
    completion_time[i]=completion_time[i]+ arrr[i];
 }
 return completion_time;
}*/
int main(){
    printf("Enter the number of processes");
    int p;
    scanf("%d",&p);
    int arra[p];
    int arrb[p];
    for(int i=0;i<p;i++)
    {
        printf("enter %d 's arrival time ",(i+1));
        scanf("%d",&arra[i]);
        printf("Enter %d 's burst time: ",(i+1));
        scanf("%d",&arrb[i]);
    } 
      insertionSort(arra,arrb,p);
int completion_time[p],i;
 completion_time[0]=arrb[0];
 for(i=1;i<p;i++)
 {
    completion_time[i]=completion_time[i-1]+ arrb[i];
 }
int tat[p];
 for(i=0;i<p;i++)
 {
 tat[i]= completion_time[i]-arra[i];
 }
int wt[p];
for(i=0;i<p;i++)
 {
 wt[i]= tat[i]-arrb[i];
 }
     printArray(arra,arrb,p,completion_time,tat,wt);
return 0;
}










    


    


   
    
