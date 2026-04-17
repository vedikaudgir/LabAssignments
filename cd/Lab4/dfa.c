#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool check_a_star(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != 'a')
            return false;
    }
    return true;
}

bool check_a_star_b_plus(char str[])
{
    int i = 0;

    while (str[i] == 'a')
        i++;

    int count_b = 0;

    while (str[i] == 'b')
    {
        count_b++;
        i++;
    }

    if (count_b >= 1 && str[i] == '\0')
        return true;

    return false;
}

bool check_abb(char str[])
{
    return strcmp(str, "abb") == 0;
}

int main()
{
    char str[100];

    printf("Enter string: ");
    scanf("%s", str);

    if (check_a_star(str))
        printf("Accepted under a*\n");
    else if (check_a_star_b_plus(str))
        printf("Accepted under a*b+\n");
    else if (check_abb(str))
        printf("Accepted under abb\n");
    else
        printf("Not Accepted\n");

    return 0;
}