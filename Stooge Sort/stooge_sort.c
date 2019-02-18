#include <stdio.h>
#include <stdlib.h>
// Prints the array with size, size
void printArray(const int arr[], const int size);
// Swaps the values pointed by p and k
void swap(int* p, int* k);
// Recursive function, low and high are array indices
void stoogeSort(int arr[], const int low, const int high);

int main(void)
{
    int size;

    printf("Enter the array size: ");
    scanf("%d",&size);

    int* arr = (int*)malloc(size * sizeof(int));

    printf("Enter %d elements: ",size);
    for(int count = 0; count < size; count++)
    {
        scanf("%d",&arr[count]);
    }
    stoogeSort(arr,0,size-1);
    printArray(arr,size);
    return 0;
}

void printArray(const int arr[], const int size)
{
    printf("Sorted Array: \n");
    for(int count = 0; count < size; count++)
    {
        printf("%d ",arr[count]);
    }
}

void swap(int* p, int* k)
{
    int temp = *p;
    *p = *k;
    *k = temp;
}

void stoogeSort(int arr[], const int low, const int high)
{
    int temp;

    if(arr[low] > arr[high])
    {
        swap(&arr[low],&arr[high]);
    }
    if(low + 1 >= high)
        return;

    temp = (int)(high - low + 1) / 3;

    stoogeSort(arr,low,high-temp);
    stoogeSort(arr,low+temp,high);
    stoogeSort(arr,low,high-temp);
}
