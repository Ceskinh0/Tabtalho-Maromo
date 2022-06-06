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
    printf("\tDigite o codigo do produto: ");
    scanf("%d", &p[pos]->codigo);
     fflush(stdin);
    printf("\tDigite a descricao do produto: ");
    scanf("%[^\n]", p[pos]->descricao);
     fflush(stdin);
    printf("\tDigite o nome do fornecedor: ");
    scanf("%[^\n]", p[pos]->fornecedor);
     fflush(stdin);
    printf("\tDigite quantidade em estoque: ");
    scanf("%d", &p[pos]->quantEstoque);
     fflush(stdin);
    printf("\tDigite o preco do produto: ");
    scanf("%lf", &p[pos]->preco);
    printf("\tRegistro cadastro com sucesso \n");
}
void listarTodos(produto* p[], int pos){
    for(int i=0; i<pos; i++){
        printf("\tDados do Registro: %d \n", i+1 );
        printf("\tcodigo do produto: %d \n", p[i]->codigo);
        printf("\tDescricao do produto: %s \n", p[i]->descricao);
        printf("\tNome do fornecedor: %s \n", p[i]->fornecedor);
        printf("\tQuantidade em estoque: %d \n", p[i]->quantEstoque);
        printf("\tPreco do produto: %.2lf \n", p[i]->preco);
        printf("\t--------------------------------------\n");
    }
}

void encontrar(produto* p[], int proc, int pos){
    for(int i=0; i<pos; i++){
        if(proc== p[i]->codigo){
            printf("\tDados do Registro: %d \n", i+1 );
            printf("\tCodigo do produto: %d \n", p[i]->codigo);
            printf("\tDescricao do produto: %s \n", p[i]->descricao);
            printf("\tNome do fornecedor: %s \n", p[i]->fornecedor);
            printf("\tQuantidade em estoque: %d \n", p[i]->quantEstoque);
            printf("\tPreco do produto: %.2lf \n", p[i]->preco);
            printf("\t--------------------------------------\n");
            return;
        }
    }
    printf("\tCodigo nao encontrado \n");
}

void comprar(produto* p[], int proc, int pos){
    int quantComp=0;
    int inv=0;
    printf("\tDigite a quantidade a ser comprada:");
    scanf("%d", &quantComp);
    for(int i=0; i<pos; i++){
        if(proc==p[i]->codigo){
            inv=1;
            p[i]->quantEstoque +=quantComp;
            printf("\tProduto comprado com sucesso!\n");
        }
    }
    if(inv==0){
        printf("\tCodigo nao encontrado \n");
    }
    fflush(stdin);
}

void vender(produto* p[], int proc, int pos){
    int quantVend=0;
    int inv=0;
    printf("\tDigite a quantidade a ser vendida:");
    scanf("%d", &quantVend);
    for(int i=0; i<pos; i++){
        if(proc==p[i]->codigo){
                inv=1;
            if(p[i]->quantEstoque==0 || quantVend > p[i]->quantEstoque){
                printf("\tQuantidade invalida impossivel vender!\n");
            }else{
                p[i]->quantEstoque -=quantVend;
                printf("\tProduto vendido com sucesso!\n");
                }
            }
        }
        if(inv==0){
        printf("\tCodigo nao encontrado \n");
        }
    fflush(stdin);
}

