#include <stdio.h>
#include <stdlib.h>
#include "produto.h"

void inicializar(produto* p[], int tam){
    for(int i=0; i<tam; i++){
        p[i] = NULL;
    }
}

void adicionar(produto* p[], int pos){
    p[pos] = (produto*)malloc(sizeof(struct Produto));
     fflush(stdin);
    printf("Digite o codigo do produto: \n");
    scanf("%d", &p[pos]->codigo);
     fflush(stdin);
    printf("Digite a descricao do produto: \n");
    scanf("%[^\n]", p[pos]->descricao);
     fflush(stdin);
    printf("Digite o nome do fornecedor: \n");
    scanf("%[^\n]", p[pos]->fornecedor);
     fflush(stdin);
    printf("Digite quantidade em estoque: \n");
    scanf("%d", &p[pos]->quantEstoque);
     fflush(stdin);
    printf("Digite o preco do produto: \n");
    scanf("%lf", &p[pos]->preco);
    printf("Registro cadastro com sucesso \n");
}
void listarTodos(produto* p[], int pos){
    for(int i=0; i<pos; i++){
        printf("Dados do Registro: %d \n", i+1 );
        printf("codigo do produto: %d \n", p[i]->codigo);
        printf("Descricao do produto: %s \n", p[i]->descricao);
        printf("Nome do fornecedor: %s \n", p[i]->fornecedor);
        printf("Quantidade em estoque: %d \n", p[i]->quantEstoque);
        printf("Preco do produto: %.2lf \n", p[i]->preco);
        printf("--------------------------------------\n");
    }
}

void encontrar(produto* p[], int proc, int pos){
    for(int i=0; i<pos; i++){
        if(proc== p[i]->codigo){
            printf("Dados do Registro: %d \n", i+1 );
            printf("codigo do produto: %d \n", p[i]->codigo);
            printf("Descricao do produto: %s \n", p[i]->descricao);
            printf("Nome do fornecedor: %s \n", p[i]->fornecedor);
            printf("Quantidade em estoque: %d \n", p[i]->quantEstoque);
            printf("Preco do produto: %.2lf \n", p[i]->preco);
            printf("--------------------------------------\n");
            return;
        }
    }
    printf("Codigo nao encontrado \n");
}

void atualizar(produto* p[], int proc, int pos){
    int resp = 0;
    for(int i=0; i<pos; i++){
        if(proc== p[i]->codigo){
            printf("Atualizar Registro: %d \n", i+1 );
            printf("Atualizar codigo? [0] nao, [1] sim\n");
            scanf("%d", &resp);
            if(resp){
                fflush(stdin);
                printf("Codigo do produto: %d \n", p[i]->codigo);
                printf("Digite o novo codigo: \n");
                scanf("%d", p[i]->codigo);
            }
            printf("Atualizar a descricao do produto? [0] nao, [1] sim\n");
            scanf("%d", &resp);
            if(resp){
                fflush(stdin);
                printf("Descricao: %s \n", p[i]->descricao);
                printf("Digite a nova descricao: \n");
                scanf("%[^\n]", p[i]->descricao);
            }
            printf("Atualizar o fornecedor? [0] nao, [1] sim\n");
            scanf("%d", &resp);
            if(resp){
                fflush(stdin);
                printf("Fornecedor: %s \n", p[i]->fornecedor);
                printf("Digite o novo Fornecedor: \n");
                scanf("%[^\n]", p[i]->fornecedor);
            }
            printf("Atualizar a quantidade em estoque? [0] nao, [1] sim\n");
            scanf("%d", &resp);
            if(resp){
                fflush(stdin);
                printf("Quantidade em estoque: %d \n", p[i]->quantEstoque);
                printf("Digite a quantidade em estoque atual: \n");
                scanf("%d", p[i]->quantEstoque);
            }
            printf("Atualizar o Preco? [0] nao, [1] sim\n");
            scanf("%d", &resp);
            if(resp){
                fflush(stdin);
                printf("Preco do produto: %.2f \n", p[i]->preco);
                printf("Digite o novo Preco do produto: \n");
                scanf("%.2lf", &p[i]->preco);
            }
            printf("Registro Atualizado com sucesso \n");
            return;
        }
    }
    printf("Registro não encontrado \n");
}
