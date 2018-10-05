#include <stdio.h>
#include <stdlib.h>




struct produto{
    int codigo;
    char nome[30];
};

typedef struct produto Produto;


struct lista {
   Produto info;
   struct lista* prox;
};

typedef struct lista Lista;

Lista* cria_lista(void){
    return NULL;
}


Lista* aloca_novo(void){
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    if (novo == NULL){
        printf("Erro na criação de novo elemento");
    }
    return novo;
}

Produto criaNovo(){
    Produto novo;
    printf("Digite o codigo do produto: ");
    scanf("%d",&novo.codigo);
    printf("Digite o nome do produto: ");
    scanf("%s",&novo.nome);
    return novo;
}

void imprime(Produto p){
    printf("Codigo (%d) : %s\n", p.codigo, p.nome);
}

Lista* insere_inicio(Lista* lst, Produto prod){
    Lista* novo = aloca_novo();
    if (novo == NULL) {
        return lst;
    }
    novo->info = prod;
    novo->prox = lst;
    return novo;
}


Lista* insere_fim(Lista* lst, Produto prod){
    Lista* novo = aloca_novo();
    if (novo == NULL) {
        return lst;
    }

    novo->info = prod;
    novo->prox = NULL;

    Lista* p = lst;
    if (!lista_vazia(p)){
        while (p->prox != NULL){
            p = p->prox;
        }
        p->prox = novo;
        return lst;
    } else{
        return novo;
    }
}

int quantidade(Lista* lst){
    int total = 0;
    if (!lista_vazia(lst)){
        Lista* p = lst;
        while (p != NULL){
            total++;
            p=p->prox;
        }
    }
    return total;

}



Lista* insere_posicao(Lista* lst, Produto prod, int posicao){
    Lista* novo = aloca_novo();
    if (novo == NULL) {
        return lst;
    }

    if ((posicao <1) || (posicao > quantidade(lst))){
        printf("posicao invalida");
        return lst;
    }
    if (posicao == 1){
        return insere_inicio(lst, prod);
    }


    Lista* p = lst;
    Lista* ant = p;
    int cont = 1;
    while (cont != (posicao - 1)){
        cont++;
        ant = p;
        p=p->prox;
    }

    Lista* pos = p->prox;

    p->prox = novo;

    novo->info = prod;
    novo->prox = pos;

    return lst;
}




void imprime_lista(Lista* lst){
    Lista* p;
    for (p = lst; p != NULL; p = p->prox){
        imprime(p->info);
    }
    printf("Final de lista\n");
}

int lista_vazia(Lista* lst){
    return (lst == NULL);
}



Produto buscar_lista(Lista* lst, int val){

    Lista* ret;
    for (ret = lst; ret != NULL; ret = ret->prox){
        if (ret->info.codigo == val){
            return ret->info;
        }
    }
    return;
}



Lista* remove_lista(Lista* lst, int val){
    if (lista_vazia(lst)){
        printf("Lista Vazia\n");
        return NULL;
    }
    Lista* ant = NULL;
    Lista* p = lst;

    while (p != NULL && p->info.codigo != val) {
        ant = p;
        p = p->prox;
    }

    if (p == NULL){
        return lst;
    }

    if (ant == NULL){
        lst = p->prox;
    } else{
        ant->prox = p->prox;
    }
    free(p);
    return lst;
}

void libera_lista (Lista* lst)
{
    Lista* p = lst;
    Lista* t = NULL;
    while (p != NULL) {
        t = p->prox;
        free(p);
        p = t;
    }
}

Lista* insere_ordenado(Lista* lst, Produto prod){

    Lista* novo = aloca_novo();
    if (novo == NULL) {
        return lst;
    }



    Lista* ant = NULL;
    Lista* temp = lst;

    if (lista_vazia(lst)){
        return insere_inicio(lst, prod);
    }

    while (temp != NULL && temp->info.codigo < prod.codigo){
        ant = temp;
        temp=temp->prox;
    }


    if (ant == NULL){
        return insere_inicio(lst, prod);
    } else{
        novo->info = prod;
        novo->prox=temp;
        ant->prox=novo;
    }
    return lst;
}

int main()
{
    int op = 0;
    int valor;
    int posicao;
    Produto prod;
    Lista* minha_lista = cria_lista();
    while(op!= 10){
        printf("1 - Insere valor no inicio da lista\n");
        printf("2 - Insere valor no final da lista\n");
        printf("3 - Insere valor no meio da lista\n");
        printf("4 - Remove valor da lista\n");
        printf("5 - Imprime lista\n");
        printf("6 - Zera lista\n");
        printf("7 - Insere em ordem\n");
        printf("10 - Sair do Programa\n");
        scanf("%d",&op);
        switch (op){
            case 1 :
                prod = criaNovo();
                minha_lista = insere_inicio(minha_lista, prod);
                break;
            case 2 :
                prod = criaNovo();
                minha_lista = insere_fim(minha_lista, prod);
                break;
            case 3 :
                prod = criaNovo();
                printf("Digite valor a posicao na lista\n");
                scanf("%d",&posicao);
                minha_lista = insere_posicao(minha_lista, prod, posicao);
                break;
            case 4 :
                if (!lista_vazia(minha_lista)){
                    printf("Digite o codigo do produto a remover na lista\n");
                    scanf("%d",&valor);
                    minha_lista = remove_lista(minha_lista, valor);
                } else {
                    printf("Lista Vazia!\n");
                }
                break;
            case 5 :
                if (lista_vazia(minha_lista)){
                    printf("Lista Vazia\n");
                } else
                    imprime_lista(minha_lista);
                break;
            case 6 :
                if (!lista_vazia(minha_lista)){
                    libera_lista(minha_lista);
                    minha_lista = cria_lista();
                }
                break;
            case 7 :
                prod = criaNovo();
                minha_lista = insere_ordenado(minha_lista, prod);
                break;
            case 8 :
                minha_lista = ordenar(minha_lista);
                break;

        }
    }
    return 0;
}
