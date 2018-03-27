#include<stdio.h>
#include<stdbool.h>
//average time

void AvgTime(int process[], int n, int brust[],int quant)
{
    int i,wt[n], temp[n], total_wt = 0, total_time= 0;
    WaitingTime(process, n,brust, wt, quant);
    TurnAroundTime(process, n, brust, wt, temp);
    printf("Processes :  Burst time :  Waiting time :   Turn around time : \n");

    for (i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_time = total_time + temp[i];
        printf(" i+1 \t\t  %d \t  %d \t\t %d\n",brust,wt[i],temp[i]);
    }
 
    printf("Average waiting time = %d",(float)total_wt / (float)n);
    printf("\n Average turn around time = %d",(float)total_time/(float)n);
}

//waiting time frome here

void WaitingTime(int process[], int n,int brust[], int wt[], int quan)
{
    int i,t,rem[n];
    t=0;
    for (i = 0 ; i < n ; i++)
        {
            rem[i] =  brust[i];
        }
    while (1)
    {
        bool flag= true;
        for (i = 0 ; i < n; i++)
        {
            if (rem[i] > 0)
            {
                flag = false; 
 
                if (rem[i] > quan)
                {
                    t += quan;
                    rem[i] -= quan;
                }
                else
                {
                    t = t + rem[i];
                    wt[i] = t - brust[i];
                    rem[i] = 0;
                }
            }
        }
        if (flag == true)
          break;
    }
}

//turn around time from here

void TurnAroundTime(int process[], int n,int brust[], int wt[], int temp[])
{
    int i;
    for (i = 0; i < n ; i++)
        temp[i] = brust[i] + wt[i];
}



int main()
{
    int process[] = { 1, 2, 3};
    int n = sizeof process / sizeof process[0];
    int burst_time[] = {10, 5, 8};
    int quantum = 2;
    AvgTime(process, n, burst_time, quantum);
    return 0;
}
