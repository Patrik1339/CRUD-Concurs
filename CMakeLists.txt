cmake_minimum_required(VERSION 3.30)
project(Concurs_de_programare_c C)

set(CMAKE_C_STANDARD 11)

add_executable(Concurs_de_programare_c main.c
        Domeniu/Participant.c
        Domeniu/Participant.h
        Teste/Teste.c
        Teste/Teste.h
        Repository/Repository.c
        Repository/Repository.h
        Controller/Service.c
        Controller/Service.h
        Prezentare/Ui.c
        Prezentare/Ui.h
        Repository/VectorDinamic.c
        Repository/VectorDinamic.h)
