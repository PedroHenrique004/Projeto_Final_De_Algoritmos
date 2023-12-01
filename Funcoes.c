#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tarefa {
    char Nome[50];
    char Dificuldade[20];
    char Status[20];
} Tarefa;


// Struct para a lista de trefas
typedef struct listadeTrarefas {
    Tarefa *tarefas;
    int posicaoAtual; 
} Lista;


void inserir_nova_tarefa(Lista l) {
    char nome[50];
    int dificuldade;
    int status;
   

    printf("\nDigite o nome da tarefa em ate 50 caracteres:");
    scanf(" %49[^\n]", nome);
    //Pega a tarefa l e dentro dela a posicao que ela está e altera só o nome dessa tarefa, dentro da lista de tarefas
    strcpy(l.tarefas[l.posicaoAtual].Nome , nome);

    printf ("Digite a dificuldade da tarefa, sendo:\n");
    printf ("1 - Facil\n");
    printf ("2 - Media\n");
    printf ("3 - Dificil\n");
     
    scanf("%d", &dificuldade);
    if (dificuldade < 1 || dificuldade > 3)
    {
        printf("Dificuldade invalida!\n");
        return;
    }
    //isso daqui é só um if que se dificuldade for igual a 1 aparece facul e tarara
    strcpy(l.tarefas[l.posicaoAtual].Dificuldade, dificuldade == 1 ? "facil" : dificuldade == 2 ? "Medio" : "Dificil");

    printf ("Digite os status da tarefa, use:\n");
    printf ("1 - Tarefa nao concluida \n");
    printf ("2 - Tarefa concluida\n");
    scanf("%d", &status);
    if (status < 1 || status > 2)
    {
        printf("Status invalida!\n");
        return;
    }
    strcpy(l.tarefas[l.posicaoAtual].Status, status == 1 ? "Nao concluida" : "Concluida");

    printf("\ntarefa inserida com sucesso!\n");
    printf("\nNome: %s\n", l.tarefas[l.posicaoAtual].Nome);
    printf("Dificuldade: %s\n", l.tarefas[l.posicaoAtual].Dificuldade);
    printf("Status: %s\n", l.tarefas[l.posicaoAtual].Status);
    
}

void mostrar_tarefas_cadastradas(Lista l) {
    int i;

    printf("\nTarefas cadastradas:\n");

    for (i = 0; i < l.posicaoAtual; i++) {
        printf("\nTarefa %d:\n", i + 1);
        printf("\nNome: %s\n", l.tarefas[i].Nome);
        printf("Dificuldade: %s\n", l.tarefas[i].Dificuldade);
        printf("Status: %s\n", l.tarefas[i].Status);
    }
}

void buscar_por_tarefa() {
    printf("Oi 3\n");
}

void editar_informacoes_de_uma_tarefa(Lista l) {
    int numero, opcao;
    char novo_nome[50];
    int nova_dificuldade, novo_status;
    int i;

    printf("\nDigite o numero da tarefa que voce quer editar:\n");

    for (i = 0; i < l.posicaoAtual; i++) {
        printf("\nTarefa %d:\n", i + 1);
        printf("Nome: %s\n", l.tarefas[i].Nome);
        printf("Dificuldade: %s\n", l.tarefas[i].Dificuldade);
        printf("Status: %s\n", l.tarefas[i].Status);
    }

    scanf("%d", &numero);

    // Verifica se o numero da tarefa e valido
    if (numero < 1 || numero > l.posicaoAtual) {
        printf("\nNumero invalido. Digite um numero valido.\n");
        return;
    }

    // Mostra as opcoes de edicao
    printf("\nO que voce quer editar na tarefa %d?\n", numero);
    printf("\n1. Nome\n");
    printf("2. Dificuldade\n");
    printf("3. Voltar\n");

    scanf("%d", &opcao);

    if (opcao < 1 || opcao > 3) {
        printf("\nOpcao invalida. Digite uma opcao valida.\n");
        return;
    }

    switch (opcao) {
        case 1:
            // Altera o nome da tarefa
            printf("\nDigite o novo nome da tarefa em ate 50 caracteres:\n");
            scanf(" %49[^\n]", novo_nome);
            strcpy(l.tarefas[numero - 1].Nome, novo_nome);
            printf("\nNome alterado com sucesso!\n");
            break;
        case 2:
            // Altera a dificuldade da tarefa
            printf("\nDigite a nova dificuldade da tarefa, sendo:\n");
            printf("1 - Facil\n");
            printf("2 - Media\n");
            printf("3 - Dificil\n");
            scanf("%d", &nova_dificuldade);
            if (nova_dificuldade < 1 || nova_dificuldade > 3) {
                printf("\nDificuldade invalida. Digite uma dificuldade valida.\n");
                return;
            }
            strcpy(l.tarefas[numero - 1].Dificuldade, nova_dificuldade == 1 ? "facil" : nova_dificuldade == 2 ? "Medio" : "Dificil");
            printf("\nDificuldade alterada com sucesso!\n");
            break;
        case 3:
            // Volta para o menu principal
            return;
    }
}    

void remover_tarefa() {
    printf("Oi 5\n");
}

void marcar_conclusao_de_uma_tarefa_especifica() {
    printf("Oi 6\n");
}

void salvar_lista_de_tarefas_em_um_arquivo() {
    printf("Oi 7\n");
}

