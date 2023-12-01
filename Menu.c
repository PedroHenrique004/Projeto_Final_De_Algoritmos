#include <stdio.h>
#include "Funcoes.c"
#include <stdlib.h>
#include <string.h>

/* void inserir_nova_tarefa();
void mostrar_tarefas_cadastradas();
void buscar_por_tarefa();
void editar_informacoes_de_uma_tarefa();
void remover_tarefa();
void marcar_conclusao_de_uma_tarefa_especifica();
void salvar_lista_de_tarefas_em_um_arquivo(); */

//Criei a lista de tarefas primeiro anes da funcao inserirnovatarefa para poder apenas adicionar os dados nela com ponteiros


// Struct com as caracteristicas da tarefa


int main() {
    int opcao;
    //vetor que mede o tamanho da struct de lista pra gente poder mexer nas posições e nas caracteristicas delas
    // l ta se referindo as tarefas (por exemplo: l.posicao = 0 vai ser a tarefa 1)
    Lista l;
    l.tarefas = (Tarefa*)calloc(10, sizeof(Tarefa)); 

    //Da posição 0 a lista para a primeira ser a 0
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

        scanf("%d", &opcao);

        if (opcao < 1 || opcao > 7) {
            printf("\nOpcao invalida. Digite uma opcao valida.\n");
        } 

        else {

         switch (opcao) {
        case 1:
            inserir_nova_tarefa(l);
            // Aumenta a posição da tarefa para se clicarmos aq denovo vai iniciar a tarefa na l[1] que é a tarefa 2
            l.posicaoAtual++;
            break;
        case 2:
            mostrar_tarefas_cadastradas(l);
            break;
        case 3:
            buscar_por_tarefa();
            break;
        case 4:
            editar_informacoes_de_uma_tarefa(l);
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
        }
    }} while (opcao != 8);

   

    return 0;
}