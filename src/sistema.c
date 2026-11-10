#include "../include/sistema.h"
#include "../include/interface.h"
#include <stdio.h>
#include <string.h>
#include "libprg/libprg.h"

void inicializar_sistema () {
    sistema_t sistema = {0};
    int opcao_menu, opcao_consultar_paciente, opcao_gerenciar_atendimento;

    abp_inicializar(&sistema.pacientes);
    lista_dupla_inicializar(&sistema.atendimentos);
    recuperar_info_pacientes(&sistema);

    do {
        inicializar_interface();
        scanf("%d", &opcao_menu);

        switch (opcao_menu) {
            case 1: {
                cadastrar_paciente(&sistema);
                break;
            }
            case 2: {
                consultar_paciente();
                scanf("%d", &opcao_consultar_paciente);
                if (opcao_consultar_paciente == 1) {
                    consultar_paciente_nome();
                } else if (opcao_consultar_paciente == 2) {
                    consultar_paciente_ID(&sistema);
                } else if (opcao_consultar_paciente == 0) {
                    break;
                }
            }
            case 3: {
                gerenciar_atendimentos();
                scanf("%d", &opcao_gerenciar_atendimento);
                if (opcao_gerenciar_atendimento == 1) {
                    agendar_atendimentos (&sistema);
                } else if (opcao_gerenciar_atendimento == 2) {
                    consultar_atendimentos (&sistema);
                } else if (opcao_gerenciar_atendimento == 3) {
                    cancelar_atendimentos (&sistema);
                } else if (opcao_gerenciar_atendimento == 4) {
                    alterar_atendimentos (&sistema);
                } else if (opcao_gerenciar_atendimento == 0) {
                    break;
                }
            }
        }
    } while (opcao_menu >= 0 && opcao_menu < 7);
    abp_libera(&sistema.pacientes);
    lista_dupla_libera(&sistema.atendimentos);
}


void recuperar_info_pacientes (sistema_t *sistema) { //recupera as info dos pacientes nos arquivos .txt e insere nas estruturas de dados do libprg
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
                abp_inserir(&sistema->pacientes, id);
            }
        }
        fclose(arquivo);
    }

void recuperar_info_funcionarios (sistema_t *sistema) { //recupera as info dos funcionarios nos arquivos .txt e insere nas estruturas de dados do libprg
    int id;
    char linha[300];

    FILE *arquivo = fopen("../dados/funcionarios.txt", "r");

    if (arquivo == NULL)
        return;

    while (fgets(linha, sizeof(linha), arquivo)) {
        if (sscanf(linha, "%d;", &id) == 1) {
            avl_inserir(&sistema->funcionarios, id);
        }
    }
    fclose(arquivo);
}
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

    if (abp_inserir(&sistema->pacientes, sistema->paciente[i].ID)) {
        sistema->quantidade_pacientes++;
        printf("PACIENTE CADASTRADO COM SUCESSO!\n");
    } else {
        printf("FALAHA AO CADASTRAR!\n");
    }
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
    int id;
    char linha[100];
    paciente_t paciente;

    printf("Digite o ID do paciente: \n");
    scanf("%d", &id);

    if (abp_buscar(sistema->pacientes, id)) {
        FILE *arquivo = fopen ("../dados/pacientes.txt", "r");

        if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo!\n");
            return;
        }
        while (fgets(linha, sizeof(linha), arquivo) != NULL) {
            if (sscanf(linha, "%d;%49[^;];%d;%19[^;];%99[^\n]",
                &paciente.ID,
                paciente.nome,
                &paciente.idade,
                paciente.data_nascimento,
                paciente.descricao) != 5) {
                }
            if (paciente.ID == id) {
                printf("===== PACIENTE ENCONTRADO =====\n\n");
                printf("ID: %d\n", paciente.ID);
                printf("Nome: %s\n", paciente.nome);
                printf("Idade: %d\n", paciente.idade);
                printf("Data de nascimento: %s\n", paciente.data_nascimento);
                printf("Problemas do paciente: %s\n", paciente.descricao);
                break;
            }
        }
        fclose(arquivo);
    } else {
        printf("PACIENTE NÃO ENCONTRADO!\n");
    }
}

void agendar_atendimentos (sistema_t *sistema) {
    printf("\n===== AGENDAR ATENDIMENTO =====\n\n");
    printf("Digite o ID do paciente: \n");

    printf("Digite o ID do funcionario: \n");
    printf("Digite uma data para o atendimento: \n");
    printf("Digite um horario para o atendimento: \n");


}

void consultar_atendimentos (sistema_t *sistema) {

}

void cancelar_atendimentos (sistema_t *sistema) {

}

void alterar_atendimentos (sistema_t *sistema) {


}