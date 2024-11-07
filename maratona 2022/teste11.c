#include <stdio.h>
#include <stdlib.h>

struct no{
    int valor;
    struct no * prox;
};
typedef struct no * noPtr;

int listaVazia(noPtr topo){
    if(topo != NULL){
        return 0;
    }
    else{
        return 1;
    }
}

void inserir(noPtr * i, int * qtd){

    noPtr p = (noPtr)malloc(sizeof(struct no));

    printf("Digite um número inteiro que deseja inserir na lista circular: \n");
    scanf("%d", &p->valor);

    if(listaVazia(*i)){
        * i = p;
        p->prox = * i;
    }
    else{
        p->prox = (*i)->prox;
        (* i)->prox = p;
        * i = p;
    }
    (* qtd)++;
}

void retirar(noPtr * i, int * qtd){
    noPtr aux = * i;
    if(!listaVazia(*i)){
        if(aux->prox == * i){
            * i = NULL;
        }
        else{
            *i = aux->prox;
        }
        free(aux);
        printf("O elemento foi retirado da lista!\n");
        (* qtd)--;
    }
    else{
        printf("A lista está vazia!\n");
    }
}

void listar(noPtr i, int qtd){
    
    if(!listaVazia(i)){
        for(int j = 0; j < qtd; j++){
            printf("%d \t\t", i->valor);
            printf("%p\n", i->prox);
            i = i->prox;
        }
    }
    else{
        printf("A lista está vazia!\n");
    }
}

int main(){
    
    int op, quantidade = 0;
    noPtr topo = NULL;

    do{
        printf("Escolha uma das opções abaixo: \n(1)Inserir\n(2)Retirar\n(3)Listar\n");
        scanf("%d", &op);

        switch(op){
            case 1: inserir(&topo, &quantidade); break;
            case 2: retirar(&topo, &quantidade); break;
            case 3: listar(topo, quantidade); break;
        }
    }while(op != 0);

    return 0;
} 