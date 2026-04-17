#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

int count = 0;
char first[10];
char follow[10];

char prod[10][10] = {
    "E=TX",
    "X=+TX",
    "X=e",
    "T=FY",
    "Y=*FY",
    "Y=e",
    "F=(E)",
    "F=i"};

void findFirst(char x, int a, int b)
{
    int i;

    if (!(isupper(x)))
    {
        first[count++] = x;
        return;
    }

    for (i = 0; i < 8; i++)
    {
        if (prod[i][0] == x)
        {
            if (prod[i][2] == 'e')
            {
                first[count++] = 'e';
            }
            else if (!isupper(prod[i][2]))
            {
                first[count++] = prod[i][2];
            }
            else
            {
                findFirst(prod[i][2], i, 3);
            }
        }
    }
}

void findFollow(char x)
{
    int i, j;

    if (prod[0][0] == x)
        follow[count++] = '$';

    for (i = 0; i < 8; i++)
    {
        for (j = 2; j < strlen(prod[i]); j++)
        {
            if (prod[i][j] == x)
            {
                if (prod[i][j + 1] != '\0')
                {
                    int firstCount = 0;
                    count = 0;

                    findFirst(prod[i][j + 1], i, j + 2);
                    firstCount = count;

                    for (int k = 0; k < firstCount; k++)
                    {
                        if (first[k] != 'e')
                            follow[count++] = first[k];
                    }
                }

                if (prod[i][j + 1] == '\0' && x != prod[i][0])
                {
                    findFollow(prod[i][0]);
                }
            }
        }
    }
}

int main()
{
    int i, j;

    printf("FIRST Sets:\n");

    for (i = 0; i < 5; i++)
    {
        char c = prod[i][0];
        count = 0;

        findFirst(c, 0, 0);

        printf("FIRST(%c) = { ", c);

        for (j = 0; j < count; j++)
        {
            printf("%c", first[j]);
            if (j != count - 1)
                printf(", ");
        }

        printf(" }\n");
    }

    printf("\nFOLLOW Sets:\n");

    for (i = 0; i < 5; i++)
    {
        char c = prod[i][0];
        count = 0;

        findFollow(c);

        printf("FOLLOW(%c) = { ", c);

        for (j = 0; j < count; j++)
        {
            printf("%c", follow[j]);
            if (j != count - 1)
                printf(", ");
        }

        printf(" }\n");
    }

    return 0;
}