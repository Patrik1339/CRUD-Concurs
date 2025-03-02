//
// Created by Patrik on 3/1/2025.
//

#ifndef SERVICE_H
#define SERVICE_H
#include "../Repository/Repository.h"

int adaugaParticipant(char* nume, char* prenume, float scor, Repository* repository);

int modificaParticipant(char* nume, char* prenume, float scor, Repository* repository);

int stergeParticipant(char* nume, char* prenume, Repository* repository);

VectorDinamic* filtrareScor(float filtruScor, Repository* repository);

VectorDinamic* filtrareNume(char filtruNume, Repository* repository);

void sortareScor(char tip, Repository* repository);

void sortareNume(char tip, Repository* repository);

#endif //SERVICE_H
