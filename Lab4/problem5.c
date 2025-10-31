#include <stdio.h>

void heapify(int arr[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    if (right < n && arr[right] < arr[smallest])
        smallest = right;
    if (smallest != i)
    {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        heapify(arr, n, smallest);
    }
}

void buildMinHeap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

int main()
{
    int arr[15];
    for (int i = 0; i < 15; i++)
        scanf("%d", &arr[i]);
    buildMinHeap(arr, 15);
    for (int i = 0; i < 15; i++)
        printf("%d ", arr[i]);
    return 0;
}
