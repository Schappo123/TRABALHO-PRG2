#ifndef TRABALHO_PRG2_SISTEMA_H
#define TRABALHO_PRG2_SISTEMA_H

#include "libprg/libprg.h"

typedef struct {
    int ID;
    char nome[50];
    int idade;
    char data_nascimento[20];
    char descricao[100];
}paciente_t;

typedef struct {
    int ID;
    char nome[50];
    char especialidade[50];
}funcionario_t;

typedef struct {
    paciente_t paciente[100];
    int quantidade_pacientes;
    funcionario_t funcionario[100];
    int quantidade_funcionarios;
    int ultimo_id;
    abp_t pacientes;
} sistema_t;

void inicializar_sistema ();
void ultimo_id_paciente (sistema_t *sistema);
void cadastrar_paciente(sistema_t *sistema);
void consultar_paciente_nome();
void consultar_paciente_ID(sistema_t *sistema);

#endif //TRABALHO_PRG2_SISTEMA_H