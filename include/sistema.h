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
    int ID;
    int ID_paciente;
    int ID_funcionario;
    char data[20];
    char horario[10];
    char status[20];
} atendimento_t;

typedef struct {
    paciente_t paciente[100];
    int quantidade_pacientes;
    int ultimo_id_pacientes;
    abp_t pacientes;

    funcionario_t funcionario[100];
    avl_t funcionarios;

    atendimento_t atendimento[100];
    int quantidade_atendimentos;
    int ultimo_id_atendimentos;
    lista_dupla_t atendimentos;

    fila_t *fila_espera;
} sistema_t;

void inicializar_sistema ();
void recuperar_info_pacientes (sistema_t *sistema);
void recuperar_info_funcionarios (sistema_t *sistema);
void recuperar_info_atendimentos (sistema_t *sistema);
void recuperar_info_fila_espera (sistema_t *sistema);

void cadastrar_paciente(sistema_t *sistema);

void consultar_paciente_nome();
void consultar_paciente_ID(sistema_t *sistema);

void agendar_atendimentos (sistema_t *sistema);
void buscar_nome_paciente(int id_paciente, char nome[]);
void buscar_nome_funcionario(int id_funcionario, char nome[]);
void consultar_atendimentos (sistema_t *sistema);
void cancelar_atendimentos (sistema_t *sistema);

void adicionar_paciente_fila_espera (sistema_t *sistema);
void chamar_proximo_paciente (sistema_t *sistema);
void consultar_fila_espera (sistema_t *sistema);
void remover_paciente_fila_espera (sistema_t *sistema);

#endif //TRABALHO_PRG2_SISTEMA_H