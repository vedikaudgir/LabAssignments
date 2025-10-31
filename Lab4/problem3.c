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

void incrementElement(int arr[], int index, int incrementVal)
{
    int key = arr[index] + incrementVal;
    if (key < arr[index])
        return;
    arr[index] = key;
    while (index > 0 && arr[(index - 1) / 2] < arr[index])
    {
        int temp = arr[(index - 1) / 2];
        arr[(index - 1) / 2] = arr[index];
        arr[index] = temp;
        index = (index - 1) / 2;
    }
}

void deleteRoot(int arr[], int *n)
{
    if (*n <= 0)
        return;
    arr[0] = arr[*n - 1];
    (*n)--;
    heapify(arr, *n, 0);
}

void findMax(int arr[], int n)
{
    if (n <= 0)
        return;
    printf("maximum element: %d at index 0\n", arr[0]);
}

void findMin(int arr[], int n)
{
    if (n <= 0)
        return;
    int min = arr[n / 2], index = n / 2;
    for (int i = n / 2 + 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            index = i;
        }
    }
    printf("minimum element: %d at index %d\n", min, index);
}

int main()
{
    int arr[100];
    int n = 25;
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    buildMaxHeap(arr, n);
    char ch;
    scanf(" %c", &ch);
    switch (ch)
    {
    case 'a':
    case 'A':
        incrementElement(arr, 8, 29);
        break;
    case 'b':
    case 'B':
        incrementElement(arr, 10, 45);
        break;
    case 'c':
    case 'C':
        deleteRoot(arr, &n);
        break;
    case 'd':
    case 'D':
        findMax(arr, n);
        break;
    case 'e':
    case 'E':
        findMin(arr, n);
        break;
    }
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
