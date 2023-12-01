#include <stdio.h>
#include <stdlib.h>
#define TAM 2
struct aluno {
    char nome[50];
    int idade;
    char faixa[20];
};
int main() {
    struct aluno ficha[TAM];
    int i;
    printf("preencha a ficha: \n");
    for (i=0;i<TAM;i++){
        printf("Digite o nome do %d atleta:\n ", i+1);
        scanf("%s",&ficha[i].nome);
        fflush(stdin);
        printf("Digite a idade atleta:\n ");
        scanf("%d",&ficha[i].idade);
        fflush(stdin);
        printf("Faixa do atleta:\n ");
        scanf("%s",&ficha[i].faixa);
        fflush(stdin);
    }

    for (i=0;i<TAM;i++){
        printf("Atleta: %s \n ",ficha[i].nome);
        printf(" Idade do  Atleta: %d\n ",ficha[i].idade);
        printf("Graduação do atleta: %s\n ",ficha[i].faixa);
    }
    return 0;
}
