//
// Created by 55219 on 23/11/2026.
//

#ifndef P2_Q12_Q14_AVL_H
#define P2_Q12_Q14_AVL_H
#include "q02_arvore_binaria.h"


class Questao12 {
};

// Questao 12
int altura(NoBinChar* no) {
    if (no == nullptr) return 0;
    int hEsquerda = altura(no->esq);
    int hDireita = altura(no->dir);
    if (hEsquerda > hDireita) return hEsquerda + 1;
    return hDireita + 1;
}
// Implemente um algoritmo que calcula o fator de
// balanceamento de um nó: int fator(NoBinChar* no);
int fator(NoBinChar* no) {
    if (no == nullptr) return 0;
    return altura(no->esq) - altura(no->dir);
}

//Implemente um algoritmo que imprime na tela qual dos 4 tipos de
// rotação é necessário em um dado nó, para uma AVL desbalanceada:
void qualRotacao(NoBinChar* no) {
    if (no == nullptr) {
        std::cout << "Nenhuma rotacao necessaria! Arvore vazia";
        return;
    }
    int fatorPai = fator(no);
    if (fatorPai >= 2) {
        if (no->esq != nullptr && fator(no->esq) <= -1) {
            std::cout << "Rotação Dupla á direita";
        } else {
            std::cout << "Rotação Simples á direita";
        }

    } else if (fatorPai <= -2) {
        if (no->dir != nullptr && fator(no->dir) >= 1) {
            std::cout << "Rotação Dupla á esquerda";
        } else {
            std::cout << "Rotação Simples á esquerda";
        }

    } else {
        std::cout << "Nenhuma rotacao necessaria! Arvore balanceada";
    }
}


#endif //P2_Q12_Q14_AVL_H
