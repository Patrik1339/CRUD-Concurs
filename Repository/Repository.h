//
// Created by Patrik on 3/1/2025.
//

#ifndef REPOSITORY_H
#define REPOSITORY_H
#include "../Repository/VectorDinamic.h"
#include "../Domeniu/Participant.h"


typedef struct {
    VectorDinamic vectorParticipanti;
    char* numeFisier;
}Repository;

Repository* creeazaRepository(char* numeFisier);

void distrugeRepository(Repository* repository);

void citesteFisier(Repository* repository);

void scrieFisier(Repository* repository);

#endif //REPOSITORY_H