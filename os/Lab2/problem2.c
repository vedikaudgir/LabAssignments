#include <stdio.h>
#include <unistd.h>


int main ()
{
    fork ();
    fork ();
    fork ();
    printf ("OS Lab\n");
    return 0;
}