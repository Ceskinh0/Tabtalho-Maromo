#include <stdio.h>
#include <stdlib.h>
#define T 500
#include "produto.h"

int main()
{
    int pos = 0;
    int codProc = 0;
    produto* vet_produto[T];
    int opc = 0;
    inicializar(vet_produto, T);
    do{
        printf("Manutencao de Produto \n");
        printf("-------------------- \n");
        printf("1. Cadastrar Produto \n");
        printf("2. Procurar Produto \n");
        printf("3. Atualizar Produto \n");
        printf("4. Apresentar todos \n");
        printf("9. Sair \n");
        printf("Digite sua opcao: \n");
        scanf("%d", &opc);
        switch(opc){
            case 1:
                adicionar(vet_produto, pos);
                pos++;
                break;
            case 2:
                printf("Digite o codigo a ser encontrado: \n");
                scanf("%d", &codProc);
                encontrar(vet_produto, codProc, pos);
                break;
            case 3:
                printf("Digite o codigo a ser atualizado: \n");
                scanf("%d", &codProc);
                atualizar(vet_produto, codProc, pos);
                break;
            case 4:
                listarTodos(vet_produto, pos);
                break;
            case 9:
                printf("Fim do programa \n");
                break;
            default:
                printf("Opcao invalida \n");
        }
    }while(opc!=9);
    return 0;
}
