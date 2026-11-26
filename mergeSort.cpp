//
// Created by 55219 on 21/10/2026.
//

#include "mergeSort.h"
#include "iostream"

void merge(int array[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int* leftArray = new int[n1];
    int* rightArray = new int[n2];
    for(int i = 0; i < n1; i++) {
        leftArray[i] = array[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArray[j] = array[middle + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        } else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = leftArray[i];
        i++;
        k++;
    }
    while (j < n2) {
        array[k] = rightArray[j];
        j++;
        k++;
    }

    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(int array[], int left, int right) {
    if (left >= right ) {
        return;
    }
    int middle = (left + right) / 2;
    mergeSort(array, left, middle); // left array
    mergeSort(array, middle + 1, right); // right array
    merge(array, left, middle, right);
}

int main() {
    int array[8] = {8, 2, 5, 3 , 4, 7, 6, 1};

    mergeSort(array, 0, 7);
    for (int i = 0; i < 8; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;

    return 0;
}