
#include <stdio.h>
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
    int valido = 0; // variavel criada para validar a entrada da variavel <char sexo>


    do {
        printf(" Informe o sexo: 'f' ou 'm': ");
        scanf("%c",&sexo);
        printf(" Informe sua altura: ");
        scanf("%f", &altura);

        while ((getchar()) != '\n'); // Limpa o buffer de entrada

        if (sexo == 'm' || sexo == 'M') {
            pesoIdeal = (72.7 * altura) - 58;
            valido=1; // valor booleano = true
        } else if (sexo == 'f' || sexo == 'F') {
            pesoIdeal = (62.1 * altura) - 44.7;
            valido=1; // valor  booleano = true
        } else {
            printf("***************************************************************\n");
            printf(" Sexo inválido. Por favor insira: 'm' ou 'f'\n");
            valido=0; // valor booleano = false
        }
    } while (!valido); //Os comandos dentro desse bloco serão repetidos atá que o usuário digite 'm, M,f ou F' para a variavel: char sexo

    printf("\nSexo: %c \n",sexo);
    printf("Altura: %.2f\n",altura);
    printf("Peso ideal: %.2f kg",pesoIdeal);

    return 0;
}