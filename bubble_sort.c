#include <stdio.h>
#include <string.h>
#include <stdbool.h> 

void bubbleSort(int arr[], int length);
void printArray(int arr[], int length);

int main(void){
    int unsortedArray[] = {7,15,3,6,1,14,23,2,15,4,4};
    int length = sizeof(unsortedArray) / sizeof(unsortedArray[0]);
 
    bubbleSort(unsortedArray, length);
    printArray(unsortedArray, length);
}

void bubbleSort(int arr[], int length)
{
    for(int i = 0; i < length-1; i++){
        bool isChanging = false;
        for(int j = 0; j < length-1; j++){
            int value1 = arr[j];
            int value2 = arr[j+1];
            if(arr[j+1] < arr[j]){
                isChanging = true;
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
        if (!isChanging) { // More readable boolean check
            printf("Array is already sorted.");
            break;
        }
    }
}

/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}



   