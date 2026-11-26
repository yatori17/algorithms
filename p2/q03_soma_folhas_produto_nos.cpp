//
// Created by 55219 on 22/11/2026.
//

#include "q03_soma_folhas_produto_nos.h"
#include <iostream>

namespace {

NoBinInt* criarNo(int valor, NoBinInt* esq = nullptr, NoBinInt* dir = nullptr) {
    NoBinInt* no = new NoBinInt;
    no->valor = valor;
    no->esq = esq;
    no->dir = dir;
    return no;
}

void liberarArvore(NoBinInt* no) {
    if (no == nullptr) return;
    liberarArvore(no->esq);
    liberarArvore(no->dir);
    delete no;
}

void testarSoma(const char* titulo, NoBinInt* raiz, int esperado) {
    int obtido = somaFolhas(raiz);
    std::cout << titulo
              << " | obtido: " << obtido
              << " | esperado: " << esperado
              << (obtido == esperado ? " [OK]" : " [FALHA]") << "\n";
}

} // namespace

int main() {
    // 1) Árvore vazia
    Arvore arvVazia{nullptr};
    testarSoma("Arvore vazia", arvVazia.raiz, 0);

    // 2) Apenas a raiz (raiz também é folha)
    NoBinInt* soRaiz = criarNo(42);
    testarSoma("Apenas raiz (folha unica)", soRaiz, 42);
    liberarArvore(soRaiz);

    // 3) Árvore mista com folhas e nós internos:
    //          10
    //         /  \
    //        5    20
    //       / \     \
    //      2   8     30
    // Folhas: 2, 8, 30 -> soma = 40 (10, 5, 20 são internos)
    NoBinInt* mista = criarNo(
        10,
        criarNo(5, criarNo(2), criarNo(8)),
        criarNo(20, nullptr, criarNo(30))
    );
    testarSoma("Arvore mista (folhas 2, 8, 30)", mista, 40);
    liberarArvore(mista);

    // 4) Valores negativos e zero nas folhas:
    //         -10
    //         /   \
    //       -5     15
    //       /        \
    //     -20         0
    // Folhas: -20, 0 -> soma = -20
    NoBinInt* negativos = criarNo(
        -10,
        criarNo(-5, criarNo(-20), nullptr),
        criarNo(15, nullptr, criarNo(0))
    );
    testarSoma("Valores negativos e zero", negativos, -20);
    liberarArvore(negativos);

    // 5) Cadeia degenerada à direita (apenas 1 folha no fim):
    //      1 -> 2 -> 3 -> 7
    NoBinInt* degenerada = criarNo(
        1,
        nullptr,
        criarNo(2, nullptr, criarNo(3, nullptr, criarNo(7)))
    );
    testarSoma("Degenerada a direita (unica folha 7)", degenerada, 7);
    liberarArvore(degenerada);

    NoBinInt* arvProd = criarNo(
    2,
    criarNo(3, criarNo(5), nullptr),
    criarNo(4)
);
    // Produto esperado: 2 * 3 * 5 * 4 = 120
    std::cout << "Produto (esperado 120): " << produtoNos(arvProd) << "\n";
    std::cout << "Produto vazia (esperado 1): " << produtoNos(nullptr) << "\n";
    liberarArvore(arvProd);

    return 0;
}