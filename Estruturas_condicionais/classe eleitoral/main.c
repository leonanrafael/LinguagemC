#include <stdio.h>
#include <locale.h>
int main() {
    /* Objetivo:Receber a idade do usuário e definir sua classe eleitoral com base na idade;
       Menor que 16 anos: não eleitor;
       De 18 a 65 anos: eleitor obrigatório;
       Entre 16 e 18 e mais que 65 anos: Eleitor facultativo;
    */

    setlocale(LC_ALL,"Portuguese");
    int idade = 0;

    printf("Informe sua idade: ");
    scanf("%d", &idade);

    if (idade < 16) {
        printf("Não eleitor. ");
    } else {
        if (idade >= 18 && idade <= 65) {
            printf("Eleitor obrigatório");
        } else
            printf("Eleitor facultativo");
    }
    return (0);
}