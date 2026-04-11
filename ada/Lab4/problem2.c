// insertion on max heap
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

void insertIntoMaxHeap(int arr[], int n, int key)
{
    arr[n] = key;
    int i = n;
    while (i > 0 && arr[(i - 1) / 2] < arr[i])
    {
        int temp = arr[i];
        arr[i] = arr[(i - 1) / 2];
        arr[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

int main()
{
    int arr[100];
    int n = 15;
    for (int i = 0; i < 15; i++)
        scanf("%d", &arr[i]);
    buildMaxHeap(arr, 15);
    int key;
    printf("enter element to be inserted:");
    scanf("%d", &key);
    insertIntoMaxHeap(arr, n, key);
    n++;
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
