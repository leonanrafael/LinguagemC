#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
int main() {
    /*O programa deve receber o sal�rio de um funcionario e o c�digo do cargo;
      apresentar o cargo, o valor do aumento  e o novo sal�rio*/
    /*C�digo          Cargo           Percentual do Aumento
        1            Servente                 40%
        2            Pedreiro                 35%
        3         Mestre de Obras             20%
        4        T�cnico de Seguran�a         10%
    */
    setlocale(LC_ALL,"");
    float salario,aumento;
    int codigo;
    char cargo[30];

    printf("Informe o sal�rio: ");
    scanf("%f",&salario);
    printf("informe o c�digo do cargo: ");
    scanf("%d",&codigo);

    switch (codigo) {
        case 1: strcpy(cargo, "servente"); codigo = 1; aumento = salario*0.4;
            break;
        case 2: strcpy(cargo, "Pedreiro"); codigo = 2; aumento = salario*0.35;
            break;
        case 3: strcpy(cargo, "Mestre de Obras"); codigo = 3; aumento = salario*0.2;
            break;
        case 4:strcpy(cargo, "T�cnico de Seguran�a"); codigo = 4; aumento = salario*0.1;
            break;
    }
    printf(" Codigo: %d\n Cargo: %s\n Sal�rio: %.2f\n Aumento: %2.f\n Novo Sal�rio: R$%.2f\n",codigo,cargo,salario,aumento,salario+aumento);
    system("pause");
    return 0;
}