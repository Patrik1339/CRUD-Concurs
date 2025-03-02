//
// Created by Patrik on 3/1/2025.
//

#include "Participant.h"
#include <stdlib.h>
#include <string.h>

/*
 * Creeaza un participant cu numele nume, prenumele prenume si scorul scor
 * pre: nume si prenume trebuie sa fie char*; scor trebuie sa fie float
 * post: praticipant este o structura de tip Participant
 * return: pointer catre participant
 */
Participant* creeazaParticipant(char* nume, char* prenume, float scor) {
    Participant* participant = (Participant*)malloc(sizeof(Participant));
    participant->nume = (char*)malloc(strlen(nume) + 1);
    strcpy(participant->nume, nume);
    participant->prenume = (char*)malloc(strlen(prenume) + 1);
    strcpy(participant->prenume, prenume);
    participant->scor = scor;
    return participant;
}

/*
 * Dealoca spatiul rezervat pentru participant
 * pre: participant este de tipul participant* si exista
 * post: participant este eliberat de pe heap
 */
void distrugeParticipant(Participant* participant) {
    free(participant->nume);
    free(participant->prenume);
    free(participant);
}

/*
 * Valideaza un participant
 * pre: participant este de tipul Participant*
 * post: -
 * return: un numar intreg din intervalul [0,3] ce reprezinta numarul de erori
 */
int validareParticipant(Participant* participant) {
    int nrErori = 0;
    if(participant->nume == NULL || strlen(participant->nume) == 0) nrErori++;
    if(participant->prenume == NULL || strlen(participant->prenume) == 0) nrErori++;
    if(participant->scor <= 0) nrErori++;
    return nrErori;
}