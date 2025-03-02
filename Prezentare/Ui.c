//
// Created by Patrik on 3/1/2025.
//

#include "Ui.h"
#include <stdio.h>


void afisareParticipant(Repository* repository) {
    VectorDinamic* vectorParticipanti = &repository->vectorParticipanti;
    if(vectorParticipanti->lg == 0) {
        printf("Nu exista participanti!\n");
        return;
    }
    for(int i = 0; i < vectorParticipanti->lg; i++) {
        Participant* participant = vectorParticipanti->elemente[i];
        printf("%s %s %.2f\n", participant->nume, participant->prenume, participant->scor);
    }
}

/*
 * Citeste de la tastatura nume, prenume si scor si apeleaza functia adaugaParticipant din Service
 * pre: -
 * post: -
 */
void uiAdaugaParticipant(Repository* repository) {
    char nume[20], prenume[20];
    float scor;
    printf("Nume: ");
    scanf("%19s", nume);
    printf("Prenume: ");
    scanf("%19s", prenume);
    printf("Scor: ");
    scanf("%f", &scor);
    int rez = adaugaParticipant(nume, prenume, scor, repository);
    if(rez == 0) {
        printf("Participantul nu a fost adaugat!\n");
        return;
    }
    printf("Participantul a fost adaugat cu succes!\n");
}

void uiModificaParticipant(Repository* repository) {
    char nume[20], prenume[20];
    float scor;
    printf("Nume: ");
    scanf("%s", nume);
    printf("Prenume: ");
    scanf("%s", prenume);
    printf("Scor: ");
    scanf("%f", &scor);
    int rez = modificaParticipant(nume, prenume, scor, repository);
    if(rez == 0) {
        printf("Participantul nu exista!\n");
        return;
    }
    printf("Participantul a fost modificat cu succes!\n");
}

void uiStergeParticipant(Repository* repository) {
    char nume[20], prenume[20];
    printf("Nume: ");
    scanf("%s", nume);
    printf("Prenume: ");
    scanf("%s", prenume);
    int rez = stergeParticipant(nume, prenume, repository);
    if(rez == 0) {
        printf("Participantul nu exista!\n");
        return;
    }
    printf("Participantul a fost sters cu succes!\n");
}

void uiFiltrareScor(Repository* repository) {
    float filtruScor = -1;
    printf("Filtru scor: ");
    scanf("%f", &filtruScor);
    VectorDinamic* participantiFiltrati = filtrareScor(filtruScor, repository);
    if(participantiFiltrati->lg == 0) {
        printf("Nu exista participanti care respecta filtrul!\n");
        return;
    }
    for(int i = 0; i < participantiFiltrati->lg; i++) {
        Participant* participant = participantiFiltrati->elemente[i];
        printf("%s %s %.2f\n", participant->nume, participant->prenume, participant->scor);
    }
}

void uiFiltrareNume(Repository* repository) {
    char filtruNume;
    printf("Filtru nume: ");
    scanf(" %c", &filtruNume);
    VectorDinamic* participantiFiltrati = filtrareNume(filtruNume, repository);
    if(participantiFiltrati->lg == 0) {
        printf("Nu exista participanti care respecta filtrul!\n");
        return;
    }
    for(int i = 0; i < participantiFiltrati->lg; i++) {
        Participant* participant = participantiFiltrati->elemente[i];
        printf("%s %s %.2f\n", participant->nume, participant->prenume, participant->scor);
    }
}

void uiSortareScor(Repository* repository) {
    char tip;
    printf("Tip(c/d): ");
    scanf(" %c", &tip);
    sortareScor(tip, repository);
    VectorDinamic* participantiSortati = &repository->vectorParticipanti;
    for(int i = 0; i < participantiSortati->lg; i++) {
        Participant* participant = participantiSortati->elemente[i];
        printf("%s %s %.2f\n", participant->nume, participant->prenume, participant->scor);
    }
}

void uiSortareNume(Repository* repository) {
    char tip;
    printf("Tip(c/d): ");
    scanf(" %c", &tip);
    sortareNume(tip, repository);
    VectorDinamic* participantiSortati = &repository->vectorParticipanti;
    for(int i = 0; i < participantiSortati->lg; i++) {
        Participant* participant = participantiSortati->elemente[i];
        printf("%s %s %.2f\n", participant->nume, participant->prenume, participant->scor);
    }
}

void run(Repository* repository) {
    VectorDinamic* vectorParticipanti = &repository->vectorParticipanti;
    int comanda;
    while(1) {
        printf("----------\nLista comenzi:\n----------\n1: Afisare participanti\n2: Adauga participant\n3: Modifica participant\n4: Sterge participant\n5: Filtrare scor\n6: Filtrare nume\n7: Sortare scor\n8: Sortare nume\n----------\n");
        printf("Comanda: ");
        scanf("%d", &comanda);
        switch(comanda) {
            case 1:
                afisareParticipant(repository);
                break;
            case 2:
                uiAdaugaParticipant(repository);
                break;
            case 3:
                uiModificaParticipant(repository);
                break;
            case 4:
                uiStergeParticipant(repository);
                break;
            case 5:
                uiFiltrareScor(repository);
                break;
            case 6:
                uiFiltrareNume(repository);
                break;
            case 7:
                uiSortareScor(repository);
                break;
            case 8:
                uiSortareNume(repository);
                break;
            default:
                printf("Comanda invalida!\n");
        }
    }
}