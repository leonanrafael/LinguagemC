#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#define TAM 9999

struct atendimento{
    char nome[50];
    char cpf[15];
    int tipoAtendimento;
};
void menuPrincipal();
//*** cadastrar  atendimentos ***
void cadastrarAtend(struct atendimento *atendimentos, int *atR, int *i);

//*** listar atendimentos realizados ***
void listarAtr( struct atendimento *atendimentos , int atR);

//*** listar atendimentos realizados  por tipo ***
void listarAtrTipo(struct atendimento *atendimentos, int atR);

int main(){
    setlocale(LC_ALL,"");
    struct atendimento atendimentos[TAM];
    int i = 0;
    int atR = 0; // *** atendimentos realizados ***
    int op; // *** (opção) variavel que vai controlar o fluxo da função main  ***
    do {
        system("cls");
        menuPrincipal();
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            system("cls");
            cadastrarAtend(atendimentos, &atR, &i);
            break;
        case 2:
            system("cls");
            listarAtr(atendimentos, atR);
            break;
        case 3:
            system("cls");
            listarAtrTipo(atendimentos, atR);
            break;
        case 4:
        system("cls");
        printf("****************************\n");
        printf("*   Saindo do Sistema...   *\n");
        printf("****************************\n");
        printf("**********************************\n");
        printf("*   Agradecemos a preferência   *\n");
        printf("**********************************\n");
                system("pause");
        break;
        default:
        system("cls");
        printf("********************************************************************************\n");
        printf("* OPS! Opção de navegação inválida. Tente novamente com uma das opções do menu *\n");
        printf("********************************************************************************\n");
        system("pause");
            break;
        }
    } while(op!=4);
    return(0);
}
void menuPrincipal(){
    printf("\nBem-vindo ao sistema de atendimento\n");
        printf("1 - Solicitar Atendimento\n");
        printf("2 - Listar Atendimentos Registrados\n");
        printf("3 - Listar Atendimento por Setor\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
}

void cadastrarAtend(struct atendimento *atendimentos, int *atR, int *i){
    int nomeValidado = 0;
    int cpfValidado = 0;
    // *** realizar cadastro Se  o numero de atendimentos realizados não for maior que o indicado na variavel atendimentos[TAM]
    if (*atR < TAM){
        do{// *** não permitir que o usuário use numeros ao preencher o nome ***
            printf("\nDigite o nome: ");
            scanf(" %50[^\n]s",atendimentos[*i].nome);
            for(int j = 0; j < strlen(atendimentos[*i].nome); j++){
                if(isdigit(atendimentos[*i].nome[j])){
                    nomeValidado = 0;
                    system("cls");
                    printf("*************************************************************\n");
                    printf("* Não é permitido colocar números no nome. Tente novamente! *\n");
                    printf("*************************************************************\n");
                    system("pause");
                    system("cls");
                    break;
                } else {
                    nomeValidado = 1;
                }
            }
        }while(nomeValidado != 1);
        do{
            printf("Digite o cpf:");
            scanf(" %15[^\n]s",atendimentos[*i].cpf);

            //*** loop para verificar se todos caracteres digitados são números ***
            for(int j = 0; j < strlen(atendimentos[*i].cpf); j++){
                if(!isdigit(atendimentos[*i].cpf[j])){
                    cpfValidado = 0;
                    system("cls");
                    printf("**************************************************************\n");
                    printf("* O CPF não deve conter letras ou símbolos. Tente novamente! *\n");
                    printf("**************************************************************\n");
                    system("pause");
                    break;
                } else {
                    cpfValidado = 1;
                }
            }
            system("cls");
        }while(cpfValidado !=1);

        //*** loop para validação do tipo de atendimento ***
        do{
            printf("Escolha o tipo de atendimento desejado:\n");
            printf("1 - Abertura de Conta\n");
            printf("2 - Caixa\n");
            printf("3 - Gerente Pessoa Física\n");
            printf("4 - Gerente Pessoa Jurídica\n");
            printf("Selecione a opção desejada:");
            scanf(" %d",&atendimentos[*i].tipoAtendimento);
            fflush(stdin);
            //*** desvio de Fluxo para o caso do usuario digitar um valor que não esteja entre 1 e 4 ***
            if ((atendimentos[*i].tipoAtendimento != 1) && (atendimentos[*i].tipoAtendimento != 2) && (atendimentos[*i].tipoAtendimento != 3) && (atendimentos[*i].tipoAtendimento != 4)){
                system("cls");
                printf("*******************************************************\n");
                printf("* O tipo -%d não é uma opção válida! Tente novamente! *\n",atendimentos[*i].tipoAtendimento);
                printf("*******************************************************\n");
                system("pause");
                system("cls");
            }
        //*** condição de parada do loop == digitar um valor entre 1 e 4 para o tipo de atendimento ***
        }while((atendimentos[*i].tipoAtendimento != 1) && (atendimentos[*i].tipoAtendimento != 2) && (atendimentos[*i].tipoAtendimento != 3) && (atendimentos[*i].tipoAtendimento != 4));
        (*i)++;
        (*atR)++;
        //*** caso atendimentos realizados == o valor de atendimentos[TAM] ***
    } else {
        printf("*******************************************************************************************************************\n");
        printf("* O número de atendimentos diário já foi atingido. Por favor, procure um de nossos colaboradores para te auxiliar *\n");
        printf("*******************************************************************************************************************\n");
    }
    system("pause");
}


void listarAtr( struct atendimento *atendimentos , int atR){
    if (atR > 0){
        printf("****************************************************\n");
        printf("*   Listagem de todos os atendimentos realizados   *\n"); 
        printf("****************************************************\n\n");
        for ( int i = 0; i < atR; i++)
        {
            printf(" Nome:%s\n",atendimentos[i].nome);
            printf(" CPF:%s\n",atendimentos[i].cpf);
            printf(" Setor de atendimento: %d",atendimentos[i].tipoAtendimento);
            printf("****************************************************\n");
            // *** Este switch é para imprimir a mensagem com o tipo de serviço com base no tipo de atendimento na hora da listagem ***
            switch (atendimentos[i].tipoAtendimento)
            {
            case 1:
                printf(" - Abertura de conta\n");
                break;
            case 2:
                printf(" - Caixa\n");
                break;
            case 3:
                printf(" - Gerente Pessoa Física\n");
                break;
            case 4:
                printf(" - Gerente Pessoa Jurídica\n");
                break;
            default:

                break;
            }
        }
    } else {
        printf("***********************************************************\n");
        printf("* Até o momento, não tivemos nenhum atendimento realizado *\n");
        printf("***********************************************************\n");
    }
    system("pause");
}

void listarAtrTipo(struct atendimento *atendimentos, int atR){
    int acha = 0;
    int tipo = 0;
    char msgTipo[50] = "";
    printf("Qual setor de atendimento deseja listar?\n");
    printf("1 - Abertura de Conta\n");
    printf("2 - Caixa\n");
    printf("3 - Gerente Pessoa Física\n");
    printf("4 - Gerente Pessoa Jurídica\n");
    printf("Selecione a opção desejada:");
    scanf("%d",&tipo);
    system("cls");
    if(tipo == 1)
        strcat(msgTipo, "1 - Abertura de conta\n");
    else if (tipo == 2)
        strcat(msgTipo, "2 - Caixa\n");
    else if (tipo == 3)
        strcat(msgTipo, "3 - Gerente Pessoa Física\n");
    else if (tipo == 4)
        strcat(msgTipo, "4 - Gerente Pessoa Jurídica\n");

    if(atR > 0){
        printf("Lista de atendimento do setor: %s\n",msgTipo);
        for (int i = 0; i < atR; i++){
            if (atendimentos[i].tipoAtendimento == tipo){
                acha = 1;
                printf(" nome: %s\n",atendimentos[i].nome);
                printf(" CPF: %s\n",atendimentos[i].cpf);
                printf(" Setor de atendimento: %s\n",msgTipo);
                printf("***********************************************************\n");
            }
        }
    }
    if(acha == 0){
        if( (tipo > 0) && (tipo <= 4) ){
        printf("********************************************************************************\n");
        printf("\tNenhum atendimento foi realizado no  setor: %s\n",msgTipo);
        }
        else{
        printf("****************************************************************************************\n");
        printf("*   O setor escolhido: %d - não existe. Tente novamente com uma opção de setor válida   *\n",tipo);
        printf("****************************************************************************************\n");
        }
    }
    system("pause");
}