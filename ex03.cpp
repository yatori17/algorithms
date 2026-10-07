//
// Created by 55219 on 04/10/2026.
//

#include "ex03.h"

#include <iostream>

int main() {
    std::cout << "\n--- TESTANDO EXERCICIO 3: Fila com 2 Pilhas ---\n";

    Fila2P fila;

    std::cout << "Enfileirando 'A', 'B' e 'C'...\n";
    fila.enfileira('A');
    fila.enfileira('B');
    fila.enfileira('C');

    // Numa fila (FIFO), o primeiro a entrar ('A') tem de ser o primeiro a sair.
    std::cout << "Frente esperada: A | Obtida: " << fila.frente() << "\n";

    std::cout << "Desenfileira (Esperado: A) | Removido: " << fila.desenfileira() << "\n";
    std::cout << "Desenfileira (Esperado: B) | Removido: " << fila.desenfileira() << "\n";

    std::cout << "Nova Frente esperada: C | Obtida: " << fila.frente() << "\n";

    std::cout << "Enfileirando 'D'...\n";
    fila.enfileira('D');
    std::cout << "Nova Frente esperada: C | Obtida: " << fila.frente() << "\n";

    return 0;
}