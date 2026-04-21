#include <bits/stdc++.h>
using namespace std;


struct job
{
    int jobID;
    int order;
    int duration;
};


bool compareJobs(const job &a, const job &b)
{
    return a.order < b.order;
}


int main()
{
    int n = 0;
    cout << "Enter no of jobs - ";
    cin >> n;


    struct job jobs[n];
    for (int i = 0; i < n; i++)
    {
        cout << "\n Enter the job ID - ";
        cin >> jobs[i].jobID;
        cout << "\n Enter the order- ";
        cin >> jobs[i].order;
        cout << "\n Enter the job duration - ";
        cin >> jobs[i].duration;
    }


    sort(jobs, jobs + n, compareJobs);


    int time = 0;
    int waitingTime = 0;
    int turnAroundTime = 0;


    for (int i = 0; i < n; i++)
    {
        cout << "CPU time = " << time << endl;
        cout << "JobID executed = " << jobs[i].jobID << endl;
        waitingTime += time;
        time += jobs[i].duration;
        turnAroundTime += (waitingTime + jobs[i].duration);
    }


    turnAroundTime /= n;
    waitingTime /= n;
    cout << "\n\n Average Waiting Time = " << waitingTime;
    cout << "\n\n Average Turnaround Time = " << turnAroundTime;
    return 0;
}
