//
// Created by 55219 on 06/10/2026.
//

#ifndef WORKSPACE_EX08_H
#define WORKSPACE_EX08_H


class ex08 {
};

template<typename Agregado, typename Tipo>
concept PegaEntreMaioresTAD = requires(Agregado a, Tipo t) {
    // requer operação 'insere' sobre tipo 't'
    { a.insere(t) };
    // requer operação de retornar o maior elemento
    { a.maior() };
    // requer operação de retornar o segundo maior elemento
    { a.segundomaior() };
    // requer operação de retornar o k-esimo maior elemento
    { a.kmaior(int{}) };
    // requer operação tamanho, ou seja, numero total de elementos
    { a.tamanho() };
};

void copiaVetor(char origem[], char destino[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        destino[i] = origem[i];
    }
}

// 8.a
constexpr int MAX_N = 100000;
struct PegaEntreMaioresNaoOrdenado {
    int N;
    char v[MAX_N];
    char aux[MAX_N];

    void cria() {
        N = 0;
    }

    void libera() {
        N = 0;
    }

    int tamanho() {
        return N;
    }

    void insere(char t) {
        v[N++] = t;
    }

    char maior() {
        return kmaior(1);
    }

    char segundomaior() {
        return kmaior(2);
    }

    char kmaior(int t) {
        copiaVetor(v, aux, N);
        // Bubble sort CRESCENTE simples no vetor
        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j < N - i - 1; j++) {
                if (aux[j] < aux[j + 1]) {
                    char temp = aux[j];
                    aux[j] = aux[j + 1];
                    aux[j + 1] = temp;
                }
            }
        }
        return aux[t -1];
    }

};

static_assert(PegaEntreMaioresTAD<PegaEntreMaioresNaoOrdenado, char>);
#endif //WORKSPACE_EX08_H
