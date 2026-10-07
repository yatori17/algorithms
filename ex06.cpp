//
// Created by 55219 on 05/10/2026.
//

#include "ex06.h"
#include <iostream>

void imprimePilhaMin(PilhaMin pilhaMin) {
    while (pilhaMin.tamanho() > 0) {
        std::cout << pilhaMin.desempilha() << " ";
    }
    std::cout << std::endl;
}

int main() {
    PilhaMin pilhaMin;
    pilhaMin.cria();
    pilhaMin.empilha(10);
    std::cout << pilhaMin.obterMinimo() << std::endl;
    pilhaMin.empilha(8);
    std::cout << pilhaMin.obterMinimo() << std::endl;
    pilhaMin.empilha(9);
    std::cout << pilhaMin.obterMinimo() << std::endl;
    pilhaMin.empilha(7);
    std::cout << pilhaMin.obterMinimo() << std::endl;
    pilhaMin.empilha(1);
    std::cout << pilhaMin.obterMinimo() << std::endl;
    pilhaMin.empilha(7);
    std::cout << pilhaMin.obterMinimo() << std::endl;
    imprimePilhaMin(pilhaMin);
    // Desempilhando ahora
    std::cout << pilhaMin.obterMinimo() << std::endl;
    pilhaMin.desempilha();
    std::cout << pilhaMin.obterMinimo() << std::endl;
    pilhaMin.desempilha();
    std::cout << pilhaMin.obterMinimo() << std::endl;
    pilhaMin.desempilha();
    std::cout << pilhaMin.obterMinimo() << std::endl;
    pilhaMin.desempilha();
    std::cout << pilhaMin.obterMinimo() << std::endl;
    pilhaMin.desempilha();
    std::cout << pilhaMin.obterMinimo() << std::endl;
    pilhaMin.desempilha();
    pilhaMin.libera();
}