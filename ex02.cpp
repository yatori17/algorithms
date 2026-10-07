//
// Created by 55219 on 04/10/2026.
//

#include "ex02.h"
#include <iostream>

int main() {
    std::cout << "\n--- TESTANDO EXERCICIO 2: Pilha com 2 Filas ---\n";

    Pilha2F pilha;

    std::cout << "Empilhando 'A', 'B' e 'C'...\n";
    pilha.empilha('A');
    pilha.empilha('B');
    pilha.empilha('C');

    // Numa pilha (LIFO), o último a entrar ('C') tem de ser o primeiro a sair.
    std::cout << "Topo esperado: C | Obtido: " << pilha.topo() << "\n";

    std::cout << "Desempilha (Esperado: C) | Removido: " << pilha.desempilha() << "\n";
    std::cout << "Desempilha (Esperado: B) | Removido: " << pilha.desempilha() << "\n";

    std::cout << "Novo Topo esperado: A | Obtido: " << pilha.topo() << "\n";

    std::cout << "Empilhando 'X'...\n";
    pilha.empilha('X');
    std::cout << "Novo Topo esperado: X | Obtido: " << pilha.topo() << "\n";

    std::cout << "Pilha liberada com sucesso!\n";

    return 0;
}