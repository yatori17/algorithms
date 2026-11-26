#include "q04_q10_abb.h"
#include <iostream>
#include <string>
#include <vector>

namespace {

void preencherLinhas(NoBinChar* no, int profundidade, int esq, int dir,
                     std::vector<std::string>& linhas) {
    if (no == nullptr) return;

    int linhaNo = profundidade * 2;
    if (static_cast<int>(linhas.size()) <= linhaNo) {
        linhas.resize(linhaNo + 2, std::string(120, ' '));
    }

    int meio = (esq + dir) / 2;
    if (meio >= 0 && meio < static_cast<int>(linhas[linhaNo].size())) {
        linhas[linhaNo][meio] = no->chave;
    }

    if (no->esq != nullptr) {
        int meioEsq = (esq + meio - 1) / 2;
        int barraEsq = (meio + meioEsq) / 2;
        if (barraEsq >= 0 && barraEsq < static_cast<int>(linhas[linhaNo + 1].size())) {
            linhas[linhaNo + 1][barraEsq] = '/';
        }
        preencherLinhas(no->esq, profundidade + 1, esq, meio - 1, linhas);
    }

    if (no->dir != nullptr) {
        int meioDir = (meio + 1 + dir) / 2;
        int barraDir = (meio + meioDir) / 2;
        if (barraDir >= 0 && barraDir < static_cast<int>(linhas[linhaNo + 1].size())) {
            linhas[linhaNo + 1][barraDir] = '\\';
        }
        preencherLinhas(no->dir, profundidade + 1, meio + 1, dir, linhas);
    }
}

void imprimirArvore(NoBinChar* raiz) {
    if (raiz == nullptr) {
        std::cout << "(arvore vazia)\n";
        return;
    }
    std::vector<std::string> linhas;
    preencherLinhas(raiz, 0, 0, 79, linhas);
    for (std::string& linha : linhas) {
        while (!linha.empty() && linha.back() == ' ') {
            linha.pop_back();
        }
        if (!linha.empty()) {
            std::cout << linha << "\n";
        }
    }
}

void emOrdem(NoBinChar* no) {
    if (no == nullptr) return;
    emOrdem(no->esq);
    std::cout << no->chave << " ";
    emOrdem(no->dir);
}

void liberarArvore(NoBinChar* no) {
    if (no == nullptr) return;
    liberarArvore(no->esq);
    liberarArvore(no->dir);
    delete no;
}

const char* strBool(bool v) {
    return v ? "true" : "false";
}

} // namespace

void imprimirBusca(char chave, NoBinChar* raiz) {
    char res = busca(chave, raiz);
    std::cout << "Busca '" << chave << "': ";
    if (res == '\0') std::cout << "'\\0' (nao encontrado)\n";
    else std::cout << "'" << res << "' (encontrado)\n";
}

int main() {
    std::cout << "=== 0) Arvore vazia ===\n";
    std::cout << "Maior: " << maior(nullptr) << " | Menor: " << menor(nullptr)
              << " | ehBinariaBusca: " << strBool(ehBinariaBusca(nullptr)) << "\n\n";

    imprimirBusca('M', nullptr);
    // 1) Árvore inicial: raiz 'M', inserindo 'F', 'T', 'B', 'H', 'P', 'Z'
    NoBinChar* raiz = new NoBinChar{'M', nullptr, nullptr};
    for (char c : {'F', 'T', 'B', 'H', 'P', 'Z'}) {
        insere(c, raiz);
    }

    std::cout << "=== 1) Arvore inicial ===\n";
    imprimirArvore(raiz);
    imprimirBusca('H', raiz); // encontrado (folha)
    imprimirBusca('M', raiz); // encontrado (raiz)
    imprimirBusca('Q', raiz); // '\0' (nao encontrado)
    std::cout << "Maior: " << maior(raiz) << " | Menor: " << menor(raiz)
              << " | ehBinariaBusca: " << strBool(ehBinariaBusca(raiz)) << "\n";
    std::cout << "Em-ordem: ";
    emOrdem(raiz);
    std::cout << "\n\n";

    // 2) Inserção de 'F' duplicada (com <= vai para a esquerda de 'F')
    insere('F', raiz);
    std::cout << "=== 2) Apos inserir 'F' duplicada ===\n";
    imprimirArvore(raiz);
    std::cout << "Maior Elemento: " << maior(raiz) << "\n";
    std::cout << "Menor Elemento: " << menor(raiz) << "\n";
    // 'F' duplicada à esquerda faz no->chave <= lower falhar em ehBinariaAux -> false
    std::cout << "ehBinariaBusca (esperado false por duplicata): "
              << strBool(ehBinariaBusca(raiz)) << "\n";
    std::cout << "Em-ordem: ";
    emOrdem(raiz);
    std::cout << "\n\n";

    // 3) Inserção crescente a partir de 'A'
    NoBinChar* dirDeg = new NoBinChar{'A', nullptr, nullptr};
    for (char c : {'B', 'C', 'D', 'E'}) {
        insere(c, dirDeg);
    }
    std::cout << "=== 3) Crescente A..E ===\n";
    imprimirArvore(dirDeg);
    std::cout << "Maior Elemento: " << maior(dirDeg) << "\n";
    std::cout << "Menor Elemento: " << menor(dirDeg) << "\n";
    std::cout << "ehBinariaBusca: " << strBool(ehBinariaBusca(dirDeg)) << "\n\n";

    // 4) Inserção decrescente a partir de 'E'
    NoBinChar* esqDeg = new NoBinChar{'E', nullptr, nullptr};
    for (char c : {'D', 'C', 'B', 'A'}) {
        insere(c, esqDeg);
    }
    std::cout << "=== 4) Decrescente E..A ===\n";
    imprimirArvore(esqDeg);
    std::cout << "Maior Elemento: " << maior(esqDeg) << "\n";
    std::cout << "Menor Elemento: " << menor(esqDeg) << "\n";
    std::cout << "ehBinariaBusca: " << strBool(ehBinariaBusca(esqDeg)) << "\n\n";

    liberarArvore(raiz);
    liberarArvore(dirDeg);
    liberarArvore(esqDeg);

    return 0;
}