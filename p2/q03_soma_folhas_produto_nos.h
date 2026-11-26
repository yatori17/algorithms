//
// Created by 55219 on 22/11/2026.
//

#ifndef P2_Q03_SOMA_FOLHAS_PRODUTO_NOS_H
#define P2_Q03_SOMA_FOLHAS_PRODUTO_NOS_H


class Questao03 {
};

struct NoBinInt {
    int valor;
    NoBinInt* esq;
    NoBinInt* dir;
};
struct Arvore {
    NoBinInt* raiz;
};

// (a) Escreva um algoritmo para computar a soma das folhas.
int somaFolhas(NoBinInt* raiz) {
    if (raiz == nullptr) return 0;
    if (raiz -> esq == nullptr && raiz ->dir == nullptr) return raiz->valor;
    return somaFolhas(raiz->esq) + somaFolhas(raiz->dir);
}

// (b) Escreva um algoritmo para computar o produto dos nós.
int produtoNos(NoBinInt* raiz) {
    if (raiz == nullptr) return 1;
    return raiz->valor * produtoNos(raiz->esq) * produtoNos(raiz->dir);
}
#endif //P2_Q03_SOMA_FOLHAS_PRODUTO_NOS_H
