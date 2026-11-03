#include "../include/sistema.h"
#include "../include/interface.h"
#include <stdio.h>
#include <string.h>
#include "libprg/libprg.h"

void inicializar_sistema () {
    sistema_t sistema = {0};
    int opcao;
    ultimo_id_paciente(&sistema);

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
                }
            }
        }
        fclose(arquivo);
    }

void cadastrar_paciente(sistema_t *cadastrar) {
    int i = cadastrar->quantidade_pacientes;
    printf("\n===== CADASTRO DE PACIENTES =====\n\n");

    printf("Digite o nome do paciente: ");
    getchar(); // remove o "espaço" que fica no buffer.
    fgets(cadastrar->paciente[i].nome, 50, stdin);
    cadastrar->paciente[i].nome[strcspn(cadastrar->paciente[i].nome, "\n")] = '\0'; // remove o "\n" e "\0" do final do arquivo.

    printf("\nDigite a idade do paciente: ");
    scanf("%d", &cadastrar->paciente[i].idade);

    printf("\nDigite a data de nascimento do paciente: ");
    scanf("%19s", cadastrar->paciente[i].data_nascimento);

    getchar();
    printf("\nDigite os problemas do paciente: ");
    fgets(cadastrar->paciente[i].descricao, 100, stdin);
    cadastrar->paciente[i].descricao[strcspn(cadastrar->paciente[i].descricao, "\n")] = '\0';

    cadastrar->paciente[i].ID = i+1;

    FILE *arquivo = fopen ("../dados/pacientes.txt", "a");

    if (arquivo == NULL) {
        printf("\nErro ao abrir o arquivo!\n");
        return;
    }

    fprintf(arquivo, "%d;%s;%d;%s;%s\n",
    cadastrar->paciente[i].ID,
    cadastrar->paciente[i].nome,
    cadastrar->paciente[i].idade,
    cadastrar->paciente[i].data_nascimento,
    cadastrar->paciente[i].descricao);


    fclose(arquivo);

    cadastrar->quantidade_pacientes++;

    printf("PACIENTE CADASTRADO COM SUCESSO!\n");
}