//
// Created by Patrik on 3/1/2025.
//

#include "Repository.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 * Creeaza un vector dinamic gol, cu capacitate de un element de tip TElem
 * pre:-
 * post: Este creat un vector dinamic
 * return: VectorDinamic*
 */
Repository* creeazaRepository(char* numeFisier) {
    Repository* repository = malloc(sizeof(Repository));
    repository->vectorParticipanti = *creeazaVectorDinamic();
    repository->numeFisier = malloc(sizeof(char) * (strlen(numeFisier) + 1));
    strcpy(repository->numeFisier, numeFisier);
    citesteFisier(repository);
    return repository;
}

/*
 * Dealoca memoria rezervata pentru un vector dinamic
 * pre: vector_dinamic este de tipul VectorDinamic* si exista
 * post: Este dealocata memoria rezervata pentru vector_dinamic
 */
void distrugeRepository(Repository* repository) {
    distrugeVectorDinamic(&repository->vectorParticipanti);
    free(repository->numeFisier);
    free(repository);
}

/*
 * Citeste participantii din fisier si ii adauga in vector
 */
void citesteFisier(Repository* repository) {
    FILE* ptrFisier = fopen(repository->numeFisier, "r");
    if(ptrFisier == NULL) {
        perror("Fisierul nu a fost gasti!\n");
        return;
    }
    while(1) {
        Participant* participant = malloc(sizeof(Participant));
        participant->nume = malloc(20 * sizeof(char));
        participant->prenume = malloc(20 * sizeof(char));
        if(fscanf(ptrFisier, "%s %s %f", participant->nume, participant->prenume, &participant->scor) != 3) {
            distrugeParticipant(participant);
            break;
        }
        add(&repository->vectorParticipanti, participant);
    }
    fclose(ptrFisier);
}

/*
 * Scrie participantii din vector in fisier
 */
void scrieFisier(Repository* repository) {
    FILE* ptrFisier = fopen(repository->numeFisier, "w");
    VectorDinamic* vector_dinamic = &repository->vectorParticipanti;
    if(ptrFisier == NULL) {
        perror("Fisierul nu a fost gasit!\n");
        return;
    }
    for(int i = 0; i < vector_dinamic->lg; i++) {
        Participant* participant = vector_dinamic->elemente[i];
        fprintf(ptrFisier, "%s %s %f\n", participant->nume, participant->prenume, participant->scor);
    }
    fclose(ptrFisier);
}