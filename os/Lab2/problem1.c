#include <stdio.h>
#include <unistd.h>

int main ()
{
if (fork () == 0)
{
    fork ();
    printf("A\n");
}
printf("B\n");
return 0;
}