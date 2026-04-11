#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 256

struct node
{
    char character;
    int frequency;
    struct node *left, *right;
};

struct node *createNode(char character, int frequency)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->character = character;
    temp->frequency = frequency;
    temp->left = temp->right = NULL;
    return temp;
}

void swapNodes(struct node **a, struct node **b)
{
    struct node *temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct node *array[], int size, int index)
{
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < size && array[left]->frequency < array[smallest]->frequency)
        smallest = left;
    if (right < size && array[right]->frequency < array[smallest]->frequency)
        smallest = right;
    if (smallest != index)
    {
        swapNodes(&array[index], &array[smallest]);
        heapify(array, size, smallest);
    }
}

struct node *extractMin(struct node *array[], int *size)
{
    struct node *minNode = array[0];
    array[0] = array[*size - 1];
    (*size)--;
    heapify(array, *size, 0);
    return minNode;
}

void insertHeap(struct node *array[], int *size, struct node *newNode)
{
    int index = (*size)++;
    array[index] = newNode;
    while (index && array[(index - 1) / 2]->frequency > array[index]->frequency)
    {
        swapNodes(&array[index], &array[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

struct node *buildHuffmanTree(int frequency[])
{
    struct node *array[MAX];
    int size = 0;
    for (int i = 0; i < MAX; i++)
        if (frequency[i])
            array[size++] = createNode((char)i, frequency[i]);
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, i);
    while (size > 1)
    {
        struct node *leftNode = extractMin(array, &size);
        struct node *rightNode = extractMin(array, &size);
        struct node *topNode = createNode('$', leftNode->frequency + rightNode->frequency);
        topNode->left = leftNode;
        topNode->right = rightNode;
        insertHeap(array, &size, topNode);
    }
    return array[0];
}

void printHuffmanCodes(struct node *root, int codeArray[], int codeLength)
{
    if (root->left)
    {
        codeArray[codeLength] = 0;
        printHuffmanCodes(root->left, codeArray, codeLength + 1);
    }
    if (root->right)
    {
        codeArray[codeLength] = 1;
        printHuffmanCodes(root->right, codeArray, codeLength + 1);
    }
    if (!root->left && !root->right)
    {
        printf("%c : ", root->character);
        for (int i = 0; i < codeLength; i++)
            printf("%d", codeArray[i]);
        printf("\n");
    }
}

void main()
{
    char inputString[250];
    int frequency[MAX] = {0};
    printf("Enter the string to encode: ");
    gets(inputString);
    for (int i = 0; i < strlen(inputString); i++)
        frequency[(unsigned char)inputString[i]]++;
    struct node *root = buildHuffmanTree(frequency);
    int codeArray[MAX], codeLength = 0;
    printf("\nHuffman Codes:\n");
    printHuffmanCodes(root, codeArray, codeLength);
}
