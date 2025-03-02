#include <stdio.h>

#include "Prezentare/Ui.h"
#include "Teste/Teste.h"

int main(void) {
    ruleazaTestele();
    Repository* repository = creeazaRepository("../Repository/fisier.txt");
    run(repository);
    return 0;
}
