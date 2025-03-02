//
// Created by Patrik on 3/1/2025.
//

#ifndef PARTICIPANT_H
#define PARTICIPANT_H

typedef struct {
    char* nume;
    char* prenume;
    float scor;
}Participant;

Participant* creeazaParticipant(char* nume, char* prenume, float scor);

void distrugeParticipant(Participant* participant);

int validareParticipant(Participant* participant);

#endif //PARTICIPANT_H