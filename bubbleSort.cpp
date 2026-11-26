//
// Created by 55219 on 21/10/2026.
//

#include "bubbleSort.h"
#include <iostream>

/** O Bubble sort eh o algoritmo mais simples de ordenacao
 * Ele orderna fazendo multiplas ordenacoes, como uma bolha, por exemplo
 * Vai jogando a 'bolha' pro final do array de acordo com cada comparacao
 * Ou seja compara e depois troca
**/

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int *array, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

int main() {
    int array[8] = {8, 2, 6 , 3, 4, 5 , 1, 7};
    for (int i = 0; i < 8; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
    bubbleSort(array, 8);
    for (int i = 0; i < 8; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;

    return 0;
}