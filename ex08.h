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
void troca(char v[], int i, int j) {
    char teste = v[i];
    v[i] = v[j];
    v[j] = teste;
}

int particiona(char arr[], int baixo, int alto) {
    char pivo = arr[alto];
    int i = baixo - 1;
    for (int j = baixo; j < alto; j++) {
        if (arr[j] <= pivo) {
            i++;
            char temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    char temp = arr[i + 1];
    arr[i + 1] = arr[alto];
    arr[alto] = temp;
    return i + 1;
}

void quickSort(char arr[], int baixo, int alto) {
    if (baixo < alto) {
        int pi = particiona(arr, baixo, alto);
        quickSort(arr, baixo, pi - 1);
        quickSort(arr, pi + 1, alto);
    }
}

char quickSelect(char arr[], int baixo, int alto, int indiceAlvo) {
    if (baixo == alto) {
        return arr[baixo];
    }
    int pi = particiona(arr, baixo, alto);

    if (pi == indiceAlvo) {
        return arr[pi];
    }
    if (indiceAlvo < pi) {
        return quickSelect(arr, baixo , pi -1 , indiceAlvo);
    }
    return quickSelect(arr, pi + 1, alto, indiceAlvo);


}

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

    char maiorInsertionSort(int t) {
        copiaVetor(v, aux, N);
        for (int i = 1; i < N; i++) {
            char key = aux[i];
            int j = i - 1;
            while (j >= 0 && aux[j] > key) {
                aux[j + 1] = aux[j];
                j--;
            }
            aux[++j] = key;
        }
        return aux[N - t];
    }


    char maiorQuickSort(int t) {
        copiaVetor(v, aux, N);
        quickSort(aux, 0, N - 1);
        return aux[N - t];
    }

};

struct PegaEntreMaioresInsertionSort {
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
        int i = N - 1;
        while (i >= 0 && v[i] > t) {
            v[i + 1] = v[i];
            i--;
        }
        v[i + 1] = t;
        N++;
    }

    char maior() {
        return kmaior(1);
    }

    char segundomaior() {
        return kmaior(2);
    }

    char kmaior(int t) {
        return v[N - t];
    }

};

// Estrutura 8.c
struct PegaEntraMaioresQuickSort {
    int N;
    char v[MAX_N];
    bool ordenado = false;

    void cria() {
        N = 0;
        ordenado = true;
    }

    void libera() {
        N = 0;
    }
    int tamanho() {
        return N;
    }

    void insere(char t) {
        v[N++] = t;
        ordenado = false;
    }

    char kmaior(int t) {
        if (!ordenado) {
            quickSort(v, 0, N - 1);
            ordenado = true;
        }
        return v[N - t];
    }

    char maior() {
        return kmaior(1);
    }

    char segundomaior() {
        return kmaior(2);
    }
};

struct PegaEntreMaioresQuickSelect {
    int N;
    char v[MAX_N];
    char aux[MAX_N];

    void cria() { N = 0; }
    void libera() { N = 0; }
    int tamanho() { return N; }

    void insere(char t) {
        v[N++] = t;
    }

    char kmaior(int k) {
        copiaVetor(v, aux, N);

        int indice_alvo = N - k;
        return quickSelect(aux, 0, N - 1, indice_alvo);
    }

    char maior() { return kmaior(1); }
    char segundomaior() { return kmaior(2); }
};

static_assert(PegaEntreMaioresTAD<PegaEntreMaioresQuickSelect, char>);
static_assert(PegaEntreMaioresTAD<PegaEntraMaioresQuickSort, char>);
static_assert(PegaEntreMaioresTAD<PegaEntreMaioresNaoOrdenado, char>);
static_assert(PegaEntreMaioresTAD<PegaEntreMaioresInsertionSort, char>);
#endif //WORKSPACE_EX08_H
