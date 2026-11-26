#ifndef P2_Q02_ARVORE_BINARIA_H
#define P2_Q02_ARVORE_BINARIA_H

#include<queue>
#include<iostream>

struct NoBinChar {
    char chave;
    NoBinChar* esq;
    NoBinChar* dir;
};

class ArvoreBinChar {
public:
    // (a) Estritamente binária: todo nó tem 0 ou 2 filhos (vazia = true)
    bool estritaBin(NoBinChar* no) const {
        if (no == nullptr) return true;

        bool temEsq = (no->esq != nullptr);
        bool temDir = (no->dir != nullptr);

        if (temEsq != temDir) return false;
        return estritaBin(no->esq) && estritaBin(no->dir);
    }

    // (b) Imprime a árvore em níveis (BFS)
    void emNiveis(NoBinChar* no) const {
        if (no == nullptr) return;
        std::queue<NoBinChar*> q;
        q.push(no);
        while (!q.empty()) {
            NoBinChar* aux = q.front();
            q.pop();
            std::cout << aux->chave << " ";
            if (aux->esq != nullptr) {
                q.push(aux->esq);
            }
            if (aux-> dir != nullptr) {
                q.push(aux->dir);
            }
        }
    }

    int contaNos(NoBinChar* no) const {
        if (no == nullptr) return 0;
        return contaNos(no->esq) + contaNos(no->dir) + 1;
    }

    int altura(NoBinChar* no) const {
        if (no == nullptr) return 0;
        int he = altura(no->esq);
        int hd = altura(no->dir);
        if (he > hd) return he + 1;
        return hd + 1;
    }

    bool ehPerfeita(NoBinChar* no) const {
        if (no == nullptr) return true;
        const int n = contaNos(no);
        const int h = altura(no);
        return n == (1 << (h)) - 1;
    }

    bool ehCompleta(NoBinChar* no) const {
        if (no == nullptr) return true;
        std::queue<NoBinChar*> fila;
        fila.push(no);
        bool viuNulo = false;
        while (!fila.empty()) {
            NoBinChar* atual = fila.front();
            fila.pop();
            if (atual == nullptr) {
                viuNulo = true;
            } else {
                if (viuNulo) return false;
                fila.push(atual->esq);
                fila.push(atual->dir);
            }
        }
        return true;
    }

    // (f) Implemente um algoritmo que imprime a árvore no percurso
    // de pré-ordem: void preordem(NoBinChar* no);
    void preOrdem(NoBinChar* no) const {
        if (no == nullptr) return;
        std::cout << no-> chave << "\n";
        preOrdem(no->esq);
        preOrdem(no->dir);
    }

    //Implemente um algoritmo que imprime a árvore no percurso de pós-ordem:
    void posordem(NoBinChar* no) const {
        if (no == nullptr) return;
        posordem(no->esq);
        posordem(no->dir);
        std::cout << no-> chave << "\n";
    }

    //(h) Implemente um algoritmo que imprime a árvore no percurso em-ordem:
    void inorder(NoBinChar* no) const {
        if (no == nullptr) return;
        inorder(no->esq);
        std::cout << no -> chave << "\n";
        inorder(no->dir);
    }
};

#endif // P2_Q02_ARVORE_BINARIA_H