
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    /*Objetivo: Elaborar um algoritmo que receba altura e sexo de uma pessoa;
      calcular e imprimir o peso ideal de acordo com a altura e sexo; com base na formula:
      Para homens (72.2 * altura)-58;
      Para mulheres (62.1 * altura)-44.7
     */

    setlocale(LC_ALL,"portuguese");
    char sexo;
    float altura,pesoIdeal;

    printf("Informe o sexo: 'f' ou 'm': ");
    sexo= getchar();
    printf("Informe sua altura: ");
    scanf("%f",&altura);

    if (sexo=='m' || sexo=='M'){
        pesoIdeal = (72.7 * altura) - 58;
    }
    else if (sexo == 'f' || sexo == 'F') {
        pesoIdeal = (62.1 * altura) - 44.7;
    }
    else{
        printf("Sexo inválido. Por favor insira 'm' ou 'f'");
        return 0;
    }

    printf("\nSexo: %c \n",sexo);
    printf("Altura: %.2f\n",altura);
    printf("Peso ideal: %.2f kg",pesoIdeal);

    return 0;
}