#include <bits/stdc++.h>
using namespace std;


struct process
{
    int pid;
    int duration;
};


bool compareProcess(const process &a, const process &b)
{
    return a.duration < b.duration;
}


int main()
{
    int n;
    cout << "Enter no of processes - ";
    cin >> n;


    process p[n];


    for (int i = 0; i < n; i++)
    {
        cout << "\n Enter process ID - ";
        cin >> p[i].pid;
        cout << " Enter burst time - ";
        cin >> p[i].duration;
    }


    sort(p, p + n, compareProcess);


    int time = 0;
    float waitingTime = 0;
    float turnAroundTime = 0;


    for (int i = 0; i < n; i++)
    {
        cout << "\nCPU time = " << time << endl;
        cout << "Process executed = " << p[i].pid << endl;


        waitingTime += time;
        turnAroundTime += (time + p[i].duration);


        time += p[i].duration;
    }


    cout << "\nAverage Waiting Time = " << waitingTime / n;
    cout << "\nAverage Turnaround Time = " << turnAroundTime / n;


    return 0;
}
