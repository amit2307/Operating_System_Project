#include<stdio.h>
#include<stdbool.h>
//average time

void AvgTime(int process[], int n, int brust[],int quant)
{
    int i,wt[n], temp[n], total_wt = 0, total_time= 0;
    int avg_wait,avg_turnaround;
    WaitingTime(process, n,brust, wt, quant);
    TurnAroundTime(process, n, brust, wt, temp);
    printf("Processes : Burst time :  Waiting time :   Turn around time : \n");

    for (i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_time = total_time + temp[i];
        printf("%d \t\t  %d \t \t %d \t\t\t%d\n",i+1,brust[i],wt[i],temp[i]);
    }

    // average query time and average waiting time
    avg_wait=total_wt/n;
    avg_turnaround=total_time/n;
    
    printf("\n Time he spend on handling query is : %d",avg_turnaround);
    printf("\n Average query time is : %d",avg_wait);
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
 
    int x;
    printf("Enter number of process you want to enter : ");
    scanf("%d",&x);
    int process[x],process1[x];
    int burst_time[x],burst_time1[x]; 
      
    //for students 
    printf("ENTER ARIVAL TIME OF STUDENTS : \n\n");
    for(int i=1;i<=x;i++)
    {
	printf("Enter arival time of student : %d\t",i);
	scanf("%d",&process[i]);
        printf("\n");
    }
    
    printf("ENTER BRUST TIME OF STUDENTS: \n\n");
    for(int i=1;i<=x;i++)
    {
       printf("Enter brust time of student : %d\t",i);
	scanf("%d",&burst_time[i]);
	printf("\n");
    }
    
    //for faculty
    printf("ENTER ARIVAL TIME OF FACULT: \n\n");
    for(int i=1;i<=x;i++)
    {
        printf("Enter arival time of faculty : %d\t",i);
	scanf("%d",&process1[i]);
        printf("\n");
    }

    int n = sizeof process / sizeof process[0];

   

    printf("ENTER BRUST TIME FOR FACULTY : \n\n");
    for(int i=1;i<=x;i++)
    {
        printf("Enter brust time of student : %d\t",i);
	scanf("%d",&burst_time1[i]);
        printf("\n");
    }
    printf("TIME QUANTUM USED IS 5 :\n");
    int quantum = 5;
    AvgTime(process, n, burst_time, quantum); 
    n = sizeof process1 / sizeof process1[0];
    printf("\n\n\n");
    AvgTime(process1, n ,burst_time1,quantum);
    return 0;
}
