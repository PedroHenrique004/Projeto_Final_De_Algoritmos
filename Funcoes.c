#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tarefa {
    int id;
    char Nome[50];
    char Dificuldade[20];
    char Status[20];
} Tarefa;

typedef struct listaDeTarefas {
    Tarefa *tarefas;
    int posicaoAtual;
    int capacidade;
} Lista;

void inicializarLista(Lista *l) {
    l->capacidade = 10;
    l->tarefas = (Tarefa*)calloc(l->capacidade, sizeof(Tarefa));
    l->posicaoAtual = 0;
}

void redimensionarLista(Lista *l) {
    if (l->posicaoAtual == l->capacidade) {
        l->capacidade *= 2; 
        l->tarefas = (Tarefa*)realloc(l->tarefas, l->capacidade * sizeof(Tarefa));
    }
}

void inserir_nova_tarefa(Lista *l) {
    redimensionarLista(l); 

    printf("\nDigite o nome da tarefa em ate 50 caracteres:");
    scanf(" %49[^\n]", l->tarefas[l->posicaoAtual].Nome);

    printf("Digite a dificuldade da tarefa, sendo:\n");
    printf("1 - Facil\n");
    printf("2 - Media\n");
    printf("3 - Dificil\n");
    int dificuldade;
    scanf("%d", &dificuldade);
    while (dificuldade < 1 || dificuldade > 3) {
        printf("Dificuldade invalida! Digite novamente:\n");
        scanf("%d", &dificuldade);
    }
    strcpy(l->tarefas[l->posicaoAtual].Dificuldade, dificuldade == 1 ? "Facil" : dificuldade == 2 ? "Media" : "Dificil");

    printf("Digite o status da tarefa, sendo:\n");
    printf("1 - Nao concluida\n");
    printf("2 - Concluida\n");
    int status;
    scanf("%d", &status);
    while (status < 1 || status > 2) {
        printf("Status invalido! Digite novamente:\n");
        scanf("%d", &status);
    }
    strcpy(l->tarefas[l->posicaoAtual].Status, status == 1 ? "Nao concluida" : "Concluida");

    l->tarefas[l->posicaoAtual].id = l->posicaoAtual + 1;
    l->posicaoAtual++;

    printf("\nTarefa inserida com sucesso!\n");
}

void mostrar_tarefas_cadastradas(Lista *l) {
    if (l->posicaoAtual == 0) {
        printf("\nNenhuma tarefa cadastrada.\n");
        return;
    }

    printf("\nTarefas cadastradas:\n");
    for (int i = 0; i < l->posicaoAtual; i++) {
        printf("\nTarefa %d:\n", l->tarefas[i].id);
        printf("Nome: %s\n", l->tarefas[i].Nome);
        printf("Dificuldade: %s\n", l->tarefas[i].Dificuldade);
        printf("Status: %s\n", l->tarefas[i].Status);
    }
}

void buscar_por_tarefa(Lista *l) {
    char termo[50];
    printf("Digite o nome da tarefa a ser buscada: ");
    scanf(" %49[^\n]", termo);

    int encontrada = 0;
    for (int i = 0; i < l->posicaoAtual; i++) {
        if (strstr(l->tarefas[i].Nome, termo) != NULL) {
            printf("\nTarefa %d:\n", l->tarefas[i].id);
            printf("Nome: %s\n", l->tarefas[i].Nome);
            printf("Dificuldade: %s\n", l->tarefas[i].Dificuldade);
            printf("Status: %s\n", l->tarefas[i].Status);
            encontrada = 1;
        }
    }

    if (!encontrada) {
        printf("Nenhuma tarefa encontrada com o termo '%s'.\n", termo);
    }
}


