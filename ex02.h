//
// Created by 55219 on 04/10/2026.
//

#ifndef WORKSPACE_EX02_H
#define WORKSPACE_EX02_H
#include <queue>


class ex02 {
};
template<typename Agregado, typename Tipo>
concept PilhaTAD = requires (Agregado a, Tipo t) {
    { a.topo() };
    { a.empilha(t) };
    { a.desempilha() };
};


struct Pilha2F {
    std::queue<char> f1;
    std::queue<char> f2;

    char topo() {
        return f1.front();
    }

    void empilha(char value) {
        f2.push(value);
        transbordaF1ParaF2();
        transbordaF2paraF1();
    }

    char desempilha() {
        char value = f1.front();
        f1.pop();
        return value;
    }


    void transbordaF1ParaF2() {
        while (!f1.empty()) {
            f2.push(f1.front());
            f1.pop();
        }
    }

    void transbordaF2paraF1() {
        while (!f2.empty()) {
            f1.push(f2.front());
            f2.pop();
        }
    }
};

static_assert(PilhaTAD<Pilha2F, char>);

#endif //WORKSPACE_EX02_H
