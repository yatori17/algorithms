//
// Created by 55219 on 05/10/2026.
//

#include "ex07.h"

#include <iostream>
#include <ostream>
#include <stack>

bool isOperator(char value) {
    return value == '+' || value == '-' || value == '*' || value == '/';
}

int applyOperator(int a, int b, char op) {
    switch (op) {
        case '+':
            return a + b;
            break;
        case '-':
            return a - b;
            break;
        case '*':
            return a * b;
            break;
        default:
            return a / b;
            break;
    }
}


// 7.b) Escreva um algoritmo que converte uma expressão aritmética parentizada usando as
// 4 operações para a expressão correspondente em notação polonesa reversa.

int avaliaRPN(char expressao[], int valores[]) {
    std::stack<int> q;
    for (int i = 0; expressao[i] != '\0'; i++) {
        char c = expressao[i];
        if (isOperator(c)) {
            int b = q.top();
            q.pop();
            int a = q.top();
            q.pop();
            q.push(applyOperator(a, b, c));
        } else {
            q.push(valores[c - 'A']);
        }
    }
    return q.top();
}

void polonesa(char expressao[], int N, char saidaPolonesa[]) {
    std::stack<char> operators;
    int n_saida = 0;
    for (int i = 0; i < N; i++) {
        char c = expressao[i];
        if (isOperator(c)) {
            operators.push(c);
        } else if (c >= 'A' && c <= 'Z') {
            saidaPolonesa[n_saida++] = c;
        } else if (c == ')') {
            saidaPolonesa[n_saida++] = operators.top();
            operators.pop();
        }
    }
    saidaPolonesa[n_saida] = '\0';

}

int main() {
    // Exemplo do enunciado:
    // N = 5 variáveis (A, B, C, D, E)
    // Valores dados: A=3, B=3, C=2, D=1, E=1
    int N = 5;
    int valores[7] = {3, 3, 2, 1, 1}; // A=3, B=3, C=2, D=1, E=1

    char expressao[] = "AB+CED/-*";

    int resultado = avaliaRPN(expressao, valores);

    std::cout << "Resultado da expressao RPN: " << resultado << std::endl;
    // Deve imprimir exatamente -4 conforme o exemplo do enunciado!

    char expressao2[] = "((A+B)*(C-(F/D)))";
    int N2 = sizeof(expressao) - 1;
    char saida_polonesa[50];

    polonesa(expressao, N2, saida_polonesa);

    std::cout << "Expressao Infixa: " << expressao << std::endl;
    std::cout << "Saida RPN gerada: " << saida_polonesa << std::endl;
    // Deve imprimir exatamente: AB+CFD/-*

    return 0;
}