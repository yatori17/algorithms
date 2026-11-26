//
// Created by 55219 on 20/10/2026.
//

#include "ex011.h"
#include "iostream"


void imprimePilha(std::stack<char> p) {
    while (!p.empty()) {
        std::cout << p.top();
        p.pop();
    }
    std::cout << "\n";
}

void imprimeFila(std::queue<char> p) {
    while (!p.empty()) {
        std::cout << p.front();
        p.pop();
    }
    std::cout << "\n";
}

void inverte4a(std::stack<char>* p) {
    std::queue<char> f;
    while (!p->empty()) {
        char value = p->top();
        f.push(value);
        p->pop();
    }

    while (!f.empty()) {
        char value = f.front();
        p->push(value);
        f.pop();
    }
}

void inverte4b(std::stack<char>* p) {
    std::stack<char> p1; // primeira pilha auxiliar
    std::stack<char> p2; // segunda pilha auxiliar
    // mais espaço auxiliar constante

    while (!p->empty()) {
        char value = p->top();
        p1.push(value);
        p->pop();
    }

    while (!p1.empty()) {
        char value = p1.top();
        p2.push(value);
        p1.pop();
    }

    while (!p2.empty()) {
        char value = p2.top();
        p->push(value);
        p2.pop();
    }
}

void inverte4c(std::stack<char>* p) {
    std::stack<char> p1; // uma pilha auxiliar
    // mais espaço auxiliar constante
    int n = p->size();
    for (int i = 0; i < n; i++) {
        char aux = p->top();
        p->pop();
        for (int j = 0; j < n - i - 1; j++) {
            p1.push(p->top());
            p->pop();
        }
        p->push(aux);
        for (int j = 0; j < n - i - 1; j++) {
            p->push(p1.top());
            p1.pop();
        }
    }
}

void inverte(std::queue<char>* f) {
    std::stack<char> p; // somente essa pilha e mais espaço auxiliar constante
    while (!f->empty()) {
        p.push(f->front());
        f->pop();
    }
    while (!p.empty()) {
        f->push(p.top());
        p.pop();
    }
}

void inverte5c(std::queue<char>* f) {
    std::queue<char> f1; // primeira fila auxiliar
    std::queue<char> f2; // segunda fila auxiliar
    // mais espaço auxiliar constante
    int size = f->size();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            f1.push(f->front());
            f->pop();
        }
        f2.push(f->front());
        f->pop();
        for (int j = 0; j < size - i - 1; j++) {
            f->push(f1.front());
            f1.pop();
        }
    }
    while (!f2.empty()) {
        f->push(f2.front());
        f2.pop();
    }
}

int avaliaPolonesaReversa(char expressao[], int valores[]) {
    int pilha[MAX_N];
    int n = 0;
    for (int i = 0; expressao[i] != '\0';i++) {
        char c = expressao[i];
        if (c >= 'A' && c <= 'Z') {
            pilha[n++] = valores[c - 'A'];
        } else {
            int b = pilha[n - 1];
            int a = pilha[n - 2];
            n = n - 2;
            if (c == '+') {
                pilha[n++] = a + b;
            } else if (c == '-') {
                pilha[n++] = a - b;
            } else if (c == '*') {
                pilha[n++] = a * b;
            } else {
                pilha[n++] = a / b;
            }
        }
    }
    return pilha[--n];
}

void polonesa(char expressao[], int N, char saida_polonesa[]) {
    int n = 0;
    char pilhaOperador[MAX_N];
    int nOperador = 0;
    for (int i = 0; i < N;i++) {
        char c = expressao[i];
        if (c >= 'A' && c <= 'Z') {
            saida_polonesa[n++] = c;
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            pilhaOperador[nOperador++] = c;
        } else if (c == ')') {
            saida_polonesa[n++] = pilhaOperador[--nOperador];
        }
    }
}

