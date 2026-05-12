#include<stdio.h>

struct process
{
    int pid, at , bt, pri ;
    int ct,tat,wt;
    int completed;
};

int main()
{
    struct process p[5]=
    {
        {1,0,5,3,0,0,0,0},
        {2,1,3,1,0,0,0,0},
        {3,2,4,4,0,0,0,0},
        {4,3,2,2,0,0,0,0},
        {5,4,6,5,0,0,0,0}
    };

    int remaining_bt[5];

    for(int i=0;i<5;i++)
    {
        remaining_bt[i]=p[i].bt;
    }



    int completed=0,time = 0;

    while (completed<5)
    {
        int idx = -1;
        int min_priority = 9999;

        for (int i=0; i<5; i++)
        {
            if (p[i].at<=time && p[i].completed==0)
            {
                if(p[i].pri < min_priority)
                {
                    min_priority = p[i].pri;
                    idx = i;
                }
            }
        }
       
        printf("| P%d ", p[idx].pid);

            remaining_bt[idx]--;
            time++;

            if(remaining_bt[idx] == 0)
            {
                p[idx].ct=time;
                p[idx].tat=p[idx].ct-p[idx].at;
                p[idx].wt=p[idx].tat-p[idx].bt;
                p[idx].completed = 1;
                completed++;
            }
       
    }


    int total_tat=0,total_wt=0;

    for (int i=0; i<5; i++) {
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
            p[i].pid, p[i].at, p[i].bt, p[i].pri,
            p[i].ct, p[i].tat, p[i].wt);

        total_tat += p[i].tat;
        total_wt += p[i].wt;
    }

    printf("average turn around time is : %d\n",total_tat/4);
    printf("average waiting time is : %d \n",total_wt/4);

}
