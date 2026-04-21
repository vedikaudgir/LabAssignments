#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int pid = fork();

    if (pid == 0)
    {
        for (int i = 1; i <= 5; i++)
        {
            printf("Child: %d\n", i);
            sleep(1);
        }
    }
    else
    {
        wait(NULL);
        printf("Parent: Child completed\n");
    }

    return 0;
}
