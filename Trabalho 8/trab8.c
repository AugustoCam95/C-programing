#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno{
    int matricula;
    char nome[30];
    float notas[3];
    int faltas;
};

typedef struct aluno Aluno;


struct lista {
   Aluno info;
   struct lista* prox;
};

typedef struct lista Lista;

Lista* cria_lista(void){
    return NULL;
}

int lista_vazia(Lista* lst){
    return (lst == NULL);
}

Lista* aloca_novo(void){
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    if (novo == NULL){
        printf("Erro na criacao do novo elemento");
    }
    return novo;
}

Aluno criaNovo(){
    Aluno novo;
    printf("Digite a matricula do aluno: ");
    scanf("%d",&novo.matricula);
    printf("Digite o nome do aluno: ");
    setbuf(stdin , NULL);
    scanf(" %[^\n]s", novo.nome);
    printf("Digite as 3 notas do aluno:\n");
    scanf("%f %f %f",&novo.notas[0],&novo.notas[1],&novo.notas[2]);
    printf("Digite o numero de faltas do aluno:\n");
    scanf("%d", &novo.faltas);
    return novo;
}

void imprime(Aluno p){
    printf("Matricula:%d\n", p.matricula);
    printf("Nome:%s\n", p.nome);
    printf("Notas:%.2f %.2f %.2f\n", p.notas[0],p.notas[1],p.notas[2]);
    printf("Media:%.2f\n", ((p.notas[0]+p.notas[1]+p.notas[2])/3));
    printf("Faltas:%d\n", p.faltas);
}

void imprime_lista(Lista* lst){
    Lista* p;

    p = lst;
    if(p != NULL){
        imprime(p->info);
        imprime_lista(p->prox);
    }
}

Lista* insere_inicio(Lista* lst, Aluno student){
    Lista* novo = aloca_novo();
    if (novo == NULL) {
        return lst;
    }
    novo->info = student;
    novo->prox = lst;
    return novo;
}

Lista* insere_fim(Lista* lst,Aluno student){
    Lista* novo = aloca_novo();
    if (novo == NULL) {
        return lst;
    }
    novo->info = student;
    novo->prox = NULL;
    Lista* p = lst;

    if (!lista_vazia(p)){
        if(p->prox != NULL){
            p = p->prox;
            insere_fim(p,student);
            return lst;
        }
        p->prox= novo;

    }
    else{
        return novo;
    }

}



int quantidade(Lista* lst, int total){

    if (!lista_vazia(lst)){
        Lista* p = lst;

        if( p != NULL){
            return quantidade(p->prox,total+1);
        }
    }
    return total;

}

Lista* insere_posicao(Lista* lst, Lista *p ,Aluno prod, int posicao, int cont){

    Lista* novo = aloca_novo();
    if (novo == NULL) {
        return lst;
    }
    if ((posicao <1) || (posicao > quantidade(lst,0))){
        printf("posicao invalida");
        return lst;
    }
    if (posicao == 1){
        return insere_inicio(lst, prod);
    }

    if (cont != (posicao - 1)){
        cont++;
        p = p->prox;
        insere_posicao(lst, p ,prod,posicao,cont);
    }
    else{
        Lista* ant = p;
        Lista* pos = p->prox;

        ant->prox = novo;

        novo->info = prod;
        novo->prox = pos;
    }

    return lst;
}

void buscar_lista(Lista *lst, int matricula){
    if(!lista_vazia(lst)){
        Lista* p =lst;
        if( p->info.matricula == matricula ){
            imprime(p->info);
        }
        else{
            buscar_lista(p->prox,matricula);
        }
    }
}

void libera_lista(Lista* lst){

    if(lst != NULL)
    {
        free(lst);
        libera_lista(lst->prox);
    }
}

Lista* insere_ordenado(Lista* lst, Lista* q ,Lista* r,Aluno student){

    Lista* novo = aloca_novo();
    if (novo == NULL) {
        return lst;
    }
    if (lista_vazia(lst)){
        return insere_inicio(lst, student);
    }

    if (q!= NULL && q->info.matricula < student.matricula){
        r = q;
        q = q->prox;
        insere_ordenado(lst,q,r,student);
    } else{
        if( r == NULL){
            return insere_inicio(lst, student);
        }else{
            novo->info = student;
            novo->prox=q;
            r->prox=novo;
        }
    }

    return lst;
}

