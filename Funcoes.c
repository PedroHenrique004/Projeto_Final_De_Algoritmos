#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tarefa {
    int id; // Supondo que cada tarefa tenha um identificador único
    char Nome[50];
    char Dificuldade[20];
    char Status[20];
} Tarefa;

typedef struct listaDeTarefas {
    Tarefa *tarefas;
    int posicaoAtual;
    int capacidade; // Adicionado para controlar a capacidade total da lista
} Lista;

void inicializarLista(Lista *l) {
    l->capacidade = 10; // Inicializa a lista com capacidade para 10 tarefas
    l->tarefas = (Tarefa*)calloc(l->capacidade, sizeof(Tarefa));
    l->posicaoAtual = 0;
}

void redimensionarLista(Lista *l) {
    if (l->posicaoAtual == l->capacidade) {
        l->capacidade *= 2; // Duplica a capacidade se necessário
        l->tarefas = (Tarefa*)realloc(l->tarefas, l->capacidade * sizeof(Tarefa));
    }
}

void inserir_nova_tarefa(Lista *l) {
    redimensionarLista(l); // Garante que há espaço para a nova tarefa

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

    l->tarefas[l->posicaoAtual].id = l->posicaoAtual + 1; // Atribui um ID único à tarefa
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

    // Encontrar a tarefa pelo ID
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
            // Voltar ao menu anterior
            return;
    }
}

void removerTarefa(Lista *l, int id) {
    int encontrado = 0;
    for (int i = 0; i < l->posicaoAtual; i++) {
        if (l->tarefas[i].id == id) {
            encontrado = 1;
            // Desloca as tarefas seguintes para a posição atual
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
    int id;
    printf("Digite o ID da tarefa que deseja marcar como concluida: ");
    scanf("%d", &id);

    for (int i = 0; i < l->posicaoAtual; i++) {
        if (l->tarefas[i].id == id) {
            strcpy(l->tarefas[i].Status, "Concluida");
            printf("Tarefa %d marcada como concluida.\n", id);
            return;
        }
    }
    printf("Tarefa com ID %d nao encontrada.\n", id);
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
    printf("Programa encerrado com sucesso. Até mais!\n");
    exit(0);
}



