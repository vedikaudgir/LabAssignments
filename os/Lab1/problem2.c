#include <bits/stdc++.h>
using namespace std;


struct process
{
    int pid;
    int burst;
    int remaining;
};


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
        cin >> p[i].burst;
        p[i].remaining = p[i].burst;
    }


    int completed = 0, time = 0;
    float waitingTime = 0, turnAroundTime = 0;


    while (completed != n)
    {
        int shortest = -1;
        int minTime = INT_MAX;


        for (int i = 0; i < n; i++)
        {
            if (p[i].remaining > 0 && p[i].remaining < minTime)
            {
                minTime = p[i].remaining;
                shortest = i;
            }
        }


        p[shortest].remaining--;
        time++;


        if (p[shortest].remaining == 0)
        {
            completed++;
            int finish = time;


            turnAroundTime += finish;
            waitingTime += finish - p[shortest].burst;
        }
    }


    cout << "\nAverage Waiting Time = " << waitingTime / n;
    cout << "\nAverage Turnaround Time = " << turnAroundTime / n;


    return 0;
}
