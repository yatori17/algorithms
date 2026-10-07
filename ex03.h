//
// Created by 55219 on 04/10/2026.
//

#ifndef WORKSPACE_EX03_H
#define WORKSPACE_EX03_H
#include <stack>

class ex03 {
};

template<typename Agregado, typename Tipo>
concept FilaTAD = requires (Agregado a, Tipo t) {
    { a.frente() };
    { a.enfileira(t) };
    { a.desenfileira() };
};

struct Fila2P {

    std::stack<char> p1;
    std::stack<char> p2;

    char frente() {
        return p1.top();
    }

    void enfileira(char t) {
        transbordaP1ParaP2();
        p1.push(t);
        transbordaP2ParaP1();
    }

    char desenfileira() {
        char topo = p1.top();
        p1.pop();
        return topo;
    }

    void transbordaP1ParaP2() {
        while (!p1.empty()) {
            p2.push(p1.top());
            p1.pop();
        }
    }

    void transbordaP2ParaP1() {
        while (!p2.empty()) {
            p1.push(p2.top());
            p2.pop();
        }
    }

};


static_assert(FilaTAD<Fila2P, char>);
#endif //WORKSPACE_EX03_H
