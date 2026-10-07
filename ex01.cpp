#include "ex01.h"
#include <iostream>

void troca(int *ptr1, int *ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main() {
    std::cout << "--- TESTANDO PONTEIROS ---\n";
    int a = 10;
    int b = 20;
    std::cout << "Valor de A antes de trocar:" << a << "\n";
    std::cout << "Valor de B antes de trocar:" << b << "\n";
    troca(&a, &b);
    std::cout << "Valor de A depois de trocar:" << a << "\n";
    std::cout << "Valor de B depois de trocar:" << b << "\n";

    std::cout << "\n--- TESTANDO DEQUE ---\n";
    Deque meuDeque;
    meuDeque.cria();

    meuDeque.insereFim('A');
    meuDeque.insereFim('B');
    meuDeque.insereInicio('C');
    meuDeque.insereInicio('D');

    std::cout << "Inicio esperado: D | Obtido: " << meuDeque.inicio() << "\n";
    std::cout << "Fim esperado:    B | Obtido: " << meuDeque.fim() << "\n";

    char remInicio = meuDeque.removeInicio();
    std::cout << "Remove Inicio (Esperado: D) | Removido: " << remInicio << "\n";

    char remFim = meuDeque.removeFim();
    std::cout << "Remove Fim    (Esperado: B) | Removido: " << remFim << "\n";

    meuDeque.libera(); // Obrigatório limpar a memória dinâmica!


    std::cout << "\n--- TESTANDO PILHA DEQUE (LIFO) ---\n";
    PilhaDeque minhaPilha;
    minhaPilha.cria();

    minhaPilha.empilha('X');
    minhaPilha.empilha('Y');
    minhaPilha.empilha('Z');

    std::cout << "Topo esperado: Z | Obtido: " << minhaPilha.topo() << "\n";
    std::cout << "Desempilha (Esperado: Z) | Removido: " << minhaPilha.desempilha() << "\n";
    std::cout << "Desempilha (Esperado: Y) | Removido: " << minhaPilha.desempilha() << "\n";

    minhaPilha.libera();


    std::cout << "\n--- TESTANDO FILA DEQUE (FIFO) ---\n";
    FilaDeque minhaFila;
    minhaFila.cria();

    minhaFila.enfileira('1');
    minhaFila.enfileira('2');
    minhaFila.enfileira('3');

    std::cout << "Frente esperada: 1 | Obtida: " << minhaFila.frente() << "\n";
    std::cout << "Desenfileira (Esperado: 1) | Removido: " << minhaFila.desenfileira() << "\n";
    std::cout << "Desenfileira (Esperado: 2) | Removido: " << minhaFila.desenfileira() << "\n";

    minhaFila.libera();

    return 0;
}