Lista* remove_aluno(Lista* lst, Lista* s , Lista* t ,int matricula){
   if (lista_vazia(lst)){
        printf("Lista Vazia\n");
        return NULL;
    }
    if(s != NULL && s->info.matricula != matricula) {
        t = s;
        s = s->prox;
        remove_aluno(lst,s,t,matricula);
    }else{
        if (s == NULL){
            return lst;
        }
        if (t == NULL){
            lst = s->prox;
        } else{
            t->prox = s->prox;
        }
        free(s);
        return lst;
    }

}

int indicar_indice(Lista* lst, int val, int cont){
    if (lista_vazia(lst)){
        printf("Lista Vazia\n");
    }
    if(lst != NULL && lst->info.matricula == val){
       return cont+1;
    }
    if (lst != NULL && lst->info.matricula != val) {
        cont++;
        indicar_indice(lst->prox,val,cont);

    }
}

void bubbleSort(Lista* vetor, int tamanho){
    int i, j;
    Lista aux;
    Lista* p;
    for(j=tamanho-1; j>=1; j--){
        for(i=0; i<j; i++){
            if(vetor[i].info.matricula > vetor[i+1].info.matricula){
                aux=vetor[i];
                vetor[i]=vetor[i+1];
                vetor[i+1]=aux;
            }
        }
    }
}


Lista* ordenar_lista(Lista* vetor, Lista* lst,Lista* p,int tamanho, int i){

    bubbleSort(vetor,tamanho);

    for( p = lst ;p != NULL;p = p->prox){
        p->info = vetor[i].info;
        i++;
    }
    if( p != NULL ){
        p->info = vetor[i].info;
        ordenar_lista(vetor,lst,p->prox,tamanho,i+1);
    }else{
        return lst;
    }

}


void criar_arquivotexto(char nomeArquivo[],Lista* lst){
    FILE* aptr;
    Aluno aluno;

    aptr = fopen(nomeArquivo,"a");
    if(aptr == NULL)
        printf("Erro na criacao do arquivo!\n");
    else
    {

        if(lst != NULL ){
            aluno = lst->info;
            fwrite(&aluno,sizeof(Aluno),1,aptr);
            criar_arquivotexto(nomeArquivo,lst->prox);
        }
        else{
        printf("Arquivo criado com sucesso!\n");
        }
    }
    fclose(aptr);
}

void criar_arquivobinario(char nomeArquivo[],Lista* lst){
    FILE* aptr;
    Aluno aluno;

    aptr = fopen(nomeArquivo,"ab");
    if(aptr == NULL)
        printf("Erro na criacao do arquivo!\n");
    else
    {

        if(lst != NULL ){
            aluno = lst->info;
            fwrite(&aluno,sizeof(Aluno),1,aptr);
            criar_arquivobinario(nomeArquivo, lst->prox);
        }
        else{
        printf("Arquivo criado com sucesso!\n");
        }
    }

    fclose(aptr);

}

Lista* abrir_arquivoTexto(char nomeArquivo[],Lista* lst){

    FILE* aptr;
    Aluno aluno;
    int fim_arq = 1;

    aptr = fopen(nomeArquivo,"r");

    if(aptr == NULL)
        printf("Erro na abertura do arquivo!\n");
    else
    {
         while( fread(&aluno,sizeof(Aluno),1,aptr) == 1){
            lst = insere_inicio(lst, aluno);
        }
        fclose(aptr);
    }
    return lst;
}

Lista* abrir_ArquivoBinario(char nomeArquivo[],Lista* lst){
    FILE* aptr;
    Aluno aluno;
    int fim_arq = 1;

    aptr = fopen(nomeArquivo,"rb");

    if(aptr == NULL)
        printf("Erro na abertura do arquivo!\n");
    else
    {
        while(fim_arq != 0){
            fim_arq = fread(&aluno,sizeof(Aluno),1,aptr);
            if(fim_arq != 0){
                lst = insere_inicio(lst, aluno);
            }
        }
        fclose(aptr);
    }
    return lst;
}

