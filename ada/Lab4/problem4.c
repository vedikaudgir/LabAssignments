#include <stdio.h>

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

int deleteMax(int arr[], int *n)
{
    if (*n <= 0)
        return -1;
    int maxElement = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;
    heapify(arr, *n, 0);
    return maxElement;
}

int main()
{
    int arr[100];
    int n = 20;
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    buildMaxHeap(arr, n);
    int maxElement = deleteMax(arr, &n);
    printf("%d\n", maxElement);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
