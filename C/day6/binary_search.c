#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sortArray(), printArray(), generateArray(); // using const int arr[] to avoid accidently change the array
int binarySearch();

void main()
{
    int arraySize, searchKey, result;
    printf("How many number you want: ");
    scanf("%d", &arraySize);
    int array[arraySize];

    generateArray(array, arraySize);
    sortArray(array, arraySize);
    printArray(array, arraySize);

    printf("\nInput your seeking number (0 to 100000): ");
    scanf("%d", &searchKey);
    result = binarySearch(array, arraySize, searchKey, 0); // return the position of search key
    if (result != -1)
    {
        printf("%d place in %d position", searchKey, result + 1); // up 1 for human readable
    }
    else
    {
        printf("%d dont find in array", searchKey);
    }
}

int binarySearch(const int arr[], int arraySize, int searchKey, int low)
{
    int high = arraySize, middle = 0;
    // using recusion
    // if (low > high) // no result
    // {
    //     return -1;
    // }
    // middle = (low + high) / 2;
    // if (searchKey == arr[middle]) // base case
    // {
    //     return middle;
    // }
    // else if (searchKey < arr[middle])
    // {
    //     binarySearch(arr, middle - 1, searchKey, low);
    // }
    // else if (searchKey > arr[middle])
    // {
    //     binarySearch(arr, high, searchKey, middle - 1);
    // }

    // using while loop (is while loop better optimization than recursion?)
    while (low <= high)
    {
        middle = (low + high) / 2;
        if (searchKey == arr[middle])
        {
            return middle;
        }
        else if (searchKey < arr[middle])
        {
            high = middle - 1;
        }
        else if (searchKey > arr[middle])
        {
            low = middle + 1;
        }
    }
    return -1; // no result
}

void sortArray(int arr[], int arraySize)
{
    puts("Sorting array...");
    int temp;
    for (int i = 0; i < arraySize; i++)
    {
        for (int x = 0; x < i + 1; x++)
        {
            if (arr[i] < arr[x])
            {
                temp = arr[i];
                arr[i] = arr[x];
                arr[x] = temp;
            }
        }
    }
}

void generateArray(int arr[], int arraySize)
{
    puts("Generating array...");
    srand(time(NULL)); // setting seed for random
    for (int i = 0; i < arraySize; i++)
    {
        arr[i] = 0 + rand() % 100000; // random number in 0 to 100
    }
}

void printArray(const int arr[], int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        if (i % 20 == 0 && i != 0)
        {
            printf("\n");
        }
        printf("%d\t", arr[i]);
    }
}