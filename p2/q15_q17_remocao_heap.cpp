//
// Created by 55219 on 24/11/2026.
//

#include "q15_q17_remocao_heap.h"

void desce(int heap[], int N, int i) {
    while (true) {
        int maior = i;
        int esq = 2 * i + 1;
        int dir = esq + 1;

        if (esq < N && heap[esq] > heap[maior]) maior = esq;
        if (dir < N && heap[dir] > heap[maior]) maior = dir;

        if (maior == i) return;
        int tmp = heap[maior];
        heap[maior] = heap[i];
        heap[i] = tmp;

        i = maior;
    }
}

    void heapify(int heap[], int N) {
        for (int i = N/2 -1; i >= 0; i--) {
            desce(heap, N, i);
        }
    }

// 16. Implemente um algoritmo que verifica se uma árvore é um heap:
bool ehHeap(int heap[], int N) {
    for (int i= 1; i < N; i++) {
        if (heap[i] > heap[(i-1)/2]) return false;
    }
    return true;
}

// 17. Implemente um algoritmo que adiciona um novo elemento em uma fila de prioridade:
void novo(int elemento, int heap[], int N) {
    int i = N;
    heap[i] = elemento;
    while (i > 0 && heap[i] > heap[(i-1)/2]) {
        int tmp = heap[i];
        heap[i] = heap[(i-1)/2];
        heap[(i-1)/2] = tmp;
        i = (i-1)/2;
    }
}


// Remove abb
NoBinChar* remove(char chave, NoBinChar* no) {
    if (no == nullptr) return nullptr;

    if (chave < no->chave) {
        no->esq = remove(chave, no->esq);
    } else if (chave > no->chave) {
        no->dir = remove(chave, no->dir);
    } else {
        // Caso 1: Nó folha (sem filhos)
        if (no->esq == nullptr && no->dir == nullptr) {
            delete no;
            return nullptr;
        }
        // Caso 2: Nó com apenas 1 filho
        if (no->esq == nullptr) {
            NoBinChar* temp = no->dir;
            delete no;
            return temp;
        }
        if (no->dir == nullptr) {
            NoBinChar* temp = no->esq;
            delete no;
            return temp;
        }
        // Caso 3: Nó com 2 filhos (substitui pelo sucessor em-ordem)
        NoBinChar* suc = no->dir;
        while (suc->esq != nullptr) {
            suc = suc->esq;
        }
        no->chave = suc->chave;
        no->dir = remove(suc->chave, no->dir);
    }
    return no;
}