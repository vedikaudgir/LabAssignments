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

int deleteMin(int arr[], int *n)
{
    if (*n <= 0)
        return -1;
    int minElement = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;
    heapify(arr, *n, 0);
    return minElement;
}

int main()
{
    int arr[100];
    int n = 20;
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    buildMinHeap(arr, n);
    int minElement = deleteMin(arr, &n);
    printf("%d\n", minElement);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
