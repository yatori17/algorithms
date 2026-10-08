//
// Created by 55219 on 04/10/2026.
//

#include "ex05.h"
#include <stack>
#include <queue>
#include <iostream>


void imprimeFila(std::queue<char> p) {
    while (!p.empty()) {
        std::cout << p.front();
        p.pop();
    }
    std::cout << "\n";
}

void inverte5a(std::queue<char>* f) {
    std::stack<char> p;
    while (!f->empty()) {
        p.push(f->front());
        f->pop();
    }
    while (!p.empty()) {
        f->push(p.top());
        p.pop();
    }
}

// como o espaço auxiliar extra permitido é de tamanho constante, a inversão exige algoritmos de manuseamento
// em cascata com complexidade de tempo O(N2), guardando o "último" elemento
// temporariamente a cada repetição.
void inverte5b(std::queue<char>* f) {
    std::queue<char> f1;
    std::queue<char> f2;
    int N = f->size();
    for (int i = 0; i < N; i++) {
        for (int j = 0 ; j < N - i - 1; j++) {
            f1.push(f->front());
            f->pop();
        }
        f2.push(f->front());
        f->pop();
        for (int j = 0 ; j < N - i - 1; j++) {
            f->push(f1.front());
            f1.pop();
        }
    }
    while (!f2.empty()) {
        f->push(f2.front());
        f2.pop();
    }
}

int main() {
    std::queue<char> fila;

    fila.push('A');
    fila.push('M');
    fila.push('O');
    fila.push('R');
    fila.push('A');
    imprimeFila(fila);
    inverte5b(&fila);
    imprimeFila(fila);
    return 0;

}