#include <stdio.h>
#include <unistd.h>

int main()
{
    int pid = fork();

    if (pid == 0)
    {
        printf("Child if wala PID = %d\n", getpid());
        printf("Parent if wala PID = %d\n", getppid());
    }
    else
    {
        printf("Parent else PID = %d\n", getpid());
        printf("Child else PID = %d\n", pid);
    }

    return 0;
}
