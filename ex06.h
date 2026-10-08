//
// Created by 55219 on 05/10/2026.
//

#ifndef WORKSPACE_EX06_H
#define WORKSPACE_EX06_H


class ex06 {
};
// Repetindo para fixar melhor

template<typename Agregado, typename Tipo>
concept PilhaTAD = requires(Agregado a, Tipo b)
{
    { a.topo() };
    { a.desempilha() };
    { a.empilha(b) };
    { a.obterMinimo() };
};

constexpr int MAX_N = 100000;
/*Manter dois arranjos estáticos sincronizados, um para os valores regulares e outro
que espelha o valor mínimo correspondente a cada nível da pilha.
• Complexidade: Todas as operações (empilha, desempilha, topo e obterMinimo) mantêm
custo O(1) rigoroso em tempo. O custo de espaço é estático O(MAX_N).
*/
struct PilhaMin {
    int elementos[MAX_N];
    int minimo[MAX_N];
    int N;
    int min;
    void cria() {
        N = 0;
        min = 0;
    }
    void libera() {
        N = 0;
        min = 0;
    }

    int topo() {
        return elementos[N-1];
    }

    void empilha(int elemento) {
        elementos[N++] = elemento;
        if (N == 1 || elemento <= minimo[min - 1]) {
            minimo[min++] = elemento;
        }
    }

    int desempilha() {
        if (elementos[N-1] == minimo[min - 1]) {
            min = min - 1;
        }
        return elementos[--N];
    }
    int tamanho() {
        return N;
    }
    int obterMinimo() {
        return minimo[min - 1];
    }

};

#endif //WORKSPACE_EX06_H
