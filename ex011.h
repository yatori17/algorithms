//
// Created by 55219 on 20/10/2026.
//

#ifndef WORKSPACE_EX011_H
#define WORKSPACE_EX011_H
#include <iostream>
#include <stack>
#include <queue>


class ex011 {
};

template<typename Agregado, typename Tipo>
concept DequeTAD = requires (Agregado a, Tipo t){
    {a.inicio()};
    {a.fim()};
    {a.insereInicio(t)};
    {a.insereFim(t)};
    {a.removeInicio()};
    {a.removeFim()};
};

template<typename Agregado, typename Tipo>
concept PilhaTAD = requires (Agregado a, Tipo t)
{
    {a.top()};
    {a.push(t)};
    {a.pop()};
};

template<typename Agregado, typename Tipo>
concept FilaTAD = requires (Agregado a, Tipo t)
{
    {a.front()};
    {a.push(t)};
    {a.pop()};
};


struct Node {
    char var;
    Node* next;
    Node* prev;
};

struct Deque {
    Node* head = nullptr;
    Node* tail = nullptr;

    void cria() {
        head = tail = nullptr;
    }

    void libera() {
        while (tail) {
            removeFim();
        }
    }

    void insereInicio(char var) {
        Node* node = new Node{var, nullptr, nullptr};
        if (!head) {
            head = tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }
    }

    void insereFim(char var) {
        Node* node = new Node{var, nullptr, nullptr};
        if (!tail) {
            head = tail = node;
        } else {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
    }

    char fim() {
        return tail->var;
    }

    char inicio() {
        return head->var;
    }

    char removeInicio() {
        char value = inicio();
        head = head->next;
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        return value;
    }

    char removeFim() {
        char value = fim();
        tail = tail->prev;
        if (tail) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        return value;
    }


};

struct PilhaDeque {
    Deque deque;

    void cria() {
        deque.cria();
    }

    void libera() {
        deque.libera();
    }

    void push(char var) {
        deque.insereFim(var);
    }

    char pop() {
        return deque.removeFim();
    }

    char top() {
        return deque.fim();
    }
};

struct FilaDeque {
    Deque deque;
    void cria() {
        deque.cria();
    }

    void libera() {
        deque.libera();
    }

    char front() {
        return deque.inicio();
    }

    void push(char var) {
        deque.insereFim(var);
    }

    char pop() {
        return deque.removeInicio();
    }
};

// Ex03. Criar Pilha2F com duas Pilhas stacks
// Fila --> Primeiro que entra eh o primeiro a sair
// Se quando empilharmos botar na fila nao adianta muita coisa
// pq eu tenho que garantir que o ultimo vai ser o primeiro a sair

void transbordaFilas(std::queue<char>* f1, std::queue<char>* f2) {
    while (!f1->empty()) {
        char value = f1->front();
        f2->push(value);
        f1->pop();
    }

}

struct Pilha2F {
    std::queue<char> f1;
    std::queue<char> f2;

    void push(char var) {
        transbordaFilas(&f1, &f2);
        f1.push(var);
        transbordaFilas(&f2, &f1);
    }

    char pop() {
        char value = f1.front();
        f1.pop();
        return value;
    }

    char top() {
        return f1.front();
    }
};

void transbordaPilhas(std::stack<char>* p1, std::stack<char>* p2) {
    while (!p1->empty()) {
        char value = p1->top();
        p2->push(value);
        p1->pop();
    }
}

// Implemente uma estrutura que satisfaz o TAD Fila para o tipo ‘char’ e somente utiliza duas Pilhas como armazenamento interno (mais espaço constante):
// #include<stack> // Pilha genérica em C++ (ou import std)

// Para esse temos que fazer algo parecido com o acima
struct Fila2P {
    std::stack<char> p1;
    std::stack<char> p2;

    void push(char var) {
        transbordaPilhas(&p1, &p2);
        p1.push(var);
        transbordaPilhas(&p2, &p1);
    }

    char pop() {
        char var = p1.top();
        p1.pop();
        return var;
    }

    char front() {
        return p1.top();
    }
};

constexpr int MAX_N = 100000;

struct PilhaMin {
    int v[MAX_N];
    int vetorMin[MAX_N];
    int n = 0;
    int nMin = 0;

    void cria() {
        n = 0;
        nMin = 0;
    }

