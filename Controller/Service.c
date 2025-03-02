//
// Created by Patrik on 3/1/2025.
//

#include "Service.h"
#include "../Domeniu/Participant.h"
#include <stdio.h>
#include <string.h>

/*
 * Verifica daca participantul este valid si in caz afirmativ il adauga in vector
 * pre: nume si prenume sunt de tipul char*; scor este de tipul float ;vector_dinamic este de tipul VectorDinamic*
 * post: Daca participantul este valid, acesta este adaugat in vectorul dinamic si returneaza 1, daca nu returneaza 0
 * return: 1 daca participantul este valid, 0 altfel
 */
int adaugaParticipant(char* nume, char* prenume, float scor, Repository* repository) {
    VectorDinamic* vectorParticipanti = &repository->vectorParticipanti;
    Participant* participant = creeazaParticipant(nume, prenume, scor);
    int rez = validareParticipant(participant);
    if(rez != 0) return 0;
    add(vectorParticipanti, participant);
    scrieFisier(repository);
    return 1;
}

/*
 * Modifica scorul participantului cu numele nume si prenumele prenume
 * return: 1 daca participantul exista in vector, 0 altfel
*/
int modificaParticipant(char* nume, char* prenume, float scor, Repository* repository) {
    VectorDinamic* vectorParticipanti = &repository->vectorParticipanti;
    for(int i = 0; i <vectorParticipanti->lg; i++) {
        Participant* participant = vectorParticipanti->elemente[i];
        if(strcmp(participant->nume, nume) == 0 && strcmp(participant->prenume, prenume) == 0) {
            participant->scor = scor;
            scrieFisier(repository);
            return 1;
        }
    }
    return 0;
}

/*
 * Sterge participantul cu numele nume si prenumele prenume si returneaza 1 daca participantul a fost sters, 0 altfel
 * pre: nume si prenume trebuie sa fie de tipul char*; repository trebuie sa fie de tipul Repository*
 * post: -
 * return: 1 daca participantul a fost sters, 0 altfel
 */
int stergeParticipant(char* nume, char* prenume, Repository* repository) {
    VectorDinamic* vectorParticipanti = &repository->vectorParticipanti;
    for(int i = 0; i <vectorParticipanti->lg; i++) {
        Participant* participant = vectorParticipanti->elemente[i];
        if(strcmp(participant->nume, nume) == 0 && strcmp(participant->prenume, prenume) == 0) {
            for(int j = i; j < vectorParticipanti->lg - 1; j++)
                vectorParticipanti->elemente[j] = vectorParticipanti->elemente[j + 1];
            vectorParticipanti->lg--;
            scrieFisier(repository);
            return 1;
        }
    }
    return 0;
}

/*
 * Filtreaza vectorul de participanti si returneaza vectorul filtrat cu participantii care au scorul < filtruScor
 * pre: filtruScor trebuie sa fie de tipul float; repository trebuie sa fie de tipul Repository*
 * post: -
 * return: Vector de participanti filtrat, cu participanti care au scorul < filtruScor
 */
VectorDinamic* filtrareScor(float filtruScor, Repository* repository) {
    VectorDinamic* vectorParticipanti = &repository->vectorParticipanti;
    VectorDinamic* participantiFiltrati = creeazaVectorDinamic();
    for(int i = 0; i < vectorParticipanti->lg; i++) {
        Participant* participant = vectorParticipanti->elemente[i];
        if(participant->scor < filtruScor)
            add(participantiFiltrati, participant);
    }
    return participantiFiltrati;
}

/*
 * Filtreaza vectorul de participanti si returneaza vectorul filtrat cu participantii carora numele
 * are prima litera == filtruNume
 * pre: filtruNume trebuie sa fie de tipul char; repository trebuie sa fie de tipul Repository*
 * post: -
 * return: Vector de participanti filtrat, cu participanti carora numele are prima litera == filtruNume
 */
VectorDinamic* filtrareNume(char filtruNume, Repository* repository) {
    VectorDinamic* vectorParticipanti = &repository->vectorParticipanti;
    VectorDinamic* participantiFiltrati = creeazaVectorDinamic();
    for(int i = 0; i < vectorParticipanti->lg; i++) {
        Participant* participant = vectorParticipanti->elemente[i];
        if(participant->nume[0] == filtruNume)
            add(participantiFiltrati, participant);
    }
    return participantiFiltrati;
}

/*
 * Filtreaza vectorul de participanti dupa scor: crescator daca tip == 'c' si descrescator daca tip == 'd'
 * pre: tip trebuie sa fie de tip char; repository trebuie sa fie de tip Repository*
 * post:-
 */
void sortareScor(char tip, Repository* repository) {
    VectorDinamic* vectorParticipanti = &repository->vectorParticipanti;
    for(int i = 0; i < vectorParticipanti->lg - 1; i++) {
        Participant* participant_i = vectorParticipanti->elemente[i];
        for(int j = i + 1; j < vectorParticipanti->lg; j++) {
            Participant* participant_j = vectorParticipanti->elemente[j];
            if(tip == 'c' && participant_i->scor > participant_j->scor || tip == 'd' && participant_i->scor < participant_j->scor) {
                Participant* participant_aux = vectorParticipanti->elemente[i];
                vectorParticipanti->elemente[i] = vectorParticipanti->elemente[j];
                vectorParticipanti->elemente[j] = participant_aux;
            }
        }
    }
}

/*
 * Sorteaza vectorul de participanti dupa nume: crescator daca tip == 'c' si descrescator daca tip == 'd'
 * pre: tip trebuie sa fie de tip char; repository trebuie sa fie de tip Repository*
 * post:-
 */
void sortareNume(char tip, Repository* repository) {
    VectorDinamic* vector_dinamic = &repository->vectorParticipanti;
    for(int i = 0; i < vector_dinamic->lg - 1; i++) {
        Participant* participant_i = vector_dinamic->elemente[i];
        for(int j = i + 1; j < vector_dinamic->lg; j++) {
            Participant* participant_j = vector_dinamic->elemente[j];
            if(tip == 'c' && strcmp(participant_i->nume, participant_j->nume) > 0 || tip == 'd' && strcmp(participant_i->nume, participant_j->nume) < 0) {
                Participant* participant_aux = vector_dinamic->elemente[i];
                vector_dinamic->elemente[i] = vector_dinamic->elemente[j];
                vector_dinamic->elemente[j] = participant_aux;
            }
        }
    }
}