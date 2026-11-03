#include "../include/sistema.h"
#include "../include/interface.h"
#include <stdio.h>
#include <string.h>
#include "libprg/libprg.h"

void inicializar_sistema () {
    sistema_t sistema = {0};
    int opcao, opcao2;
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

    sistema->paciente[i].ID = i+1;

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

void consultar_paciente_nome(sistema_t *sistema) {

}

void consultar_paciente_ID(sistema_t *sistema) {

}