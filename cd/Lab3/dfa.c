#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

char *keywords[] = {
    "int", "float", "char", "double", "if", "else",
    "while", "for", "return", "void", "break", "continue"};

int keywordCount = 12;

bool isKeyword(char str[])
{
    for (int i = 0; i < keywordCount; i++)
    {
        if (strcmp(str, keywords[i]) == 0)
            return true;
    }
    return false;
}

bool isIdentifier(char str[])
{
    if (!(isalpha(str[0]) || str[0] == '_'))
        return false;

    for (int i = 1; str[i] != '\0'; i++)
    {
        if (!(isalnum(str[i]) || str[i] == '_'))
            return false;
    }

    return true;
}

bool isNumber(char str[])
{
    int i = 0, hasDot = 0;

    if (str[i] == '+' || str[i] == '-')
        i++;

    for (; str[i] != '\0'; i++)
    {
        if (str[i] == '.')
        {
            if (hasDot)
                return false;
            hasDot = 1;
        }
        else if (!isdigit(str[i]))
            return false;
    }

    return true;
}

bool isComment(char str[])
{
    int len = strlen(str);

    if (len >= 2 && str[0] == '/' && str[1] == '/')
        return true;

    if (len >= 4 && str[0] == '/' && str[1] == '*' &&
        str[len - 2] == '*' && str[len - 1] == '/')
        return true;

    return false;
}

int main()
{
    char line[200];
    char token[50];
    int i = 0, j = 0;

    printf("Enter line: ");
    fgets(line, sizeof(line), stdin);

    if (isComment(line))
    {
        printf("It is a comment\n");
        return 0;
    }

    while (line[i] != '\0')
    {
        if (isspace(line[i]) || line[i] == ',' || line[i] == ';')
        {
            if (j > 0)
            {
                token[j] = '\0';

                if (isKeyword(token))
                    printf("%s : Keyword\n", token);
                else if (isNumber(token))
                    printf("%s : Constant\n", token);
                else if (isIdentifier(token))
                    printf("%s : Identifier\n", token);
                else
                    printf("%s : Invalid\n", token);

                j = 0;
            }
            i++;
        }
        else
        {
            token[j++] = line[i++];
        }
    }

    if (j > 0)
    {
        token[j] = '\0';

        if (isKeyword(token))
            printf("%s : Keyword\n", token);
        else if (isNumber(token))
            printf("%s : Constant\n", token);
        else if (isIdentifier(token))
            printf("%s : Identifier\n", token);
        else
            printf("%s : Invalid\n", token);
    }

    return 0;
}