int main() {
    // std::cout << "\n--- TESTANDO DEQUE ---\n";
    // Deque meuDeque;
    // meuDeque.cria();
    //
    // meuDeque.insereFim('A');
    // meuDeque.insereFim('B');
    // meuDeque.insereInicio('C');
    // meuDeque.insereInicio('D');
    //
    // std::cout << "Inicio esperado: D | Obtido: " << meuDeque.inicio() << "\n";
    // std::cout << "Fim esperado:    B | Obtido: " << meuDeque.fim() << "\n";
    //
    // char remInicio = meuDeque.removeInicio();
    // std::cout << "Remove Inicio (Esperado: D) | Removido: " << remInicio << "\n";
    //
    // char remFim = meuDeque.removeFim();
    // std::cout << "Remove Fim    (Esperado: B) | Removido: " << remFim << "\n";
    //
    // meuDeque.libera(); // Obrigatório limpar a memória dinâmica!
    //
    //
    // std::cout << "\n--- TESTANDO PILHA DEQUE (LIFO) ---\n";
    // PilhaDeque minhaPilha;
    // minhaPilha.cria();
    //
    // minhaPilha.push('X');
    // minhaPilha.push('Y');
    // minhaPilha.push('Z');
    //
    // std::cout << "Topo esperado: Z | Obtido: " << minhaPilha.top() << "\n";
    // std::cout << "Desempilha (Esperado: Z) | Removido: " << minhaPilha.pop() << "\n";
    // std::cout << "Desempilha (Esperado: Y) | Removido: " << minhaPilha.pop() << "\n";
    //
    // minhaPilha.libera();
    //
    //
    // std::cout << "\n--- TESTANDO FILA DEQUE (FIFO) ---\n";
    // FilaDeque minhaFila;
    // minhaFila.cria();
    //
    // minhaFila.push('1');
    // minhaFila.push('2');
    // minhaFila.push('3');
    //
    // std::cout << "Frente esperada: 1 | Obtida: " << minhaFila.front() << "\n";
    // std::cout << "Desenfileira (Esperado: 1) | Removido: " << minhaFila.pop() << "\n";
    // std::cout << "Desenfileira (Esperado: 2) | Removido: " << minhaFila.pop() << "\n";
    //
    // minhaFila.libera();
    //
    // std::cout << "\n--- TESTANDO EXERCICIO 2: Pilha com 2 Filas ---\n";
    //
    // Pilha2F pilha;
    //
    // std::cout << "Empilhando 'A', 'B' e 'C'...\n";
    // pilha.push('A');
    // pilha.push('B');
    // pilha.push('C');
    //
    // // Numa pilha (LIFO), o último a entrar ('C') tem de ser o primeiro a sair.
    // std::cout << "Topo esperado: C | Obtido: " << pilha.top() << "\n";
    //
    // std::cout << "Desempilha (Esperado: C) | Removido: " << pilha.pop() << "\n";
    // std::cout << "Desempilha (Esperado: B) | Removido: " << pilha.pop() << "\n";
    //
    // std::cout << "Novo Topo esperado: A | Obtido: " << pilha.top() << "\n";
    //
    // std::cout << "Empilhando 'X'...\n";
    // pilha.push('X');
    // std::cout << "Novo Topo esperado: X | Obtido: " << pilha.pop() << "\n";
    //
    // std::cout << "Pilha liberada com sucesso!\n";
    //
    // std::cout << "\n--- TESTANDO EXERCICIO 3: Fila com 2 Pilhas ---\n";
    //
    // Fila2P fila;
    //
    // std::cout << "Enfileirando 'A', 'B' e 'C'...\n";
    // fila.push('A');
    // fila.push('B');
    // fila.push('C');
    //
    // // Numa fila (FIFO), o primeiro a entrar ('A') tem de ser o primeiro a sair.
    // std::cout << "Frente esperada: A | Obtida: " << fila.front() << "\n";
    //
    // std::cout << "Desenfileira (Esperado: A) | Removido: " << fila.pop() << "\n";
    // std::cout << "Desenfileira (Esperado: B) | Removido: " << fila.pop() << "\n";
    //
    // std::cout << "Nova Frente esperada: C | Obtida: " << fila.front() << "\n";
    //
    // std::cout << "Enfileirando 'D'...\n";
    // fila.push('D');
    // std::cout << "Nova Frente esperada: C | Obtida: " << fila.front() << "\n";
    //
    // std::stack<char> pilhaTest;
    //
    // pilhaTest.push('A');
    // pilhaTest.push('M');
    // pilhaTest.push('O');
    // pilhaTest.push('R');
    // pilhaTest.push('A');
    //
    // std::cout << "\n--- TESTANDO EXERCICIO 4: Pilha ---\n";
    //
    // imprimePilha(pilhaTest);
    // inverte4a(&pilhaTest);
    // imprimePilha(pilhaTest);
    // inverte4b(&pilhaTest);
    // imprimePilha(pilhaTest);
    // inverte4c(&pilhaTest);
    // imprimePilha(pilhaTest);
    //
    // std::cout << "\n--- TESTANDO EXERCICIO 5: Fila ---\n";
    //
    // std::queue<char> filaTest;
    //
    // filaTest.push('A');
    // filaTest.push('M');
    // filaTest.push('O');
    // filaTest.push('R');
    // filaTest.push('A');
    // imprimeFila(filaTest);
    // inverte(&filaTest);
    // imprimeFila(filaTest);
    // inverte5c(&filaTest);
    // imprimeFila(filaTest);
    //
    // PilhaMin pilhaMin;
    // pilhaMin.cria();
    // pilhaMin.push(10);
    // std::cout << pilhaMin.obterMinimo() << std::endl;
    // pilhaMin.push(8);
    // std::cout << pilhaMin.obterMinimo() << std::endl;
    // pilhaMin.push(9);
    // std::cout << pilhaMin.obterMinimo() << std::endl;
    // pilhaMin.push(7);
    // std::cout << pilhaMin.obterMinimo() << std::endl;
    // pilhaMin.push(1);
    // std::cout << pilhaMin.obterMinimo() << std::endl;
    // pilhaMin.push(7);
    // std::cout << pilhaMin.obterMinimo() << std::endl;
    // imprimePilhaMin(pilhaMin);
    // // Desempilhando ahora
    // std::cout << pilhaMin.obterMinimo() << std::endl;
    // pilhaMin.pop();
    // std::cout << pilhaMin.obterMinimo() << std::endl;
    // pilhaMin.pop();
    // std::cout << pilhaMin.obterMinimo() << std::endl;
    // pilhaMin.pop();
    // std::cout << pilhaMin.obterMinimo() << std::endl;
    // pilhaMin.pop();
    // std::cout << pilhaMin.obterMinimo() << std::endl;
    // pilhaMin.pop();
    // std::cout << pilhaMin.obterMinimo() << std::endl;
    // pilhaMin.pop();
    // pilhaMin.libera();
    //
    // std::cout << "\n--- TESTANDO EXERCICIO 7: Pilha Polonesa ---\n";
    //
    // int N = 5;
    // int valores[7] = {3, 3, 2, 1, 1}; // A=3, B=3, C=2, D=1, E=1
    //
    // char expressao[] = "AB+CED/-*";
    //
    // //int resultado = avaliaPolonesaReversa(expressao, valores);
    //
    // //std::cout << "Resultado da expressao RPN: " << resultado << std::endl;
    //
    // char expressaoParenteses[] = "((A+B)*(C-(F/D)))";
    // char saida_polonesa[50];
    // int N2 = sizeof(expressaoParenteses) - 1;
    // //polonesa(expressaoParenteses, N2, saida_polonesa);
    // std::cout << "Resultado da expressao RPN: " << saida_polonesa << std::endl;
    //
    // PegaEntreMaiores tad;
    // tad.cria();
    //
    // std::cout << "--- TESTE 8.a: Bubble sort com metodos extraas de exercicio adicional ---" << std::endl;
    // tad.insere(3);
    // tad.insere(1);
    // tad.insere(20);
    // tad.insere(5);
    // tad.insere(10);
    //
    // std::cout << "Total de elementos: " << tad.tamanho() << std::endl;
    //
    // // A ordem correta decrescente seria: Z, M, F, C, A
    // std::cout << "Maior elemento (esperado Z): " << tad.maior() << std::endl;
    // std::cout << "Segundo maior (esperado M): " << tad.segundomaior() << std::endl;
    // std::cout << "3o maior (esperado F): " << tad.kmaior(3) << std::endl;
    // std::cout << "5o maior (esperado A): " << tad.kmaior(5) << std::endl;

    std::cout << "\n--- TESTE 8.b: Insertion Sort ---" << std::endl;
    PegaEntreMaioresOrdernado tad2;
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

    tad2.libera();

    std::cout << "\n--- TESTE 8.c: Quick Sort  ---" << std::endl;
    PegaEntreMaioresQuickSort tad3;
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
    return 0;
}