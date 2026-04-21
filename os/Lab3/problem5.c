#include <stdio.h>
#include <unistd.h>

int main()
{
    for (int i = 0; i < 3; i++)
    {
        int pid = fork();

        if (pid == 0)
        {
            printf("Child %d PID = %d\n", i + 1, getpid());
            return 0;
        }
    }

    return 0;
}
