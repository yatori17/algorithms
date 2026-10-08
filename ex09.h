//
// Created by 55219 on 06/10/2026.
//

#ifndef WORKSPACE_EX09_H
#define WORKSPACE_EX09_H


class ex09 {
};

// ANALISE DE COMPLEXIDADE ASSINTOTICA:
//  - adiciona(char): O(1). Insercao direta no final do vetor, sem realocacao.
//  - remove(char):   O(N). A remocao fisica custa O(1), mas a busca linear
//                    para encontrar o elemento custa O(N) no pior caso.
//  - busca(char):    O(N). Varredura linear pelo vetor.
//  - itera():        O(1). Incremento de indice simples a cada chamada.
//  - iteravolta():   O(1). Decremento de indice simples a cada chamada.
constexpr int MAX_SACO = 100000;

struct SacoVaiEVem {
    int N;
    char v[MAX_SACO];

    int indice_itera;
    int indice_volta;

    void cria() {
        N = 0;
        indice_itera = 0;
        indice_volta = -1;
    }

    void libera() {
        N = 0;
    }

    void adiciona(char t) {
        if (N < MAX_SACO) {
            v[N++] = t;
        }
    }

    bool busca(char t) {
        for (int i = 0; i < N; i++) {
            if (v[i] == t) return true;
        }
        return false;
    }

    bool remove(char t) {
        for (int i = 0; i < N; i++) {
            if (v[i] == t) {
                v[i] = v[N - 1];
                N--;
                return true;
            }
        }
        return false;
    }

    void reinicia_itera() {
        indice_itera = 0;
    }

    bool itera(char &saida) {
        if (indice_itera < N) {
            saida = v[indice_itera++];
            return true;
        }
        return false;
    }

    void reinicia_iteravolta() {
        indice_volta = N - 1;
    }

    bool iteravolta(char &saida) {
        if (indice_volta >= 0) {
            saida = v[indice_volta--];
            return true;
        }
        return false;
    }
};

#endif //WORKSPACE_EX09_H
