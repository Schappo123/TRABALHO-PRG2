#include "../include/sistema.h"
#include "../include/interface.h"
#include <stdio.h>
#include <string.h>
#include "libprg/libprg.h"

void inicializar_sistema () {
    sistema_t sistema = {0};
    int opcao, opcao2;

    abp_inicializar(&sistema.pacientes);
    ultimo_id_paciente(&sistema);

    do {
        inicializar_interface();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                cadastrar_paciente(&sistema);
                break;
            }
            case 2: {
                consultar_paciente();
                scanf("%d", &opcao2);
                if (opcao2 == 1) {
                    consultar_paciente_nome();
                } else if (opcao2 == 2) {
                    consultar_paciente_ID(&sistema);
                } else if (opcao2 == 0) {
                    break;
                }
            }
        }
    } while (opcao >= 0 && opcao < 7);
    abp_libera(&sistema.pacientes);
}

void ultimo_id_paciente (sistema_t *sistema) {
        int id;
        char linha[300];

        FILE *arquivo = fopen("../dados/pacientes.txt", "r");

        sistema->quantidade_pacientes = 0;
        sistema->ultimo_id = 0;

        if (arquivo == NULL)
            return;

        while (fgets(linha, sizeof(linha), arquivo)) {
            if (sscanf(linha, "%d;", &id) == 1) {
                sistema->quantidade_pacientes++;

                if (id > sistema->ultimo_id) {
                    sistema->ultimo_id = id;

                    abp_inserir(&sistema->pacientes, id);
                }
            }
        }
        fclose(arquivo);
    }

void cadastrar_paciente(sistema_t *sistema) {
    int i = sistema->quantidade_pacientes;
    printf("\n===== CADASTRO DE PACIENTES =====\n\n");

    printf("Digite o nome do paciente: ");
    getchar(); // remove o "espaço" que fica no buffer.
    fgets(sistema->paciente[i].nome, 50, stdin);
    sistema->paciente[i].nome[strcspn(sistema->paciente[i].nome, "\n")] = '\0'; // remove o "\n" e "\0" do final do arquivo.

    printf("\nDigite a idade do paciente: ");
    scanf("%d", &sistema->paciente[i].idade);

    printf("\nDigite a data de nascimento do paciente: ");
    scanf("%19s", sistema->paciente[i].data_nascimento);

    getchar();
    printf("\nDigite os problemas do paciente: ");
    fgets(sistema->paciente[i].descricao, 100, stdin);
    sistema->paciente[i].descricao[strcspn(sistema->paciente[i].descricao, "\n")] = '\0';

    sistema->paciente[i].ID = ++sistema->ultimo_id;

    if (abp_inserir(&sistema->pacientes, sistema->paciente[i].ID)) {
        printf("PACIENTE CADASTRADO COM SUCESSO!\n");
    }


    FILE *arquivo = fopen ("../dados/pacientes.txt", "a");

    if (arquivo == NULL) {
        printf("\nErro ao abrir o arquivo!\n");
        return;
    }

    fprintf(arquivo, "%d;%s;%d;%s;%s\n",
    sistema->paciente[i].ID,
    sistema->paciente[i].nome,
    sistema->paciente[i].idade,
    sistema->paciente[i].data_nascimento,
    sistema->paciente[i].descricao);


    fclose(arquivo);

    sistema->quantidade_pacientes++;

    printf("PACIENTE CADASTRADO COM SUCESSO!\n");
}

void consultar_paciente_nome() {
    char nome[50];
    char linha[100];
    paciente_t paciente;
    int encontrado = 0;

    printf("Digite o nome do paciente buscado: \n");
    getchar();
    fgets(nome, 50, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    FILE *arquivo = fopen ("../dados/pacientes.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        sscanf (linha, "%d;%49[^;];%d;%19[^;];%99[^\n]",
        &paciente.ID,
        paciente.nome,
        &paciente.idade,
        paciente.data_nascimento,
        paciente.descricao);

        if (strcmp (nome, paciente.nome) == 0) {
            printf("===== PACIENTE ENCONTRADO =====\n\n");
            printf("ID: %d\n", paciente.ID);
            printf("Nome: %s\n", paciente.nome);
            printf("Idade: %d\n", paciente.idade);
            printf("Data de nascimento: %s\n", paciente.data_nascimento);
            printf("Problemas do paciente: %s\n", paciente.descricao);

            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("PACIENTE NÃO ENCONTRADO!\n");
    }
    fclose(arquivo);
}

void consultar_paciente_ID(sistema_t *sistema) {

}