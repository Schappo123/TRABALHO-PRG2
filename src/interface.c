#include <stdio.h>
#include "../include/sistema.h"

void inicializar_interface() {
    printf ("===== SISTEMA DE ATENDIMENTO - CERTEA =====\n\n");
    printf("1 - Cadastrar Paciente\n");
    printf("2 - Consultar Paciente\n");
    printf("3 - Agendar Atendimento\n");
    printf("4 - Gerenciar fila de espera\n");
    printf("5 - Consultar profissionais\n");
    printf("0 - Sair\n");
    printf("============================================\n");
    printf("Escolha uma opcao: ");
}

void consultar_paciente () {
    printf("===== CONSULTAR INFORMAÇÕES DO PACIENTE =====\n\n");
    printf("1 - Consultar pelo nome\n");
    printf("2 - Consultar pelo ID\n");
    printf("0 - Voltar\n");
    printf("============================================\n");
    printf("Escolha uma opcao: ");
}