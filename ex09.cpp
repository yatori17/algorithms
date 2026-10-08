//
// Created by 55219 on 06/10/2026.
//

#include "ex09.h"
#include "iostream"

int main() {
    SacoVaiEVem saco;
    saco.cria();

    saco.adiciona('A');
    saco.adiciona('B');
    saco.adiciona('C');
    saco.adiciona('D');

    char elemento;

    std::cout << "--- Iterando (Frente para Tras) ---\n";
    saco.reinicia_itera();
    while (saco.itera(elemento)) {
        std::cout << elemento << " ";
    }
    std::cout << "\n";

    std::cout << "--- Iterando Volta (Tras para Frente) ---\n";
    saco.reinicia_iteravolta();
    while (saco.iteravolta(elemento)) {
        std::cout << elemento << " "; // Esperado: D C B A
    }
    std::cout << "\n";

    std::cout << "--- Removendo 'B' ---\n";
    saco.remove('B');

    std::cout << "--- Iterando Apos Remocao ---\n";
    saco.reinicia_itera();
    while (saco.itera(elemento)) {
        // Como o B saiu e o ultimo (D) tomou o lugar, a ordem será: A D C
        std::cout << elemento << " ";
    }
    std::cout << "\n";

    saco.libera();
    return 0;
}