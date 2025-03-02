//
// Created by Patrik on 3/1/2025.
//

#include "Teste.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <tgmath.h>

#include "../Controller/Service.h"
#include "../Domeniu/Participant.h"
#include "../Repository/Repository.h"
#include "../Repository/VectorDinamic.h"


//Test pentru crearea unui participant si validare
void testParticipant() {
    char* nume = "John";
    char* prenume = "Doe";
    float scor = 7.5;
    float epsilon = 0.0001;
    Participant* participant = creeazaParticipant(nume, prenume, scor);
    assert(strcmp(participant->nume, nume) == 0);
    assert(strcmp(participant->prenume, prenume) == 0);
    assert(fabs(participant->scor - scor) <= epsilon);
    Participant* participantInvalid = creeazaParticipant("", "", -1);
    assert(validareParticipant(participantInvalid) == 3);
    distrugeParticipant(participant);
    distrugeParticipant(participantInvalid);
}

//Testeaza functiile CRUD
void testCRUD() {
    Repository* repository = creeazaRepository("../Teste/teste.txt");
    VectorDinamic* vectorParticipanti = &repository->vectorParticipanti;
    assert(vectorParticipanti->lg == 2);
    char nume[20] = "John", prenume[20] = "Doe";
    float scor = 7.5, epsilon = 0.0001;
    Participant* participant = vectorParticipanti->elemente[0];
    assert(strcmp(participant->nume, nume) == 0);
    assert(strcmp(participant->prenume, prenume) == 0);
    assert(fabs(participant->scor - 7.5) <= epsilon);
    int rez = adaugaParticipant("John", "Doe2", 8.8, repository);
    assert(vectorParticipanti->lg == 3);
    participant = vectorParticipanti->elemente[2];
    assert(strcmp(participant->nume, nume) == 0);
    assert(strcmp(participant->prenume, "Doe2") == 0);
    assert(fabs(participant->scor - 8.8) <= epsilon);
    modificaParticipant("John", "Doe2", 1.2, repository);
    assert(fabs(participant->scor - 1.2) <= epsilon);
    stergeParticipant("John", "Doe2", repository);
    assert(vectorParticipanti->lg == 2);
    distrugeParticipant(participant);
}

//Testeaza functiile de filtrare
void testFiltrari() {
    float epsilon = 0.0001;
    Repository* repository = creeazaRepository("../Teste/teste.txt");
    VectorDinamic* vectorAsteptat = creeazaVectorDinamic();
    Participant* participant = creeazaParticipant("John", "Doe", 7.5);
    add(vectorAsteptat, participant);
    VectorDinamic* vectorFiltratScor = filtrareScor(8, repository);
    assert(vectorAsteptat->lg == vectorFiltratScor->lg);
    Participant* participantVector = vectorFiltratScor->elemente[0];
    assert(strcmp(participant->nume, participantVector->nume) == 0);
    assert(strcmp(participant->prenume, participant->prenume) == 0);
    assert(fabs(participant->scor - participantVector->scor) <= epsilon);
    VectorDinamic* vectorFiltratNume = filtrareNume('P', repository);
    assert(vectorAsteptat->lg == vectorFiltratNume->lg);
    Participant* participantVector2 = vectorFiltratNume->elemente[0];
    assert(strcmp(participantVector2->nume, "Part") == 0);
    assert(strcmp(participantVector2->prenume, "icipant") == 0);
    assert(fabs(participantVector2->scor - 9.94) <= epsilon);
    distrugeParticipant(participant);
    distrugeParticipant(participantVector);
    distrugeParticipant(participantVector2);
}


//Ruleaza toate testele
void ruleazaTestele() {
    testParticipant();
    testCRUD();
    testFiltrari();
}