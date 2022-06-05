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
    printf("Digite o codigo do produto: ");
    scanf("%d", &p[pos]->codigo);
     fflush(stdin);
    printf("Digite a descricao do produto: ");
    scanf("%[^\n]", p[pos]->descricao);
     fflush(stdin);
    printf("Digite o nome do fornecedor: ");
    scanf("%[^\n]", p[pos]->fornecedor);
     fflush(stdin);
    printf("Digite quantidade em estoque: ");
    scanf("%d", &p[pos]->quantEstoque);
     fflush(stdin);
    printf("Digite o preco do produto: ");
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
            printf("Codigo do produto: %d \n", p[i]->codigo);
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

void comprar(produto* p[], int proc, int pos){
    int quantComp=0;
    printf("Digite a quantidade a ser comprada:");
    scanf("%d", &quantComp);
    for(int i=0; i<pos; i++){
        if(proc==p[i]->codigo){
            p[i]->quantEstoque +=quantComp;
            printf("Pdotudo comprado com sucesso!\n");
        }else{
            printf("Codigo nao encontrado \n");
        }
    }
    fflush(stdin);
}

void vender(produto* p[], int proc, int pos){
    int quantVend=0;
    printf("Digite a quantidade a ser vendida:");
    scanf("%d", &quantVend);
    for(int i=0; i<pos; i++){
        if(proc==p[i]->codigo){
            if(p[i]->quantEstoque==0 || quantVend > p[i]->quantEstoque){
                printf("Quantidade invalida impossivel vender!\n");
            }else{
                p[i]->quantEstoque -=quantVend;
                printf("Poduto vendido com sucesso!\n");
            }
        }else{
            printf("Codigo nao encontrado \n");
        }
    }
    fflush(stdin);
}
