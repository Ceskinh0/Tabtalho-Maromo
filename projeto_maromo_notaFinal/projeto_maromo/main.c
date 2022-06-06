#include <stdio.h>
#include <stdlib.h>
#define T 500
#include "produto.h"

int main(){
    int pos = 0;
    int codProc = 0;
    produto* vet_produto[T];
    int opc = 0;
    inicializar(vet_produto, T);
    do{
        printf("\t=Manutencao de Produtos= \n");
        printf("\t----------------------- \n");
        printf("\t1. Cadastrar Produto \n");
        printf("\t2. Listar Produtos \n");
        printf("\t3. Procurar Produto \n");
        printf("\t4. Comprar Produtos \n");
        printf("\t5. Vender Produtos \n");
        printf("\t9. Sair \n");
        printf("\tDigite sua opcao: ");
        scanf("%d", &opc);
        system("cls");
        switch(opc){
            case 1:
                adicionar(vet_produto, pos);
                pos++;
                break;
            case 2:
                listarTodos(vet_produto, pos);
                break;
            case 3:
                printf("\tDigite o codigo a ser encontrado: ");
                scanf("%d", &codProc);
                encontrar(vet_produto, codProc, pos);
                break;
            case 4:
                printf("\tDigite o codigo do produto a ser comprado: ");
                scanf("%d", &codProc);
                comprar(vet_produto, codProc, pos);
                break;
            case 5:
                printf("\tDigite o codigo do produto a ser vendido: ");
                scanf("%d", &codProc);
                vender(vet_produto, codProc, pos);
                break;
            case 9:
                printf("\tFim do programa \n");
                break;
            default:
                printf("Opcao invalida \n");
        }
    }while(opc!=9);
    return 0;
}
