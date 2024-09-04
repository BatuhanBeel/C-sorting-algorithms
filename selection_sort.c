#include <stdio.h>
#include <string.h>

void insertionSort(int arr[], int length);
void printArray(int arr[], int length);

int main(void){
    int unsortedArray[] = {7,15,3,2,18,12,30,20,4,1};
    int length = sizeof(unsortedArray) / sizeof(unsortedArray[0]);
 
    insertionSort(unsortedArray, length);
    printArray(unsortedArray, length);
}

void insertionSort(int arr[], int length)
{
   for(int i = 0; i < length-1; i++){
        int smallestValue = arr[i];
        int smallestValueIndex = i;
        for (int j=i+1; j < length; j++)
        {
            if (arr[j] < smallestValue)
            {
                smallestValue = arr[j];
                smallestValueIndex = j;
            }
        }
        arr[smallestValueIndex] = arr[i];
        arr[i] = smallestValue;
    }
}

/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}
