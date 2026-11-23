#include <stdio.h>
#include "../include/sistema.h"

void inicializar_interface() {
    printf ("===== SISTEMA DE ATENDIMENTO - CERTEA =====\n\n");
    printf("1 - Cadastrar Paciente\n");
    printf("2 - Consultar Paciente\n");
    printf("3 - Gerenciar Atendimentos\n");
    printf("4 - Gerenciar Fila de Espera\n");
    printf("5 - Consultar Funcionarios\n");
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
    printf("0 - Voltar\n");
    printf("============================================\n");
    printf("Escolha uma opcao: ");
}

void gerenciar_fila_espera () {
    printf("===== GERENCIAR FILA DE ESPERA =====\n\n");
    printf("1 - Adicionar paciente a fila de espera\n");
    printf("2 - Chamar próximo paciente\n");
    printf("3 - Consultar fila de espera\n");
    printf("4 - Remover paciente da fila de espera\n");
    printf("0 - Voltar\n");
    printf("============================================\n");
    printf("Escolha uma opcao: ");
}