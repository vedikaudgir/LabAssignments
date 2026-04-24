#include <stdio.h>
#include <string.h>
#include <ctype.h>

char table[6][6] = {
    {'>', '<', '<', '<', '>', '>'},
    {'>', '>', '<', '<', '>', '>'},
    {'>', '>', ' ', ' ', '>', '>'},
    {'<', '<', '<', '<', '=', ' '},
    {'>', '>', ' ', ' ', '>', '>'},
    {'<', '<', '<', '<', ' ', '='}};

char symbol[6] = {'+', '*', 'i', '(', ')', '$'};
char stack[100];
int topPointer = -1;

int index(char c)
{
    for (int i = 0; i < 6; i++)
        if (symbol[i] == c)
            return i;
    return -1;
}
int isNonTerminal(char c) { return c == 'E' || c == 'T' || c == 'F'; }
void push(char c) { stack[++topPointer] = c; }
char pop() { return stack[topPointer--]; }

char topTerm()
{
    for (int i = topPointer; i >= 0; i--)
        if (!isNonTerminal(stack[i]))
            return stack[i];
    return '$';
}

int reduce()
{
    char a = topPointer >= 0 ? stack[topPointer] : 0;
    char b = topPointer >= 1 ? stack[topPointer - 1] : 0;
    char c = topPointer >= 2 ? stack[topPointer - 2] : 0;

    if (isNonTerminal(a) && b == '+' && isNonTerminal(c))
    {
        pop();
        pop();
        pop();
        push('E');
        return 1;
    }
    if (isNonTerminal(a) && b == '*' && isNonTerminal(c))
    {
        pop();
        pop();
        pop();
        push('T');
        return 1;
    }
    if (a == ')' && isNonTerminal(b) && c == '(')
    {
        pop();
        pop();
        pop();
        push('F');
        return 1;
    }

    if (a == 'i')
    {
        pop();
        push('F');
        return 1;
    }
    if (a == 'F')
    {
        pop();
        push('T');
        return 1;
    }
    if (a == 'T')
    {
        pop();
        push('E');
        return 1;
    }

    return 0;
}

int main()
{
    char input[100];
    int ip = 0;

    printf("Enter input string: ");
    scanf("%99s", input);
    strcat(input, "$");
    push('$');

    for (int steps = 0; steps < 1000; steps++)
    {

        char tt = topTerm();
        char in = input[ip];

        if (in == '$' && topPointer == 1 && stack[0] == '$' && isNonTerminal(stack[1]))
        {
            while (stack[1] != 'E')
            {
                if (stack[1] == 'F')
                {
                    pop();
                    push('T');
                }
                else if (stack[1] == 'T')
                {
                    pop();
                    push('E');
                }
                else
                    break;
            }
            if (stack[1] == 'E')
            {
                printf("Valid String\n");
                return 0;
            }
        }

        int r = index(tt);
        int col = index(in);

        if (r < 0 || col < 0 || table[r][col] == ' ')
        {
            printf("Invalid String\n");
            return 0;
        }

        char rel = table[r][col];

        if (rel == '<' || rel == '=')
        {
            push(in);
            ip++;
        }
        else
        {
            if (!reduce())
            {
                printf("Invalid String\n");
                return 0;
            }
        }
    }

    printf("Invalid String\n");
    return 0;
}