int main(){
    int i;
    int matricula;
    int op = 0;
    int total;
    int escolha;
    int cont;
    int valor;
    int posicao;
    char nomeArquivo[50];
    Aluno student;
    Lista* minha_lista = cria_lista();
    Lista* p = minha_lista;

    while(op!= 14){
        printf("1 - Inserir um novo aluno no final da lista\n");
        printf("2 - Inserir um novo aluno no inicio da lista\n");
        printf("3 - Inserir um novo aluno em uma posicao especifica da lista\n");
        printf("4 - Inserir um aluno de forma ordenada pelo numero de matricula\n");
        printf("5 - Remover um aluno de acordo com seu numero de matricula\n");
        printf("6 - Consultar os dados de um aluno pela matricula\n");
        printf("7 - Listar alunos da listas\n");
        printf("8 - Apresentar o numero de alunos cadastrados\n");
        printf("9 - Indicar o indice de acordo com seu numero de matricula\n");
        printf("10 - Re-inicializar a lista\n");
        printf("11 - Ordenar a lista de acordo com a ordem de matricula dos alunos cadastrados\n");
        printf("12 - Gerar um arquivo com os dados dos alunos\n");
        printf("13 - Carregar a lista a partir de um arquivo existente\n");
        printf("14 - Sair do Programa\n");
        scanf("%d",&op);
        switch (op){
            case 1 :
                student = criaNovo();
                minha_lista = insere_fim(minha_lista, student);
                break;
            case 2 :
                student = criaNovo();
                minha_lista = insere_inicio(minha_lista, student);
                break;
            case 3 :
                student = criaNovo();
                printf("Digite valor a posicao na lista\n");
                scanf("%d",&posicao);
                Lista *p = minha_lista;
                minha_lista = insere_posicao(minha_lista,p,student, posicao, 1);

                break;
            case 4 :
                student = criaNovo();
                Lista *q = minha_lista;
                Lista *r = NULL;
                insere_ordenado(minha_lista,q,r,student);

                break;
            case 5 :
                    printf("Digite a matricula que deseja remover:\n");
                    scanf("%d", &matricula);
                    Lista *s = minha_lista;
                    Lista *t = NULL;
                    minha_lista = remove_aluno(minha_lista, s,t,matricula);
                break;
            case 6 :
                    printf("Digite a matricula que deseja procurar:\n");
                    scanf("%d", &matricula);
                    buscar_lista(minha_lista,matricula);
                break;
            case 7 :
                if (lista_vazia(minha_lista)){
                    printf("Lista Vazia\n");
                } else{
                    imprime_lista(minha_lista);
                    printf("Final da lista\n");
                }
                break;
            case 8 :
                total = quantidade(minha_lista,0);
                printf("A quantidade de alunos eh: %d\n",total);
                break;
            case 9 :
                printf("Digite a matricula que deseja procurar:\n");
                scanf("%d", &matricula);
                cont = indicar_indice(minha_lista,matricula,0);
                printf("Indice do Aluno na lista: %d \n",cont);
                break;
            case 10 :
                 if (!lista_vazia(minha_lista)){
                    libera_lista(minha_lista);
                    minha_lista = cria_lista();
                }
                break;

            case 11 :
                    total = quantidade(minha_lista,0);
                    Lista *u = (Lista*) malloc(total*sizeof(Lista));
                    Lista *v = minha_lista;
                    Lista *x = minha_lista;
                    for( i=0; i < total; i++){
                            u[i] = *v;
                            v = v->prox;
                    }
                    minha_lista = ordenar_lista(u,minha_lista,x,total,0);
                    free(u);

                break;

            case 12 :
                {
                    printf("Digite o nome do arquivo:(por favor colocar .txt)\n");
                    scanf("%s", nomeArquivo);
                    printf("Digite o tipo de arquivo que deseja criar\n");
                    printf("1 - Arquivo Texto\n");
                    printf("2 - Arquivo Binario\n");
                    scanf("%d", &escolha);
                    if( escolha == 1){
                        criar_arquivotexto(nomeArquivo,minha_lista);
                    }
                    if( escolha == 2)
                    {
                        criar_arquivobinario(nomeArquivo,minha_lista);
                    }

                }
                break;

            case 13 :
                {
                    libera_lista(minha_lista);
                    minha_lista = cria_lista();
                    printf("Digite o nome do arquivo:(por favor colocar .txt)\n");
                    scanf("%s", nomeArquivo);
                    printf("Qual o tipo de arquivo?\n");
                    printf("1 - Arquivo Texto\n");
                    printf("2 - Arquivo Binario\n");
                    scanf("%d", &escolha);
                    if( escolha == 1){
                        minha_lista = abrir_arquivoTexto(nomeArquivo,minha_lista);
                    }
                    if( escolha == 2){
                        minha_lista = abrir_ArquivoBinario(nomeArquivo,minha_lista);
                    }
                }
                break;
        }
    }

    return 0;
}
