#include "sistema.h"
#include <stdio.h>
#include "libprg/libprg.h"

void cadastrar_paciente(sistema_t *cadastrar) {
    int i = cadastrar->quantidade_pacientes;
    printf("\n===== CADASTRO DE PACIENTES =====\n\n");

    printf("Digite o nome do paciente: ");
    scanf("%s", cadastrar->paciente[i].nome);

    printf("\nDigite a idade do paciente: ");
    scanf("%d", &cadastrar->paciente[i].idade);

    printf("\nDigite a data de nascimento do paciente: ");
    scanf("%s", cadastrar->paciente[i].data_nascimento);

    printf("\nDigite os problemas do paciente: ");
    scanf("%s", cadastrar->paciente[i].descricao);

    cadastrar->quantidade_pacientes++;

    printf("PACIENTE CADASTRADO COM SUCESSO!\n");
}