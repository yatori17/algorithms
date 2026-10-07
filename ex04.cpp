//
// Created by 55219 on 04/10/2026.
//

#include "ex04.h"

#include <stack>
#include <queue>
#include <iostream>

// 04.A
void inverte4a(std::stack<char>* p) {
    std::queue<char> filaAux;
    while (!p->empty()) {
        char aux = p->top();
        p->pop();
        filaAux.push(aux);
    }

    while (!filaAux.empty()) {
        char aux = filaAux.front();
        filaAux.pop();
        p->push(aux);
    }
}


void inverte4b(std::stack<char>* p) {
    std::stack<char> p1; // primeira pilha auxiliar
    std::stack<char> p2; // segunda pilha auxiliar
    while (!p->empty()) {
        char aux = p->top();
        p1.push(aux);
        p->pop();
    }
    while (!p1.empty()) {
        char aux = p1.top();
        p2.push(aux);
        p1.pop();
    }
    while (!p2.empty()) {
        char aux = p2.top();
        p->push(aux);
        p2.pop();
    }
}

void inverte4c(std::stack<char>* p) {
    std::stack<char> p1;
    int n = p->size();
    for (int i = 0; i < n; i++) {
        char aux = p->top();
        p->pop();
        for (int j = 0; j < n - i - 1; j++) {
            char aux2 = p->top();
            p->pop();
            p1.push(aux2);
        }
        p->push(aux);
        for (int j = 0; j < n - i - 1; j++) {
            char aux2 = p1.top();
            p1.pop();
            p->push(aux2);
        }
    }
}

void imprimePilha(std::stack<char> p) {
    while (!p.empty()) {
        std::cout << p.top();
        p.pop();
    }
    std::cout << "\n";
}

int main() {
    std::stack<char> pilha;

    pilha.push('A');
    pilha.push('M');
    pilha.push('O');
    pilha.push('R');
    pilha.push('A');

    imprimePilha(pilha);
    inverte4c(&pilha);
    imprimePilha(pilha);
    return 0;

}
