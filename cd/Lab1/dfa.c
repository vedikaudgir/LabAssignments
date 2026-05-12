#include <stdio.h>
#include <string.h>

//  DFA
int simulateDFA(char input[])
{
    int state = 0; // q0

    for (int i = 0; i < strlen(input); i++)
    {
        char ch = input[i];

        switch (state)
        {
        case 0:
            if (ch == '0')
                state = 1;
            else
                state = 0;
            break;

        case 1:
            if (ch == '0')
                state = 2;
            else
                state = 0;
            break;

        case 2:
            if (ch == '0')
                state = 3;
            else
                state = 0;
            break;

        case 3:
            state = 3; // stay in accepting state
            break;
        }
    }

    return (state == 3);
}

//  NFA
int simulateNFA(char input[])
{
    int current[4] = {1, 0, 0, 0}; // q0 active
    int next[4];

    for (int i = 0; i < strlen(input); i++)
    {
        char ch = input[i];

        for (int j = 0; j < 4; j++)
            next[j] = 0;

        if (ch == '0')
        {
            if (current[0])
            {
                next[0] = 1;
                next[1] = 1;
            }
            if (current[1])
                next[2] = 1;
            if (current[2])
                next[3] = 1;
            if (current[3])
                next[3] = 1;
        }
        else if (ch == '1')
        {
            if (current[0])
                next[0] = 1;
            if (current[3])
                next[3] = 1;
        }

        for (int j = 0; j < 4; j++)
            current[j] = next[j];
    }

    return current[3]; // accept if q3 active
}

int main()
{
    char input[100];

    printf("Enter binary string: ");
    scanf("%s", input);

    int dfaResult = simulateDFA(input);
    int nfaResult = simulateNFA(input);

    printf("\n- Results -\n");

    if (dfaResult)
        printf("DFA: ACCEPTED (contains 000)\n");
    else
        printf("DFA: REJECTED\n");

    if (nfaResult)
        printf("NFA: ACCEPTED (contains 000)\n");
    else
        printf("NFA: REJECTED\n");

    return 0;
}