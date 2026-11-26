//
// Created by 55219 on 21/10/2026.
//

#include "insertionSort.h"
#include "iostream"


/**
 *Insertion Sort (Ordenação por inserção)
 * É um algoritmo de ordenacao simples que funciona inserindo, iterativamtnete cada eleemente
 * de uma lista nao ordenada em sua posicao correta dentro de uma parte da lista que já
 * está ordernada
 * Steps:
 * 1. Comece pelo segundo elemento, já que o primeiro elemento é considerado ordenardo
 * Compare o segundo com o primeiro, se o segundo for menor, mude de lugar
 * Avance para o terceiro elemento,
 * compare com os dois primeiros elementos e coloque em sua posicao correta
 * Repita o processo ate que todo o conjunto esteja ordenardo
 * É como organizar cartas de baralho em suas mãos: você divide as cartas em dois grupos:
 * Os que ja estao ordenadas e os que ainda nao estao
 * Em seguida vc pega a carta do grupo nao ordenado e insere no lugar correto dentro do grupo que já está ordenado
 **/
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
void insertionSort(int *arr, int n) {
    for (int i = 1; i < n ; i++) {
        int key = arr[i];
        int k = i - 1;
        while (k >= 0 && arr[k] > key) {
            swap(&arr[k], &arr[k+1]);
            k--;
        }
    }
}

int main() {
    int array[8] = {8, 2, 6 , 3, 4, 5 , 1, 7};
    for (int i = 0; i < 8; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
    insertionSort(array, 8);
    for (int i = 0; i < 8; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}