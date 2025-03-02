//
// Created by Patrik on 3/1/2025.
//

#ifndef VECTORDINAMIC_H
#define VECTORDINAMIC_H

typedef void* TElem;

typedef struct {
    TElem* elemente;
    int lg;
    int capacitate;
}VectorDinamic;

VectorDinamic* creeazaVectorDinamic();

void distrugeVectorDinamic(VectorDinamic* vector_dinamic);

void resize(VectorDinamic* vector_dinamic);

void add(VectorDinamic* vector_dinamic, TElem el);

#endif //VECTORDINAMIC_H
