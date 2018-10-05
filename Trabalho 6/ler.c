#include <stdio.h>


typedef struct {
        int matricula;
        char nome[50];
        float notas[3];
        int faltas;
}TStudent;

int main(){
    int i;
    int j;
    int tamTurma;
    TStudent *aluno;
    FILE *aptr,*ptr;
    aptr = fopen("leleco.txt","rb");
    ptr = fopen("tamTurma.txt","rb");
    fread(&tamTurma,sizeof(int),1,ptr);

    printf("Quantos elementos no arquivo:%d\n",j);
    for(i = 0; i < j; i++){
        fread(&aluno,sizeof(TStudent),1,aptr);
        printf("%s\n",aluno[i].nome);

    }
    fclose(aptr);
    fclose(ptr);

    return 0;
}
