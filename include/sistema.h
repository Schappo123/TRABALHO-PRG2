#ifndef TRABALHO_PRG2_SISTEMA_H
#define TRABALHO_PRG2_SISTEMA_H

typedef struct {
    char nome[50];
    int idade;
    char data_nascimento[20];
    char descricao[100];
}paciente_t;

typedef struct {
    char nome[50];
    int idade;
    char data_nascimento[20];
    char especialidade[50];
}funcionario_t;

typedef struct {
    paciente_t paciente[100];
    int quantidade_pacientes;
    funcionario_t funcionario[100];
    int quantidade_funcionarios;
} sistema_t;

void inicializar_sistema ();
void cadastrar_paciente(sistema_t *cadastrar);

#endif //TRABALHO_PRG2_SISTEMA_H