#include <stdio.h>
#include <stdlib.h>

// Definir nÃ³ da Lista e a lista


typedef struct lista Lista;

struct lista {
    int conteudo;
    Lista* prox;
};

Lista* cria_lista(void){
    return NULL;
}

int lista_vazia(Lista* lst){
    return (lst == NULL);
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



Lista* insere_inicio(Lista* lst, int val){
	// Cria novo nÃ³
	// Testa se a criaÃ§Ã£o ocorreu sem problemas
	// FAz o conteÃºdo do novo nÃ³ igual ao conteÃºdo repassado
	// Faz o prÃ³ximo do novo nÃ³ apontar para a lista repassada
	// retorna lista atualizada

	Lista* novo = (Lista*)  malloc((sizeof(Lista)));
    if( novo == NULL){
        printf("Erro na criacao do no\n");
    }

    novo->conteudo = val;
    novo->prox = lst;

    return novo;

}



Lista* insere_fim(Lista* lst, int val){
	// Cria novo nÃ³
	// Testa se a criaÃ§Ã£o ocorreu sem problemas
	// FAz o conteÃºdo do novo nÃ³ igual ao conteÃºdo repassado

	// Verifica se a lista estÃ¡ vazia
	// Se nÃ£o estiver, varre a lista atÃ© o final
	// Ao encontrar o final, faz a lista apontar para o novo nÃ³

	// Se a lista estiver vazia, a nova lista Ã© igual ao prÃ³prio nÃ³ passado

	// retorna lista atualizada


	Lista *cauda = lst;
	Lista *cabeca = cauda;
	Lista *anterior = NULL;

	Lista* novo = (Lista*)  malloc((sizeof(Lista)));
    if( novo == NULL){
        printf("Erro na criacao do no\n");
    }
    novo->conteudo = val;

    while( cauda != NULL){
        anterior = cauda;
        cauda = cauda->prox;
    }

    if( anterior !=  NULL ){
        anterior->prox = novo;
        novo->prox = NULL;
    }
    else{
        return insere_inicio(lst,val);
    }

    return cabeca;

}


Lista* insere_posicao(Lista* lst, int val, int posicao){
	// Cria novo nÃ³
	// Testa se a criaÃ§Ã£o ocorreu sem problemas
	// FAz o conteÃºdo do novo nÃ³ igual ao conteÃºdo repassado

	// Testa se a posicao que se deseja inserir Ã© vÃ¡lida 1 <= pos <= quantidade

	// Se pos = 1, insere no inicio

	// Varre lista atÃ© posicao - 1
	// Guarda elemento na posicao - 1 -> elem, e para quem ele aponta -> prox
	// Faz que o prÃ³ximo de elem aponte para novo elemento
	// Faz que o prÃ³ximo de novo aponte para prox

	// retorna lista atualizada
    if( posicao < 0 || posicao > quantidade(lst)){
        return NULL;
    }
    if(posicao == 1 ){
        return insere_inicio(lst,val);
    }


    Lista* novo = (Lista*)  malloc((sizeof(Lista)));
    if( novo == NULL){
        printf("Erro na criacao do no\n");
    }
    novo->conteudo =val;
    Lista *aux = NULL;
    Lista *atual = lst;
    Lista *cabeca = atual;
    int i = 1;

    while(  i < posicao - 1 ){
        atual = atual->prox;
        i++;
    }
    aux = atual->prox;
    atual->prox = novo;
    novo->prox = aux;

    return  cabeca;

}




void imprime_lista(Lista* lst){

	// Varre a lista e imprime o valor do dado
	Lista* lista_temp = lst;

	while( lista_temp != NULL){
        printf("Dado: %d\n",lista_temp->conteudo);
        lista_temp = lista_temp->prox;
	}
}


Lista* buscar_lista(Lista* lst, int val){
	// Varre a lista e retorna um nÃ³ da lista cujo o valor seja aquele procurado
	Lista *p = lst;
	while( p != NULL ){
        if( p->conteudo == val ){
            return p;
        }else{
            return NULL;
        }
        p = p->prox;
	}
}

Lista* remove_lista(Lista* lst, int val){

	// Se lista vazia, devolve NULL

	// Tenta encontrar na lista se existe algum nÃ³ com o valor buscado e guarde em uma variÃ¡vel
	// Ao varrer, guarde sempre a referÃªncia para o nÃ³ anterior, e para o prÃ³ximo nÃ³

	// Ao terminar a varredura, se a variÃ¡vel  for NULL, elemento nÃ£o existe, devolve a lista

	// Varre a lista, enquanto o nÃ³ nÃ£o vazio e o valor nÃ£o for igual ao que se quer apagar
	// guardar o anterior e o prÃ³ximo;

	// Ao sair do laÃ§o, se o valor do nÃ³ onde a varredura parou for null, ->
	// o elemento nÃ£o existe

	// se o anterior for null, -> elemento a ser apagado Ã© o primeiro -> devolve a lista a partir do segundo

	// se o anterior nÃ£o for null, faz o prÃ³ximo do anterior apontar o prÃ³ximo do nÃ³ encontrado
	// devolve a memÃ³ria ao OS

	// retorna lista atualizada



    if( lista_vazia(lst)){
        printf("Lista vazia\n");
        return NULL;
    }

	Lista* ant =  NULL;
	Lista* p = lst;

	while( p != NULL && p->conteudo != val ){
        ant = p;
        p = p->prox;
	}

	if( p == NULL){
        return lst;
	}

	if( ant == NULL){
        lst = p->prox;
	}else{
        ant->prox = p->prox;
	}
	free(p);
	return lst;

}


Lista* insere_ordenado(Lista* lst, int val){

	// Cria novo nÃ³
	// Testa se a criaÃ§Ã£o ocorreu sem problemas
	// FAz o conteÃºdo do novo nÃ³ igual ao conteÃºdo repassado

	// Guarde referÃªncias para o nÃ³ anterior e o atual

	// Se a lista for vazia, insere no inicio

	// Varre a lista, enquanto o nÃ³ nÃ£o vazio e o valor nÃ£o for menor ao que se quer inserir
	// guardar o anterior e o prÃ³ximo;

	// Ao sair do laÃ§o, se o valor do nÃ³ anterior  for null, ->
	// insere no inicio

	// Ao sair do laÃ§o, se o valor do nÃ³ anterior  for != null, ->
	// insere no inicio

	// FAz o prÃ³ximo do anterior apontar para o novo
	// Faz o prÃ³ximo do novo elemento apontar para o nÃ³ onde a varredura parou

	// devolve a lista

	Lista *novo = (Lista*) malloc(sizeof(Lista));
	if( novo == Null){
        printf("Erro na criacao do no\n");
	}
	novo->conteudo = val;
	Lista *anterior;
	Lista *atual;

}

int main()
{
    int op = 0;
    int valor;
    int posicao;
    Lista* minha_lista = cria_lista();
    while(op!= 10){
        printf("1 - Insere valor no inicio da lista\n");
        printf("2 - Insere valor no final da lista\n");
        printf("3 - Insere valor em uma posicao da lista\n");
        printf("4 - Insere em ordem\n");
        printf("5 - Remove valor da lista\n");
        printf("6 - Zera lista\n");
        printf("7 - Imprime lista\n");
        printf("10 - Sair do Programa\n");
        scanf("%d",&op);
        switch (op){
            case 1 :
                printf("Digite valor a inserir na lista\n");
                scanf("%d",&valor);
                minha_lista = insere_inicio(minha_lista, valor);
                break;
            case 2 :
                printf("Digite valor a inserir na lista\n");
                scanf("%d",&valor);
                minha_lista = insere_fim(minha_lista, valor);
                break;
            case 3 :

                printf("Digite valor a inserir na lista\n");
                scanf("%d",&valor);
                printf("Digite valor a posicao na lista\n");
                scanf("%d",&posicao);

                minha_lista = insere_posicao(minha_lista, valor,posicao);
                break;
            case 4 :
                printf("Digite valor a inserir na lista\n");
                scanf("%d",&valor);
                minha_lista = insere_ordenado(minha_lista, valor);
                break;

            case 5 :
                if (!lista_vazia(minha_lista)){
                    printf("Digite valor a remover na lista\n");
                    scanf("%d",&valor);
                    minha_lista = remove_lista(minha_lista, valor);
                } else {
                    printf("Lista Vazia!\n");
                }
                break;
            case 6 :
                if (!lista_vazia(minha_lista)){
                    libera_lista(minha_lista);
                    minha_lista = cria_lista();
                }
                break;
            case 7 :
                if (lista_vazia(minha_lista)){
                    printf("Lista Vazia\n");
                } else
                    imprime_lista(minha_lista);
                break;
        }
    }
    return 0;
}
