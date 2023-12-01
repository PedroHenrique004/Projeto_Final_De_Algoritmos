#include <stdio.h>
#include "Funcoes.c"
#include <stdlib.h>
#include <string.h>

int main() {
    int opcao;
    Lista l;
    l.tarefas = (Tarefa*)calloc(10, sizeof(Tarefa)); 
    l.posicaoAtual = 0;    

    do {
        printf("\nO que deseja fazer?\n");
        printf("\n1. Inserir nova tarefa\n");
        printf("2. Mostrar tarefas cadastradas\n");
        printf("3. Buscar por tarefa\n");
        printf("4. Editar informacoes de uma tarefa\n");
        printf("5. Remover tarefa\n");
        printf("6. Marcar conclusao de uma tarefa especifica\n");
        printf("7. Salvar lista de tarefas em um arquivo\n");
        printf("8. Sair\n");

        scanf("%d", &opcao);

        if (opcao < 1 || opcao > 7) {
            printf("\nOpcao invalida. Digite uma opcao valida.\n");
        } 

        else {

         switch (opcao) {
        case 1:
            inserir_nova_tarefa();
            break;
        case 2:
            mostrar_tarefas_cadastradas();
            break;
        case 3:
            buscar_por_tarefa();
            break;
        case 4:
            editar_informacoes_de_uma_tarefa();
            break;
        case 5:
            remover_tarefa();
            break;
        case 6:
            marcar_conclusao_de_uma_tarefa_especifica();
            break;
        case 7:
            salvar_lista_de_tarefas_em_um_arquivo();
            break;

        case 8:
            break;
        }
    }} while (opcao != 8);

   

    return 0;
}