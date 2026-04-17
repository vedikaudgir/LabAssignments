#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

int count = 0;
char first[10];
char follow[10];

char prod[10][10] = {
    "S=AA",
    "A=bB",
    "A=Cd",
    "B=aB",
    "B=e",
    "C=cC",
    "C=c"};

char terminals[] = {'a', 'b', 'c', 'd', '$'};
char table[10][10][10];

void findFirst(char x)
{
    int i;

    if (!(isupper(x)))
    {
        first[count++] = x;
        return;
    }

    for (i = 0; i < 7; i++)
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
                findFirst(prod[i][2]);
            }
        }
    }
}

void findFollow(char x)
{
    int i, j;

    if (prod[0][0] == x)
        follow[count++] = '$';

    for (i = 0; i < 7; i++)
    {
        for (j = 2; j < strlen(prod[i]); j++)
        {
            if (prod[i][j] == x)
            {
                if (prod[i][j + 1] != '\0')
                {
                    int tempCount = 0;
                    count = 0;

                    findFirst(prod[i][j + 1]);
                    tempCount = count;

                    for (int k = 0; k < tempCount; k++)
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


int getTerminalIndex(char t)
{
    for (int i = 0; i < 5; i++)
        if (terminals[i] == t)
            return i;
    return -1;
}

int getNonTerminalIndex(char nt)
{
    return nt - 'A';
}

void buildParsingTable()
{
    for (int i = 0; i < 7; i++)
    {
        char lhs = prod[i][0];
        char firstSet[10];
        int firstCount = 0;

        count = 0;
        findFirst(prod[i][2]);
        firstCount = count;

        for (int j = 0; j < firstCount; j++)
        {
            if (first[j] != 'e')
            {
                int row = getNonTerminalIndex(lhs);
                int col = getTerminalIndex(first[j]);

                if (col != -1)
                    strcpy(table[row][col], prod[i]);
            }
            else
            {
                count = 0;
                findFollow(lhs);

                for (int k = 0; k < count; k++)
                {
                    int row = getNonTerminalIndex(lhs);
                    int col = getTerminalIndex(follow[k]);

                    if (col != -1)
                        strcpy(table[row][col], prod[i]);
                }
            }
        }
    }
}

void printTable()
{
    printf("\nParsing Table:\n");

    for (int i = 0; i < 7; i++)
    {
        char nt = prod[i][0];
        int row = getNonTerminalIndex(nt);

        for (int j = 0; j < 5; j++)
        {
            if (strlen(table[row][j]) > 0)
            {
                printf("M[%c, %c] = %s\n", nt, terminals[j], table[row][j]);
            }
        }
    }
}

int main()
{
    int i, j;

    printf("FIRST Sets:\n");
    
    for (i = 0; i < 4; i++) // S, A, B, C
    {
        char c = prod[i][0];
        count = 0;

        findFirst(c);

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

    for (i = 0; i < 4; i++)
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

    buildParsingTable();
    printTable();

    return 0;
}
    // // 🔥 REMOVE DIRECT LEFT RECURSION
    // void removeDirectLeftRecursion()
    // {
    
    //     char newProductions[20][10];
    //     int newCount = 0;
    
    //     for (int i = 0; i < ntCount; i++)
    //     {
    
    //         char A = nonTerminals[i];
    
    //         char alpha[10][10]; // recursive
    //         char beta[10][10];  // non-recursive
    
    //         int aCount = 0, bCount = 0;
    
    //         // Separate productions
    //         for (int j = 0; j < n; j++)
    //         {
    
    //             if (productions[j][0] == A)
    //             {
    
    //                 if (productions[j][2] == A)
    //                 {
    //                     // A → Aα
    //                     strcpy(alpha[aCount++], &productions[j][3]);
    //                 }
    //                 else
    //                 {
    //                     // A → β
    //                     strcpy(beta[bCount++], &productions[j][2]);
    //                 }
    //             }
    //         }
    
    //         // If no left recursion
    //         if (aCount == 0)
    //         {
    //             for (int j = 0; j < n; j++)
    //             {
    //                 if (productions[j][0] == A)
    //                 {
    //                     strcpy(newProductions[newCount++], productions[j]);
    //                 }
    //             }
    //         }
    //         else
    //         {
    //             // Create new non-terminal
    //             char newNT = 'Z' - i;
    //             nonTerminals[ntCount++] = newNT;
    
    //             // A → βA'
    //             for (int j = 0; j < bCount; j++)
    //             {
    //                 sprintf(newProductions[newCount++],
    //                         "%c=%s%c", A, beta[j], newNT);
    //             }
    
    //             // A' → αA'
    //             for (int j = 0; j < aCount; j++)
    //             {
    //                 sprintf(newProductions[newCount++],
    //                         "%c=%s%c", newNT, alpha[j], newNT);
    //             }
    
    //             // A' → ε
    //             sprintf(newProductions[newCount++],
    //                     "%c=#", newNT);
    //         }
    //     }
    
    //     // Copy back
    //     n = newCount;
    //     for (int i = 0; i < n; i++)
    //     {
    //         strcpy(productions[i], newProductions[i]);
    //     }
    // }