#include <stdio.h>
#include <locale.h>
#include <string.h> // biblioteca para fun��es srtcpy e strcat (utilizei para "concatenar as strings dos pratos com as trings das bebidas)
int main() {
    /*  informar os pratos tipicos e  as bebidas;
        receber as escolhas do usu�rio;
        informar a o prato, bebida escolhida e quantidade total de calorias com base na escolha do usu�rio;
        tabela de calorias:
                                  pratos           |           bebidas
                            salvadorenho 545cal           suco de laranja 80cal
                            japon�s      324cal           ch�             30cal
                            italiano     750cal           refrigerante    90cal
     */
    setlocale(LC_ALL, "");
    int escolha;        // para armazenar a escolha dos pratos e bebidas;
    char pedido[100];   // para armazenar o prato e a bebida;
    int calorias;       // para armazenar as calorias de cada escolha;

    printf("\t\t\tSeja bem-vindo! \nFa�a se pedido e saiba o consumo calorias!\n");
    printf("Digite: 1 - para Prato Salvadorenho | 2 - para Prato Japon�s | 3 - para Prato Italiano:\n Op��o escolhida: ");
    scanf("%d",&escolha);
    switch (escolha) {
        case 1: calorias = 545;
            strcpy(pedido,"Prato Salvadorenho "); //com a fun��o strcpy eu quero dizer: pedipo="Prato Salvadorenho";
            break;
        case 2: calorias = 324;
            strcpy(pedido,"Prato Japon�s"); //Ao inv�s de pedido="Prato Japon�s ";
            break;
        case 3: calorias = 750;
            strcpy(pedido,"Prato Italiano"); // Ao inv�s de  pedido="Prato Italiano ";
            break;
    }

    printf("\tOp��es de bedida: \n\b 1 para Ch� | 2 para Suco de laranja | 3 para Refrigerante \nOp��o Escolhida: ");
    //\t para tab,\n para pular linha,\b para alinhar o texto no canto.
    scanf("%d", &escolha);

    switch (escolha) {
        case 1:
            calorias += 30;
            strcat(pedido, " + ch�"); // Aqui, usei a fun��o strcat para "concatenar as strings de caracteres"
            break;
        case 2:
            calorias += 80;
            strcat(pedido, " + Suco de Laranja"); //ao inves de pedido+="Suco de laranja";
            break;
        case 3:
            calorias += 90;
            strcat(pedido, " + Refrigerante");
    }
    printf("\n Pedido: %s \n total de calorias: %d",pedido,calorias);
    return 0;
}

