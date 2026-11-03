#include <stdio.h>
#include "src/sistema.h"
#include "src/interface.h"

int main() {

    sistema_t sistema = {0};
    int opcao;
    do {
        inicializar_interface();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                cadastrar_paciente(&sistema);
                break;
            }
        }
    } while (opcao >= 0 && opcao < 7);

    return 0;
}