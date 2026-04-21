#include <stdio.h>


int main()
{
    int n, m;


    printf("Enter number of processes: ");
    scanf("%d", &n);


    printf("Enter number of resources: ");
    scanf("%d", &m);


    int alloc[n][m], max[n][m], need[n][m];
    int avail[m], finish[n], safeSeq[n];


    printf("\nEnter Allocation Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);


    printf("\nEnter Max Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &max[i][j]);


    printf("\nEnter Available Resources:\n");
    for (int i = 0; i < m; i++)
        scanf("%d", &avail[i]);


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }


    for (int i = 0; i < n; i++)
        finish[i] = 0;


    int count = 0;


    while (count < n)
    {
        int found = 0;


        for (int i = 0; i < n; i++)
        {
            if (finish[i] == 0)
            {
                int canExecute = 1;


                for (int j = 0; j < m; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        canExecute = 0;
                        break;
                    }
                }


                if (canExecute)
                {
                    for (int j = 0; j < m; j++)
                        avail[j] += alloc[i][j];


                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }


        if (!found)
        {
            printf("\nSystem is NOT in safe state\n");
            return 0;
        }
    }


    printf("\nSystem is in SAFE STATE\nSafe sequence: ");
    for (int i = 0; i < n; i++)
        printf("P%d ", safeSeq[i]);


    printf("\n");


    return 0;
}