void editar_informacoes_de_uma_tarefa(Lista *l) {
    int numero, opcao;
    printf("\nDigite o numero da tarefa que voce quer editar:\n");
    for (int i = 0; i < l->posicaoAtual; i++) {
        printf("Tarefa %d: %s\n", l->tarefas[i].id, l->tarefas[i].Nome);
    }
    scanf("%d", &numero);

    Tarefa *tarefa = NULL;
    for (int i = 0; i < l->posicaoAtual; i++) {
        if (l->tarefas[i].id == numero) {
            tarefa = &l->tarefas[i];
            break;
        }
    }

    if (tarefa == NULL) {
        printf("\nTarefa nao encontrada.\n");
        return;
    }

    printf("\nO que voce quer editar na tarefa %d?\n", numero);
    printf("1. Nome\n");
    printf("2. Dificuldade\n");
    printf("3. Status\n");
    printf("4. Voltar\n");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("\nDigite o novo nome da tarefa em ate 50 caracteres:\n");
            scanf(" %49[^\n]", tarefa->Nome);
            printf("\nNome alterado com sucesso!\n");
            break;
        case 2:
            printf("\nDigite a nova dificuldade da tarefa, sendo:\n");
            printf("1 - Facil\n");
            printf("2 - Media\n");
            printf("3 - Dificil\n");
            int nova_dificuldade;
            scanf("%d", &nova_dificuldade);
            strcpy(tarefa->Dificuldade, nova_dificuldade == 1 ? "Facil" : nova_dificuldade == 2 ? "Media" : "Dificil");
            printf("\nDificuldade alterada com sucesso!\n");
            break;
        case 3:
            printf("\nDigite o novo status da tarefa, sendo:\n");
            printf("1 - Nao concluida\n");
            printf("2 - Concluida\n");
            int novo_status;
            scanf("%d", &novo_status);
            strcpy(tarefa->Status, novo_status == 1 ? "Nao concluida" : "Concluida");
            printf("\nStatus alterado com sucesso!\n");
            break;
        case 4:
            return;
    }
}

void removerTarefa(Lista *l, int id) {
    int encontrado = 0;

    printf("ID's das tarefas:\n");
        for (int i = 0; i < l->posicaoAtual; i++) {
            printf("Id: %d: \nNome: %s\n", l->tarefas[i].id, l->tarefas[i].Nome);
        }

    printf("Digite o ID da tarefa a ser removida: ");
    scanf("%d", &id);

        for (int i = 0; i < l->posicaoAtual; i++) {
            if (l->tarefas[i].id == id) {
                encontrado = 1;
                for (int j = i; j < l->posicaoAtual - 1; j++) {
                    l->tarefas[j] = l->tarefas[j + 1];
                }
                l->posicaoAtual--;
                printf("Tarefa removida com sucesso.\n");
                break;
            }
    }
    if (!encontrado) {
        printf("Tarefa com ID %d nao encontrada.\n", id);
    }
}

void marcar_conclusao_de_uma_tarefa_especifica(Lista *l) {
    mostrar_tarefas_cadastradas(l);

    if (l->posicaoAtual == 0) {
        printf("Nenhuma tarefa cadastrada.\n");
        return;
    }

    int indice;
    printf("Digite o numero da tarefa concluida: ");
    scanf("%d", &indice);

    if (indice >= 1 && indice <= l->posicaoAtual) {
        strcpy(l->tarefas[indice - 1].Status, "ConcluIda");
        printf("Tarefa marcada como concluIda.\n");
    } else {
        printf("Indice invalido.\n");
    }
}


void salvar_lista_de_tarefas_em_um_arquivo(Lista *l) {
    FILE *arquivo = fopen("lista_de_tarefas.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    for (int i = 0; i < l->posicaoAtual; i++) {
        fprintf(arquivo, "ID: %d, Nome: %s, Dificuldade: %s, Status: %s\n",
                l->tarefas[i].id, l->tarefas[i].Nome, l->tarefas[i].Dificuldade, l->tarefas[i].Status);
    }
    fclose(arquivo);
    printf("Lista de tarefas salva com sucesso no arquivo 'lista_de_tarefas.txt'.\n");
}

void encerrar_programa(Lista *l) {
    if (l->tarefas != NULL) {
        free(l->tarefas);
        l->tarefas = NULL;
    }
    printf("Programa encerrado com sucesso. Ate mais!\n");
    exit(0);
}



