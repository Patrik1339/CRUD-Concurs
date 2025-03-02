//
// Created by Patrik on 3/1/2025.
//

#include "VectorDinamic.h"
#include <stdlib.h>
#include "../Domeniu/Participant.h"

/*
 * Creeaza un vector dinamic gol, cu capacitate de un element de tip TElem
 * pre:-
 * post: Este creat un vector dinamic
 * return: VectorDinamic*
 */
VectorDinamic* creeazaVectorDinamic(char* numeFisier) {
    VectorDinamic* vector_dinamic = malloc(sizeof(VectorDinamic));
    vector_dinamic->capacitate = 1;
    vector_dinamic->lg = 0;
    vector_dinamic->elemente = malloc(sizeof(TElem));
    return vector_dinamic;
}

/*
 * Dealoca memoria rezervata pentru un vector dinamic
 * pre: vector_dinamic este de tipul VectorDinamic* si exista
 * post: Este dealocata memoria rezervata pentru vector_dinamic
 */
void distrugeVectorDinamic(VectorDinamic* vector_dinamic) {
    for(int i = 0; i < vector_dinamic->lg; i++) {
        Participant* participant = vector_dinamic->elemente[i];
        distrugeParticipant(participant);
    }
    free(vector_dinamic->elemente);
    free(vector_dinamic);
}

/*
 * Dubleaza capacitate unui vector dinamic
 * pre: vector_dinamic este de tipul VectorDinamic*
 * post: Capacitatea vectorului dinamic este dublata
 */
void resize(VectorDinamic* vector_dinamic) {
    int nCap = 2 * vector_dinamic->capacitate;
    TElem* nElemente = malloc(nCap * sizeof(TElem));
    for(int i = 0; i < vector_dinamic->lg; i++)
        nElemente[i] = vector_dinamic->elemente[i];
    free(vector_dinamic->elemente);
    vector_dinamic->elemente = nElemente;
    vector_dinamic->capacitate = nCap;
}

/*
 * Adauga elementul el in vectorul dinamic vector_dinamic
 * pre: vector_dinamic este de tipul VectorDinamic*; el este de tipul TElem
 * post: Elementul el este adaugat la sfarsitul vectorului dinamic, iar lungimea lg este incrementata cu 1
 */
void add(VectorDinamic* vector_dinamic, TElem el) {
    if(vector_dinamic->lg == vector_dinamic->capacitate)
        resize(vector_dinamic);
    vector_dinamic->elemente[vector_dinamic->lg] = el;
    vector_dinamic->lg++;
}