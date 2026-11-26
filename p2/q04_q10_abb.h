//
// Created by 55219 on 22/11/2026.
//

#ifndef P2_Q04_Q10_ABB_H
#define P2_Q04_Q10_ABB_H


class Questao04 {
};

struct NoBinChar {
    char chave;
    NoBinChar* esq;
    NoBinChar* dir;
};

// O(h)
void insere(char chave, NoBinChar* no) {
    if (no == nullptr) {
        return;
    }
    if (chave <= no -> chave) {
        if (no->esq) insere(chave, no->esq);
        else no->esq = new NoBinChar {chave, nullptr, nullptr};
    } else {
        if (no->dir) insere(chave, no->dir);
        else no->dir = new NoBinChar{chave, nullptr, nullptr};
    }
}

//5. Implemente um algoritmo que encontra o maior valor na árvore:
//char maior(NoBinChar* no);
//— Obs: considere somente letras maiúsculas, de B..X, e use o
//caractere ‘A’ como menor valor possível.

char maior(NoBinChar* no) {
    if (no == nullptr) return 'A';
    if (no->dir == nullptr) {
        return no->chave;
    }
    return maior(no->dir);
}
//6. Implemente um algoritmo que encontra o menor valor na árvore:
//char menor(NoBinChar* no);
//— Obs: considere somente letras maiúsculas, de B..X, e use o caractere ‘Z’
// como maior valor possível.

char menor(NoBinChar* no) {
    if (no == nullptr) return 'Z';
    if (no->esq == nullptr) {
        return no->chave;
    }
    return menor(no->esq);
}

// 7. Implemente um algoritmo que verifica se uma árvore é binária de busca:
bool ehBinariaAux(NoBinChar* no, char lower, char highest) {
    if (no == nullptr) return true;
    if (no->chave <= lower || no->chave >= highest) return false;
    return ehBinariaAux(no->esq, lower, no->chave) &&
        ehBinariaAux(no->dir, no->chave, highest);
}

bool ehBinariaBusca(NoBinChar* no) {
    return ehBinariaAux(no, 'A', 'Z');
}

// 8. Implemente um algoritmo que encontra um elemento em uma árvore binária de busca:
// char busca(char chave, NoBinChar* no);
// — Obs: retorne o caractere ‘\0’ caso nenhum seja encontrado.
char busca(char chave, NoBinChar* no) {
    if (no == nullptr) return '\0';
    if (no->chave == chave) return chave;
    if (chave > no->chave) return busca(chave, no->dir);
    return busca(chave, no->esq);
}

//9. Implemente um algoritmo que encontra o elemento imediatamente anterior a
//uma dada chave em uma árvore binária de busca: char anterior(char chave, NoBinChar* no);
char anterior(char chave, NoBinChar* no) {

    char resp = '\0';
    while (no != nullptr) {
        if (no->chave < chave) {
            resp = no->chave;
            no = no->dir;
        } else {
            no = no-> esq;
        }
    }
    return resp;
}

//10. Implemente um algoritmo que encontra o elemento imediatamente posterior a uma dada
//chave em uma árvore binária de busca: char posterior(char chave, NoBinChar* no);
char posterior(char chave, NoBinChar* no) {
    char resp = '\0';
    while (no != nullptr) {
        if (no->chave > chave) {
            resp = no->chave;
            no = no->esq;
        } else {
            no = no->dir;
        }
    }
    return resp;
}
#endif //P2_Q04_Q10_ABB_H
