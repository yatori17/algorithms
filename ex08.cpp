//
// Created by 55219 on 06/10/2026.
//

#include "ex08.h"

#include <iostream>
#include <chrono>
#include <cstdlib>
#include <iomanip>

template<typename TAD>
void testaDesempenho(int N, const char* nome_estrategia) {
    TAD* tad = new TAD();
    tad->cria();

    auto inicio_ins = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        tad->insere('A' + (rand() % 26));
    }
    auto fim_ins = std::chrono::high_resolution_clock::now();

    auto inicio_busca = std::chrono::high_resolution_clock::now();
    tad->kmaior(N / 2);
    auto fim_busca = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> tempo_ins = fim_ins - inicio_ins;
    std::chrono::duration<double, std::milli> tempo_busca = fim_busca - inicio_busca;

    std::cout << std::left << std::setw(15) << nome_estrategia
              << " | N=" << std::setw(8) << N
              << " | Insere: " << std::setw(10) << tempo_ins.count() << " ms"
              << " | Busca: " << tempo_busca.count() << " ms\n";

    tad->libera();
    delete tad;
}

int main() {
    /*
     * COMPLEXIDADES 8.a (Vetor Não Ordenado)
     * - insere(char): O(1) - Apenas adiciona ao final do vetor original.
     * - kmaior(int) / maior() / segundomaior(): O(N^2) - Como faz a cópia do vetor
     *   e executa um Bubble Sort completo a cada consulta, o custo é quadrático.
     */
    PegaEntreMaioresNaoOrdenado tad;
    tad.cria();

    std::cout << "--- TESTE 8.a: Bubble sort com metodos extraas de exercicio adicional ---" << std::endl;
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

    std::cout << "2o maior (esperado M) QuikcSort: " << tad.maiorQuickSort(2) << std::endl;
    std::cout << "o maior (esperado A) QuickSort: " << tad.maiorQuickSort(1) << std::endl;


    /*
     * COMPLEXIDADES 8.b (Insertion Sort "Online")
     * - insere(char): O(N) no pior caso - Empurra elementos à direita para manter o vetor ordenado.
     *   (Inserir N elementos custa O(N^2) no total, caracterizando o algoritmo pouco eficiente).
     * - kmaior(int) / maior() / segundomaior(): O(1) - O vetor está sempre perfeitamente
     *   ordenado, logo o acesso ao K-ésimo elemento é direto no índice.
     */
    std::cout << "\n--- TESTE 8.b: Insertion Sort ---" << std::endl;
    PegaEntreMaioresInsertionSort tad2;
    tad2.cria();
    tad2.insere('C');
    tad2.insere('A');
    tad2.insere('Z');
    tad2.insere('F');
    tad2.insere('Y');
    tad2.insere('L');

    std::cout << "Maior elemento (esperado Z): " << tad2.maior() << std::endl;
    std::cout << "Segundo maior (esperado Y): " << tad2.segundomaior() << std::endl;
    std::cout << "3o maior (esperado L): " << tad2.kmaior(3) << std::endl;
    std::cout << "6o maior (esperado A): " << tad2.kmaior(6) << std::endl;
    std::cout << "5o maior (esperado C): " << tad2.kmaior(5) << std::endl;

    tad.libera();
    tad2.libera();


    /*
     * COMPLEXIDADES 8.c (Quick Sort - Avaliação Preguiçosa)
     * - insere(char): O(1) - Apenas adiciona ao final e marca a flag "ordenado = false".
     * - kmaior(int) / maior() / segundomaior():
     *   -> O(N log N) (caso médio) se houveram novas inserções (precisa rodar o QuickSort).
     *   -> O(1) se não houveram novas inserções (a flag indica que já está ordenado).
     */
    std::cout << "\n--- TESTE 8.c: Quick Sort  ---" << std::endl;
    PegaEntraMaioresQuickSort tad3;
    tad3.cria();
    tad3.insere('C');
    tad3.insere('A');
    tad3.insere('Z');
    tad3.insere('F');
    tad3.insere('M');

    std::cout << "Maior elemento (esperado Z): " << tad3.maior() << std::endl;
    std::cout << "Segundo maior (esperado M): " << tad3.segundomaior() << std::endl;
    std::cout << "3o maior (esperado F): " << tad3.kmaior(3) << std::endl;
    std::cout << "5o maior (esperado A): " << tad3.kmaior(5) << std::endl;
    tad3.libera();


    /*
     * COMPLEXIDADES 8.d (Quick Select)
     * - insere(char): O(1) - Apenas adiciona ao final do vetor.
     * - kmaior(int) / maior() / segundomaior(): O(N) no caso médio - Faz a cópia do vetor em O(N)
     *   e o QuickSelect descarta metade da busca a cada partição. Pior caso teórico raro: O(N^2).
     */
    std::cout << "\n--- TESTE 8.d: Quick Select ---" << std::endl;
    PegaEntreMaioresQuickSelect tad4;
    tad4.cria();
    tad4.insere('C');
    tad4.insere('A');
    tad4.insere('Z');
    tad4.insere('F');
    tad4.insere('M');

    std::cout << "Maior elemento (esperado Z): " << tad4.maior() << std::endl;
    std::cout << "Segundo maior (esperado M): " << tad4.segundomaior() << std::endl;
    std::cout << "3o maior (esperado F): " << tad4.kmaior(3) << std::endl;
    std::cout << "5o maior (esperado A): " << tad4.kmaior(5) << std::endl;
    tad4.libera();

    // Bonus
    int valores_N[] = {10, 100, 1000, 10000, 100000, 1000000};

    std::cout << "Iniciando Benchmark...\n\n";

    for (int N : valores_N) {
        std::cout << "---------------------------------------------------------\n";

        // Programa nao execuuta para 1000000 para O2
        if (N <= 10000) {
            testaDesempenho<PegaEntreMaioresNaoOrdenado>(N, "8.a (Nao Ord)");
        } else {
            std::cout << "8.a (Nao Ord)   | N=" << std::setw(8) << N << " | IGNORADO (O(N^2) demoraria demais)\n";
        }
        // Programa nao execuuta para 1000000 paara O2
        if (N <= 100000) {
            testaDesempenho<PegaEntreMaioresInsertionSort>(N, "8.b (Insert)");
        } else {
            std::cout << "8.b (Insert)    | N=" << std::setw(8) << N << " | IGNORADO (O(N^2) demoraria demais)\n";
        }

        testaDesempenho<PegaEntraMaioresQuickSort>(N, "8.c (QuickSrt)");
        testaDesempenho<PegaEntreMaioresQuickSelect>(N, "8.d (QuickSel)");
    }

    return 0;
}