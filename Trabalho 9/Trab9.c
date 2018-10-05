
#include <stdio.h>
#include <stdlib.h>

struct aluno{
    int matricula;
    char nome[30];
    float notas[3];
    float media;
    int faltas;
};

typedef struct aluno Aluno;


struct arv {
	Aluno info;
	struct arv* esq;
	struct arv* dir;
};

typedef struct arv Arv;

/*Cadastra os dados do aluno*/
Aluno criaNovo(){
    Aluno novo;
    printf("Digite a matricula do aluno: ");
    scanf("%d",&novo.matricula);
    printf("Digite o nome do aluno: ");
    setbuf(stdin , NULL);
    scanf(" %[^\n]s", novo.nome);
    printf("Digite as 3 notas do aluno:\n");
    scanf("%f %f %f",&novo.notas[0],&novo.notas[1],&novo.notas[2]);
    novo.media = (novo.notas[0]+ novo.notas[1]+ novo.notas[2])/3;
    printf("Digite o numero de faltas do aluno:\n");
    scanf("%d", &novo.faltas);
    return novo;
}

/*Verifica se o conteudo da arvore  vazio*/
int vazia(Arv* a){
	return a == NULL;
}

/*Imprime o conteudo do aluno*/
void imprime(Aluno p){
    printf("Matricula:%d\n", p.matricula);
    printf("Nome:%s\n", p.nome);
    printf("Notas:%.2f %.2f %.2f\n", p.notas[0],p.notas[1],p.notas[2]);
    printf("Media:%.2f\n", ((p.notas[0]+p.notas[1]+p.notas[2])/3));
    printf("Faltas:%d\n", p.faltas);
}

void preOrdem(Arv* a){
	if (!vazia(a)){
		imprime(a->info);
		preOrdem(a->esq);
		preOrdem(a->dir);
	}
}

void posOrdem(Arv* a){
	if (!vazia(a)){
		posOrdem(a->esq);
		posOrdem(a->dir);
		imprime(a->info);
	}
}

void emOrdem(Arv* a){
	if (!vazia(a)){
		emOrdem(a->esq);
		imprime(a->info);
		emOrdem(a->dir);
	}
}
/*Funcao para inserir um elemento na arvore*/
void inserir_arvore(Arv ** a , Aluno student){
    Arv *p = NULL;
    if( *a == NULL){
        p = (Arv*) malloc(sizeof(Arv));
        p->info = student;
        p->dir = NULL;
        p->esq = NULL;
        *a = p;
        return ;
    }
    else{
        if( student.matricula < (*a)->info.matricula ){
            inserir_arvore(&(*a)->esq,student);
        }
        if( student.matricula > (*a)->info.matricula ){
            inserir_arvore(&(*a)->dir,student);
        }
    }
}
/*Funcao auxiliar pra retornar o maior de dois inteiros */
int eh_maior(int a, int b){
    if( a > b){
        return a;
    }
    if( a < b ){
        return b;
    }
}

/*A funcao calcula a altura da subarvore da esquerda e da subarvore da direita e retorna a maior das duas para o usuario*/
int altura(Arv *a){
    if( (a == NULL) || ( a->esq == NULL && a->dir == NULL )){
        return 0;
    }
    else{
        return 1+eh_maior(altura(a->esq),altura(a->dir));
    }
}

/*Dado a matricula de um aluno, retorna a altura do mesmo    na arvore*/
int alturaAluno( Arv *a, int b){
    if( a != NULL  ){
        if(a->info.matricula == b){
            return 0;
        }
        else{
            if( b < a->info.matricula ){
                return 1+alturaAluno(a->esq,b);
            }
            if( b > a->info.matricula){
                return 1+alturaAluno(a->dir,b);
            }
        }
    }
        return -1;
}
/*A funcao retorna o numero de elementos com os campos da esquerda e direita iguais a NULO    */
int nfolhas(Arv *a){
    if( a == NULL){
        return 0;
    }
    if(a->esq == NULL && a->dir == NULL){
        return 1;
    }
    return nfolhas(a->esq)+nfolhas(a->dir);
}

/*A funcao retorna o numero de nós na arvore*/
int npai(Arv *a){
    if( a == NULL){
        return 0;
    }
    else{
        return 1+npai(a->esq)+npai(a->dir);
    }
}

/*Este buscar é para verificar se existe um elemento com tal matricula dentro da arvore*/
Arv* buscar(Arv **a, int b)
{
    if(!(*a)){
        return NULL;
    }

    if( b < (*a)->info.matricula ){
        buscar(&((*a)->esq), b);
    }
    else if( b > (*a)->info.matricula ){
        buscar(&((*a)->dir), b);
    }
    else if( b == (*a)->info.matricula ){
        return *a;
    }
}



/*A funcao verifica a altura de ambas as arvores, procurando aceitar uma diferença de apenas 1 no maximo*/
void eh_avl(Arv *a){
    if(  altura(a->dir) == altura(a->esq) ){
        printf("A arvore eh AVL\n");
    }
    else{
        if(altura(a->dir)+1 == altura(a->esq)){
            printf("A arvore eh AVL\n");
        }
        else{
            if( altura(a->esq)+1 == altura(a->dir)){
                printf("A arvore eh AVL\n");
            }
            else{
                printf("A arvore nao eh AVL\n");
            }
        }
    }
}

int main(){
    int op;
    Aluno maior_media;
    maior_media.media = 0;


    int matriculatemp;
    Aluno student;
    Arv* minha_arvore = NULL;
    while(op != 11){
        printf("1 - Inserir um novo aluno na arvore\n");
        printf("2 - Percorrer arvore usando in-order\n");
        printf("3 - Percorrer arvore usando pre-order\n");
        printf("4 - Percorrer arvore usando pos-order\n");
        printf("5 - Retornar a altura da arvore\n");
        printf("6 - Rertornar altura do aluno atraves da matricula\n");
        printf("7 - Retornar o numero de folhas da arvore\n");
        printf("8 - Retornar o numero de no's da arvore\n");
        printf("9 - Retornar o aluno com maior media\n");
        printf("10 - Verifica se eh AVL \n");
        printf("11 - Sair do Programa\n");
        scanf("%d",&op);
        switch (op){
            case 1 :{
                student = criaNovo();
                inserir_arvore(&minha_arvore,student);
                if( student.media > maior_media.media){
                    maior_media = student;
                }
            }
                break;
            case 2 :
                emOrdem(minha_arvore);
                break;
            case 3 :
                preOrdem(minha_arvore);
                break;
            case 4 :
                posOrdem(minha_arvore);
                break;
            case 5 :{
                Arv *p = minha_arvore;
                printf("A altura eh:%d\n",altura(p));
                break;
                }
            case 6 :{
                Arv *q = minha_arvore;
                Arv *x = minha_arvore;
                printf("Digite o numero de matricula:\n");
                scanf("%d",&matriculatemp);
                if(buscar(&x,matriculatemp) != NULL){
                    printf("O aluno se encontra na altura:%d\n",alturaAluno(q,matriculatemp));
                }
                else{
                    printf("O aluno nao se encontra na arvore\n");
                }
                break;
                }
            case 7 :{
                Arv *r = minha_arvore;
                printf("O numero de folhas eh:%d\n",nfolhas(r));
                break;
                }
            case 8 :{
                Arv *s = minha_arvore;
                printf("O numero de nos pais eh:%d\n",npai(s));
                break;
                }
            case 9 :
                imprime(maior_media);
                break;

            case 10 :{
                Arv *u = minha_arvore;
                eh_avl(u);
                }
                break;
        }
    }
	return 0;
}
