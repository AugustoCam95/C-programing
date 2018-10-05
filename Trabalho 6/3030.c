#include <stdio.h>
#include <string.h>

struct Aluno
{
   char name[50];
   int height;
};



int main(){
    struct Aluno a[5],b[5];
    FILE *fptr;
    int i;
    int j = 5;
    fptr=fopen("file.txt","wb");

    char n[50];
    for(i = 0;i < 5;i++){
        printf("Nome:");
        scanf("%s",&n);
        strcpy(a[i].name, n);
        printf("Altura:");
        scanf("%d",&a[i].height);
    }
    fwrite(&j,sizeof(int),1,fptr);
    fwrite(a,sizeof(a),1,fptr);
    fclose(fptr);

    return 0;

}
