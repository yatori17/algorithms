//
// Created by 55219 on 21/10/2026.
//

#include "quickSort.h"
#include "iostream"

/**
 *
 * O quick sort tem tres processos basicos (Divisao e conquista)
 * 1. Escolha de Pivot: Selecionar um elemnto do array. A escolha do pivot pode variar
 * (primeiro elemento, último elemento, elemento aleatório ou mediana)
 * 2. Particiona o Array: A gente deve rearranjar o array em torno do pivot e depois de partiiconar
 * todos os elementos que sao menores que o pivot tem que ficar do lado direito enquanto
 * todos os elementos maiores que o pivot vao para o lado direito
 * 3. Chamadas recursivas: Recursivametente temos que aplicar o msm processo para os dois subparticionados arrays
 * 3.1. Caso base de quaqleru recursao: A recursao para quando so tem um elemento do lado esquedo do subarray
 * Pq um único elemento ja esta ordenado
 */

int partition(int *array, int low, int high) {
    int pivot = array[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    return i + 1;
}

void quickSort(int *array, int low, int high) {
    if (low < high) {
        int pivot = partition(array, low, high);
        quickSort(array, low, pivot - 1);
        quickSort(array, pivot + 1, high);
    }
}
int main() {
    int array[8] = {8, 2, 5, 3 , 4, 7, 6, 1};

    quickSort(array, 0, 7);
    for (int i = 0; i < 8; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;

    return 0;
}