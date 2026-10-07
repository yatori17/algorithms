//
// Created by 55219 on 06/10/2026.
//

#include "ex08.h"

#include <iostream>
#include "ex08.h"

int main() {
    PegaEntreMaioresNaoOrdenado tad;
    tad.cria();

    // Inserindo dados desordenados
    tad.insere('C');
    tad.insere('A');
    tad.insere('Z');
    tad.insere('F');
    tad.insere('M');

    std::cout << "Total de elementos: " << tad.tamanho() << std::endl;

    // A ordem correta decrescente seria: Z, M, F, C, A
    std::cout << "Maior elemento (esperado Z): " << tad.maior() << std::endl;
    std::cout << "Segundo maior (esperado M): " << tad.segundomaior() << std::endl;
    std::cout << "3o maior (esperado F): " << tad.kmaior(3) << std::endl;
    std::cout << "5o maior (esperado A): " << tad.kmaior(5) << std::endl;

    tad.libera();
    return 0;
}