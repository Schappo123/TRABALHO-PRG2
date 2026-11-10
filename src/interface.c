#include <stdio.h>
#include "../include/sistema.h"

void inicializar_interface() {
    printf ("===== SISTEMA DE ATENDIMENTO - CERTEA =====\n\n");
    printf("1 - Cadastrar Paciente\n");
    printf("2 - Consultar Paciente\n");
    printf("3 - Gerenciar Atendimentos\n");
    printf("4 - Gerenciar Fila de Espera\n");
    printf("5 - Consultar Profissionais\n");
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

void gerenciar_atendimentos () {
    printf("===== GERENCIAR ATENDIMENTOS =====\n\n");
    printf("1 - Agendar Atendimento\n");
    printf("2 - Consultar Atendimento\n");
    printf("3 - Cancelar Atendimento\n");
    printf("4 - Alterar Atendimento\n");
    printf("0 - Voltar\n");
    printf("============================================\n");
    printf("Escolha uma opcao: ");
}