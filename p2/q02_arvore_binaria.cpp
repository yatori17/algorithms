//
// Created by 55219 on 22/11/2026.
//

#include <iostream>
#include "q02_arvore_binaria.h"

namespace {

NoBinChar* criarNo(char chave, NoBinChar* esq = nullptr, NoBinChar* dir = nullptr) {
    NoBinChar* no = new NoBinChar;
    no->chave = chave;
    no->esq = esq;
    no->dir = dir;
    return no;
}

void liberarArvore(NoBinChar* no) {
    if (no == nullptr) return;
    liberarArvore(no->esq);
    liberarArvore(no->dir);
    delete no;
}

void rodarCaso(const char* titulo, const ArvoreBinChar& arv, NoBinChar* raiz) {
    std::cout << "=== " << titulo << " ===\n";
    std::cout << "Nos: " << arv.contaNos(raiz)
              << " | Altura (vazia=-1): " << arv.altura(raiz) << "\n";
    std::cout << "Estrita binaria: " << arv.estritaBin(raiz)
              << " | Perfeita: " << arv.ehPerfeita(raiz)
              << " | Completa: " << arv.ehCompleta(raiz) << "\n";

    std::cout << "Em niveis: ";
    arv.emNiveis(raiz);
    std::cout << "\n";

    std::cout << "Pre-ordem: ";
    arv.preOrdem(raiz);
    std::cout << "\n";

    std::cout << "Pos-ordem: ";
    arv.posordem(raiz);
    std::cout << "\n";

    std::cout << "In-order:  ";
    arv.inorder(raiz);
    std::cout << "\n\n";
}

} // namespace

int main() {
    std::cout << std::boolalpha;
    ArvoreBinChar arv;

    // 1) Árvore vazia
    rodarCaso("Arvore vazia", arv, nullptr);

    // 2) Árvore perfeita e completa de altura 1 (3 nós):
    //      A
    //     / \
    //    B   C
    NoBinChar* perfeita = criarNo(
        'A',
        criarNo('B'),
        criarNo('C')
    );
    rodarCaso("Perfeita e completa (A, B, C)", arv, perfeita);
    liberarArvore(perfeita);

    // 3) Completa mas NÃO perfeita (4 nós):
    //        A
    //       / \
    //      B   C
    //     /
    //    D
    NoBinChar* completaNaoPerfeita = criarNo(
        'A',
        criarNo('B', criarNo('D'), nullptr),
        criarNo('C')
    );
    rodarCaso("Completa mas nao perfeita", arv, completaNaoPerfeita);
    liberarArvore(completaNaoPerfeita);

    // 4) Estritamente binária, mas NÃO completa e NÃO perfeita:
    //        A
    //       / \
    //      B   C
    //         / \
    //        D   E
    NoBinChar* estritaNaoCompleta = criarNo(
        'A',
        criarNo('B'),
        criarNo('C', criarNo('D'), criarNo('E'))
    );
    rodarCaso("Estrita binaria, nao completa", arv, estritaNaoCompleta);
    liberarArvore(estritaNaoCompleta);

    // 5) Nem estrita, nem completa, nem perfeita (buraco à esquerda de F):
    //        A
    //       / \
    //      B   C
    //       \
    //        F
    NoBinChar* comBuraco = criarNo(
        'A',
        criarNo('B', nullptr, criarNo('F')),
        criarNo('C')
    );
    rodarCaso("Com buraco (nao estrita, nao completa)", arv, comBuraco);
    liberarArvore(comBuraco);

    return 0;
}