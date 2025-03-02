//
// Created by Patrik on 3/1/2025.
//

#ifndef UI_H
#define UI_H
#include "../Repository/Repository.h"
#include "../Controller/Service.h"
#include "../Domeniu/Participant.h"

void uiAdaugaParticipant(Repository* repository);

void uiModificaParticipant(Repository* repository);

void uiStergeParticipant(Repository* repository);

void uiFiltrareScor(Repository* repository);

void uiFiltrareNume(Repository* repository);

void uiSortareScor(Repository* repository);

void uiSortareNume(Repository* repository);

void run(Repository* repository);

#endif //UI_H