    void libera() {
        n = 0;
        nMin = 0;
    }

    void push(int var) {
        if (n == 0 || (vetorMin[nMin - 1] >= var)) {
            vetorMin[nMin++] = var;
        }
        v[n++] = var;
    }

    int pop() {
        int var = v[n - 1];
        n--;
        if (var == vetorMin[nMin - 1]) {
            nMin = nMin - 1;
        }
        return var;
    }

    int top() {
        return v[n - 1];
    }

    int obterMinimo() {
        return vetorMin[nMin - 1];
    }

    int size() {
        return n;
    }

};

void imprimePilhaMin(PilhaMin pilhaMin) {
    while (pilhaMin.size() > 0) {
        std::cout << pilhaMin.pop() << " ";
    }
    std::cout << std::endl;
}

template<typename Agregado, typename Tipo>
concept PegaEntreMaioresTAD = requires(Agregado a, Tipo t)
{
    { a.insere(t) };
    // requer operação de retornar o maior elemento
    { a.maior() };
    // requer operação de retornar o segundo maior elemento
    { a.segundomaior() };
    // requer operação de retornar o k-esimo maior elemento
    { a.kmaior(int{}) };
    // requer operação
};

//constexpr int MAX_N = 100000;
struct PegaEntreMaiores {
    int vetor[MAX_N];
    int n;

    void cria() {
        n = 0;
    }
    void insere(int value) {
        vetor[n++] = value;
    }

    int tamanho() {
        return n;
    }

    int kmaior(int grau) {
        int aux[n];
        // copía vetor para um auxiliar
        for (int i = 0; i < n; i++) {
            aux[i] = vetor[i];
        }
        // InsertionSort hihihihihiih
        // 10 9 8
        for (int i = 1; i < n; i++) {
            int key = aux[i];
            int k = i - 1;
            while (k >= 0 && aux[k] > key) {
                int temp = aux [k + 1];
                aux[k + 1] = aux [k];
                aux[k] = temp;
            }
        }
        return aux[n - grau - 1];
    }

    int maior() {
        return kmaior(0);
    }

    int segundomaior() {
        return kmaior(1);
    }
};

struct PegaEntreMaioresOrdernado {
    int N;
    char vetor[MAX_N];

    void cria() {
        N = 0;
    }

    void libera() {
        N = 0;
    }

    // B C A
    // N = 2;
    void insere(char value) {
        int i = N - 1;
        while (i >= 0 && vetor[i] > value) {
            vetor[i + 1] = vetor[i];
            i--;
        }
        vetor[i + 1] = value;
        N++;
    }

    char maior() {
        return kmaior(1);
    }

    char segundomaior() {
        return kmaior(2);
    }

    char kmaior(int posicao) {
        return vetor[N - posicao];
    }

};

// Vou montar o quickSort com as vozes da minha cabeça
void swap (char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}
int particiona(char *vetor, int low, int high) {
    char pivot = vetor[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (vetor[j] < pivot) {
            i++;
            swap(&vetor[i], &vetor[j]);
        }
    }
    swap(&vetor[i + 1], &vetor[high]);
    return i + 1;
}

void quickSort(char *vetor, int low, int high) {
    if (low < high) {
        int pivot = particiona(vetor, low, high);
        quickSort(vetor, low, pivot - 1);
        quickSort(vetor, pivot + 1, high);
    }
}

struct PegaEntreMaioresQuickSort {
    char v[MAX_N];
    int N;
    bool ord = false;
    void cria() {
        N = 0;
    }

    void insere(char value) {
        v[N++] = value;
    }

    void libera() {
        N = 0;
    }

    char kmaior(int grau) {
        if (!ord) {
            quickSort(v, 0, N - 1);
            ord = true;
        }
        return v[N - grau];
    }

    char maior() {
        return kmaior(1);
    }

    char segundomaior() {
        return kmaior(2);
    }

};

static_assert(DequeTAD<Deque, char>);
static_assert(PilhaTAD<PilhaDeque, char>);
static_assert(FilaTAD<FilaDeque, char>);
static_assert(PilhaTAD<Pilha2F, char>);
static_assert(FilaTAD<Fila2P, char>);
static_assert(PilhaTAD<PilhaMin, char>);
static_assert(PegaEntreMaioresTAD<PegaEntreMaiores, int>);


#endif //WORKSPACE_EX011_H
