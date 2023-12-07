#include <stdio.h>
#include "Funcoes.c"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    int opcao;
    int id;
    Lista l;
    inicializarLista(&l);

    do {
        printf("\n=============================================\n");
        printf("\nO que deseja fazer?\n");
        printf("1. Inserir nova tarefa\n");
        printf("2. Mostrar tarefas cadastradas\n");
        printf("3. Buscar por tarefa\n");
        printf("4. Editar informacoes de uma tarefa\n");
        printf("5. Remover tarefa\n");
        printf("6. Marcar conclusao de uma tarefa especifica\n");
        printf("7. Salvar lista de tarefas em um arquivo\n");
        printf("8. Sair\n");
        printf("\n=============================================\n");

        char input[10];
        int i;

        scanf("%s", input);

        for (i = 0; input[i] != '\0'; i++) {
            if (!isdigit(input[i])) {
                printf("Entrada invalida. Digite uma opcao valida.\n");
                break;
            }
        }

        if (i == strlen(input)) {
            opcao = atoi(input);

            if (opcao < 1 || opcao > 8) {
                printf("\nOpcao invalida. Digite uma opcao valida.\n");
            } else {
                switch (opcao) {
                    case 1:
                        inserir_nova_tarefa(&l);
                        break;
                    case 2:
                        mostrar_tarefas_cadastradas(&l);
                        break;
                    case 3:
                        buscar_por_tarefa(&l);
                        break;
                    case 4:
                        editar_informacoes_de_uma_tarefa(&l);
                        break;
                    case 5:
                        removerTarefa(&l, id);
                        break;
                    case 6:
                        marcar_conclusao_de_uma_tarefa_especifica(&l);
                        break;
                    case 7:
                        salvar_lista_de_tarefas_em_um_arquivo(&l);
                        break;
                    case 8:
                        encerrar_programa(&l);
                        break;
                }
            }
        }
    } while (opcao != 8);

    return 0;
}
