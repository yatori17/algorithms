//
// Created by 55219 on 30/09/2026.
//

#ifndef WORKSPACE_EX01_H
#define WORKSPACE_EX01_H


class ex01 {
};

template<typename Agregado, typename Tipo>
concept DequeTAD = requires (Agregado a, Tipo t) {
    { a.inicio() };
    { a.fim() };
    { a.insereInicio(t) };
    { a.insereFim(t) };
    { a.removeInicio() };
    { a.removeFim() };
};

template<typename Agregado, typename Tipo>
concept PilhaTAD = requires (Agregado a, Tipo t) {
    { a.topo() };
    { a.empilha(t) };
    { a.desempilha() };
};

template<typename Agregado, typename Tipo>
concept FilaTAD = requires (Agregado a, Tipo t) {
    { a.frente() };
    { a.enfileira(t) };
    { a.desenfileira() };
};

struct Node {
    char value;
    Node* next;
    Node* prev;
};

struct Deque {
    Node* head = nullptr; // Obrigatório para começar limpo!
    Node* tail = nullptr; // Obrigatório para começar limpo!

    void cria() {
        head = tail = nullptr;
    }

    void libera() {
        while (head != nullptr) {
            removeInicio();
        }
    }

    char inicio() {
        return head->value;
    }

    char fim() {
        return tail->value;
    }

    void insereInicio(char value) {
        Node* newNode = new Node{value, nullptr, nullptr};
        if (!head) { // Verifica se é o primeiro elemento (essencial para sair do zero)
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insereFim(char value) {
        Node* newNode = new Node{value, nullptr, nullptr};
        if (!tail) { // Verifica se é o primeiro elemento (essencial para sair do zero)
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    char removeInicio() {
        char val = head->value;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr; // Se esvaziou, limpa o tail também
        return val;
    }

    char removeFim() {
        char val = tail->value;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr; // Se esvaziou, limpa o head também
        return val;
    }
};

struct PilhaDeque {
    // Cria - Libera - Tamanho - Empilha - Desempilha -- topo
    Deque deque;

    void cria() {
        deque.cria();
    }

    void libera() {
        deque.libera();
    }

    char topo() {
        return deque.fim();
    }

    void empilha(char val) {
        deque.insereFim(val);
    }

    char desempilha() {
        return deque.removeFim();
    }
};

struct FilaDeque {
    Deque deque;

    void cria() {
        deque.cria();
    }

    void libera() {
        deque.libera();
    }

    char frente() {
        return deque.inicio();
    }

    void enfileira(char value) {
        deque.insereFim(value);
    }

    char desenfileira() {
        return deque.removeInicio();
    }
};

static_assert(DequeTAD<Deque, char>);
static_assert(PilhaTAD<PilhaDeque, char>);
static_assert(FilaTAD<FilaDeque, char>);
#endif //WORKSPACE_EX01_H
