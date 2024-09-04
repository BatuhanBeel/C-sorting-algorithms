
#include <stdio.h>
#include <stdlib.h>

void merge(int array[], int start, int mid, int end) {
    int left_length = mid - start + 1;
    int right_length = end - mid;

    // Geçici diziler oluşturuyoruz.
    int *left_array = (int*)malloc(left_length * sizeof(int));
    int *right_array = (int*)malloc(right_length * sizeof(int));

    // Sol ve sağ yarıları geçici dizilere kopyalıyoruz.
    for (int i = 0; i < left_length; i++) {
        left_array[i] = array[start + i];
    }
    for (int j = 0; j < right_length; j++) {
        right_array[j] = array[mid + 1 + j];
    }

    int i = 0, j = 0, k = start;

    // İki yarıyı birleştiriyoruz.
    while (i < left_length && j < right_length) {
        if (left_array[i] <= right_array[j]) {
            array[k] = left_array[i];
            i++;
        } else {
            array[k] = right_array[j];
            j++;
        }
        k++;
    }

    // Kalan elemanları ekliyoruz.
    while (i < left_length) {
        array[k] = left_array[i];
        i++;
        k++;
    }

    while (j < right_length) {
        array[k] = right_array[j];
        j++;
        k++;
    }

    // Geçici dizileri serbest bırakıyoruz.
    free(left_array);
    free(right_array);
}

void merge_sort(int array[], int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;

        merge_sort(array, start, mid);
        merge_sort(array, mid + 1, end);
        merge(array, start, mid, end);
    }
}

void print_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int unsortedList[] = {2, 3, 1, 8, 15};
    int size = sizeof(unsortedList) / sizeof(unsortedList[0]);

    merge_sort(unsortedList, 0, size - 1);
    print_array(unsortedList, size);

    return 0;
}