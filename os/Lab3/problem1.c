#include <stdio.h>
#include <math.h>

int main()
{
    int outer[4] = {0, 1, 2, 3};

    int page_table[4][4] = {
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
        {17, 18, 19, 20}
    };

    int logical;
    printf("Enter logical address (decimal): ");
    scanf("%d", &logical);

    int pageSize = 1024;
    int offsetBits = 10;

    int p1 = logical / (pageSize * 4);
    int p2 = (logical / pageSize) % 4;
    int offset = logical % pageSize;

    int frame = page_table[p1][p2];
    int physical = (frame * pageSize) + offset;

    printf("\np1 = %d", p1);
    printf("\np2 = %d", p2);
    printf("\noffset = %d", offset);
    printf("\nPhysical Address = %d\n", physical);

    printf("\nLogical (binary) = ");
    for (int i = 15; i >= 0; i--)
        printf("%d", (logical >> i) & 1);

    printf("\nPhysical (binary) = ");
    for (int i = 15; i >= 0; i--)
        printf("%d", (physical >> i) & 1);

    return 0;
}
