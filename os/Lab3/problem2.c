#include <stdio.h>

int main()
{
    unsigned int logical;
    printf("Enter logical address: ");
    scanf("%u", &logical);

    int offsetBits = 12;
    int p2Bits = 10;
    int p1Bits = 10;

    int offset = logical & ((1 << offsetBits) - 1);
    int p2 = (logical >> offsetBits) & ((1 << p2Bits) - 1);
    int p1 = logical >> (offsetBits + p2Bits);

    printf("\np1 = %d", p1);
    printf("\np2 = %d", p2);
    printf("\noffset = %d", offset);

    unsigned long frame = p1 * 1024 + p2;
    unsigned long physical = (frame << offsetBits) | offset;

    printf("\nPhysical Address = %lu\n", physical);

    printf("\nLogical (binary) = ");
    for (int i = 31; i >= 0; i--)
        printf("%d", (logical >> i) & 1);

    printf("\nPhysical (binary) = ");
    for (int i = 43; i >= 0; i--)
        printf("%lu", (physical >> i) & 1);

    return 0;
}
