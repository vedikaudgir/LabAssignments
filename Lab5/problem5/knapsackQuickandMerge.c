// Fractional Knapsack using Merge Sort and Quick Sort
// Author - Vedika Udgir

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000
#define CAPACITY 5000

int value[MAX];
int weight[MAX];
float ratio[MAX];
float sackCapacity;
float totalProfit;

void generateRandomData(int n)
{
    for (int i = 0; i < n; i++)
    {
        value[i] = rand() % 1000 + 1;
        weight[i] = rand() % 100 + 1;
        ratio[i] = (float)value[i] / weight[i];
    }
}

void mergeSubarrays(int start, int mid, int end)
{
    int i, j, k;
    int n1 = mid - start + 1;
    int n2 = end - mid;

    float array1[n1], array2[n2];
    int array1value[n1], array2value[n2];
    int array1weight[n1], array2weight[n2];

    for (i = 0; i < n1; i++)
    {
        array1[i] = ratio[start + i];
        array1value[i] = value[start + i];
        array1weight[i] = weight[start + i];
    }
    for (j = 0; j < n2; j++)
    {
        array2[j] = ratio[mid + j + 1];
        array2value[j] = value[mid + j + 1];
        array2weight[j] = weight[mid + j + 1];
    }

    i = 0;
    j = 0;
    k = start;
    while (i < n1 && j < n2)
    {
        if (array1[i] > array2[j])
        {
            ratio[k] = array1[i];
            value[k] = array1value[i];
            weight[k] = array1weight[i];
            i++;
        }
        else
        {
            ratio[k] = array2[j];
            value[k] = array2value[j];
            weight[k] = array2weight[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        ratio[k] = array1[i];
        value[k] = array1value[i];
        weight[k] = array1weight[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        ratio[k] = array2[j];
        value[k] = array2value[j];
        weight[k] = array2weight[j];
        j++;
        k++;
    }
}

void mergeSort(int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(start, mid);
        mergeSort(mid + 1, end);
        mergeSubarrays(start, mid, end);
    }
}

int partition(int low, int high)
{
    float pivot = ratio[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (ratio[j] > pivot)
        {
            i++;
            float temp = ratio[i];
            ratio[i] = ratio[j];
            ratio[j] = temp;

            int t = value[i];
            value[i] = value[j];
            value[j] = t;

            t = weight[i];
            weight[i] = weight[j];
            weight[j] = t;
        }
    }
    float temp = ratio[i + 1];
    ratio[i + 1] = ratio[high];
    ratio[high] = temp;

    int t = value[i + 1];
    value[i + 1] = value[high];
    value[high] = t;

    t = weight[i + 1];
    weight[i + 1] = weight[high];
    weight[high] = t;

    return i + 1;
}

void quickSort(int low, int high)
{
    if (low < high)
    {
        int pi = partition(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

float knapsack(int n)
{
    float profit = 0.0;
    float capacity = CAPACITY;
    for (int i = 0; i < n; i++)
    {
        if (weight[i] <= capacity)
        {
            capacity -= weight[i];
            profit += value[i];
        }
        else
        {
            profit += value[i] * (capacity / weight[i]);
            break;
        }
    }
    return profit;
}

void main()
{
    int sizes[] = {1000, 10000, 100000, 1000000};
    for (int x = 0; x < 4; x++)
    {
        int n = sizes[x];
        printf("\nTest for %d elements", n);

        generateRandomData(n);

        int valueCopy[n], weightCopy[n];
        float ratioCopy[n];
        for (int i = 0; i < n; i++)
        {
            valueCopy[i] = value[i];
            weightCopy[i] = weight[i];
            ratioCopy[i] = ratio[i];
        }

        clock_t start = clock();
        mergeSort(0, n - 1);
        float profitM = knapsack(n);
        clock_t end = clock();
        float mergeTime = (float)(end - start) / CLOCKS_PER_SEC;

        for (int i = 0; i < n; i++)
        {
            value[i] = valueCopy[i];
            weight[i] = weightCopy[i];
            ratio[i] = ratioCopy[i];
        }

        start = clock();
        quickSort(0, n - 1);
        float profitQ = knapsack(n);
        end = clock();
        float quickTime = (float)(end - start) / CLOCKS_PER_SEC;

        printf("\nMerge Sort: Time = %.5f sec, Profit = %.2f", mergeTime, profitM);
        printf("\nQuick Sort: Time = %.5f sec, Profit = %.2f", quickTime, profitQ);
    }
}
