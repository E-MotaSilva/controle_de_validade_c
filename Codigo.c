#include <stdio.h>
#include <string.h>

// variaveis globais

int escolha, escCenario, totalprodutos = 0;

// struct para armazenar os dados dos produtos

struct produto {
        char nome[50];
        char industria [50];
        char data[20];
        char loja[50];
        char responsavel[50];
        int quantidade;
        int soma;
    };

// #define para definir o maximo de produtos que podem ser cadastrados, evitando problemas de memoria

#define maxProdutos 10000

// array de struct usando o #define para limitar o numero de produtos cadastrados nesse struct
// facil manutencao caso seja preciso aumentar o numero de produtos, basta mudar o valor do #define

struct produto produtos[maxProdutos];

// funcoes trazidas aqui para evitar erro de continuidade

void opcaomenu();
void cadastro();
void cenario();
void produtoscad();
void industriascad();
void lojascad();
void responsavelscad();
void datascad();

// menu principal do sistema

void menu(){

    printf(" -- Controle de vencimentos -- \n\n");
    printf("1 - Cadastrar produto\n");   // Cadastra produto, industria, data, loja, responsavel
    printf("2 - Cenario\n");   // Mostra situacao dos produtos cadastrados
    printf("3 - Sair\n");   // Encerra o sistema
    printf("Escolha uma opcao: ");
    scanf("%d", &escolha);   // Entrada de dados do usuario
    getchar();   // Limpa buffer do teclado para evitar problemas com o fgets usado no cadastro
}

// switches de escolha do menu

void opcaomenu(){

    switch(escolha){

        case 1:
            cadastro(); // funcao de cadastro
        break;
        
        case 2:
            cenario(); // funcao de cenario que mostra os produtos cadastrados
        break;

        case 3:
            printf("Saindo do programa...\n");
        break;
    }

}

// funcao de cadastrar produto

void cadastro(){

    // usado fgets para ler strings com espacos
    // sizeof para limitar o tamanho da string
    // stdin indicando que a entrada de dados vem do teclado e nao de um arquivo

    printf("\n--- Cadastro de produto ---\n\n");
    printf("Nome do produto: ");
    fgets(produtos[totalprodutos].nome, sizeof(produtos[totalprodutos].nome), stdin);
    printf("Industria: ");
    fgets(produtos[totalprodutos].industria, sizeof(produtos[totalprodutos].industria), stdin);
    printf("Data de vencimento: ");
    fgets(produtos[totalprodutos].data, sizeof(produtos[totalprodutos].data), stdin);
    printf("Loja: ");
    fgets(produtos[totalprodutos].loja, sizeof(produtos[totalprodutos].loja), stdin);
    printf("Responsavel: ");
    fgets(produtos[totalprodutos].responsavel, sizeof(produtos[totalprodutos].responsavel), stdin);
    printf("Quantidade: ");
    scanf("%d", &produtos[totalprodutos].quantidade);
    getchar();
    totalprodutos++;  // incrementa o total de produtos cadastrados para a proxima entrada
    printf("\nCadastro concluido\n\n");
}

// menu cenario

void cenario(){
    do{
        printf("\n--- Cenario ---\n\n");
        printf("1 - Produtos\n");   // visualiza os produtos cadastrados e a quantidade de cada um
        printf("2 - Industria\n");   // visualizacao por industria, mostrando a quantidade total de produtos de cada industria
        printf("3 - Loja\n");   // visualizacao por loja
        printf("4 - Responsavel\n");  // visualizacao por responsavel
        printf("5 - Data de vencimento\n");  // visualizacao por data de vencimento
        printf("6 - Voltar para menu\n");  // volta para o menu principal
        printf("Escolha uma opcao: ");  
        scanf("%d", &escCenario);  // entrada de dados do usuario

            switch(escCenario){   // switch para menu
                case 1:
                    produtoscad();  // funcao produtos
                break;
                    
                case 2:
                    industriascad();  // funcao industria
                break;

                case 3:
                    lojascad();  // funcao loja
                break;

                case 4:
                    responsavelscad();  // funcao responsavel
                break;

                case 5:
                    datascad();  // funcao data de vencimento
                break;

                case 6:
                    printf("\nVoltando para o menu principal...\n\n");
                break;
            }
    }while(escCenario != 6);   // repeticao para que o usuario escolha quando voltar para o menu principal
}

// nas funcoes abaixo foram usadas:

// loop for para evitar que o mesmo produto/loja/responsavel/data/industria seja mostrado varias vezes
// strcmp para comparar strings e verificar se o produto ja foi mostrado
// soma para contar a quantidade total de cada produto

void produtoscad(){

    printf("\n--- Produtos cadastrados ---\n\n");

        for(int i = 0; i < totalprodutos; i++) {

            int jaMostrado = 0;

            for(int k = 0; k < i; k++) {

                if(strcmp(produtos[i].nome, produtos[k].nome) == 0) {

                    jaMostrado = 1;

                    break;
                }
            }

            if(jaMostrado)
            continue;

            int soma = 0;

            for(int j = 0; j < totalprodutos; j++) {

                if(strcmp(produtos[i].nome, produtos[j].nome) == 0) {
                
                    soma += produtos[j].quantidade;
                }
            }

            printf("%s %d\n", produtos[i].nome, soma);
        }
}

void industriascad(){

    printf("\n--- Industrias cadastradas ---\n\n");

    for(int i = 0; i < totalprodutos; i++){

        int jaMostrado = 0;

        for(int k = 0; k < i; k++) {

            if(strcmp(produtos[i].industria, produtos[k].industria) == 0) {

                jaMostrado = 1;
                break;
            }
        }

        if(jaMostrado)
        continue;

        int soma = 0;

        for(int j = 0; j < totalprodutos; j++) {

            if(strcmp(produtos[i].industria, produtos[j].industria) == 0) {

                soma += produtos[j].quantidade;
            }
        }

        printf("%s %d\n", produtos[i].industria, soma);
    }
}

void lojascad(){

    printf("\n--- Lojas cadastradas ---\n\n");

    for(int i = 0; i < totalprodutos; i++){

        int jaMostrado = 0;

        for(int k = 0; k < i; k++) {

            if(strcmp(produtos[i].loja, produtos[k].loja) == 0) {

                jaMostrado = 1;
                break;
            }
        }

        if(jaMostrado)
        continue;

        int soma = 0;

        for(int j = 0; j < totalprodutos; j++) {

            if(strcmp(produtos[i].loja, produtos[j].loja) == 0) {

                soma += produtos[j].quantidade;
            }
        }

        printf("%s %d\n", produtos[i].loja, soma);
    }
}

void responsavelscad(){

    printf("\n--- Responsaveis cadastrados ---\n\n");

    for(int i = 0; i < totalprodutos; i++){

        int jaMostrado = 0;

        for(int k = 0; k < i; k++) {

            if(strcmp(produtos[i].responsavel, produtos[k].responsavel) == 0) {

                jaMostrado = 1;
                break;
            }
        }

        if(jaMostrado)
        continue;

        int soma = 0;

        for(int j = 0; j < totalprodutos; j++) {

            if(strcmp(produtos[i].responsavel, produtos[j].responsavel) == 0) {

                soma += produtos[j].quantidade;
            }
        }

        printf("%s %d\n", produtos[i].responsavel, soma);
    }
}

void datascad(){

    printf("\n--- Datas de vencimento cadastradas ---\n\n");

    for(int i = 0; i < totalprodutos; i++){

        int jaMostrado = 0;

        for(int k = 0; k < i; k++) {

            if(strcmp(produtos[i].data, produtos[k].data) == 0) {

                jaMostrado = 1;
                break;
            }
        }

        if(jaMostrado)
        continue;

        int soma = 0;

        for(int j = 0; j < totalprodutos; j++) {

            if(strcmp(produtos[i].data, produtos[j].data) == 0) {

                soma += produtos[j].quantidade;
            }
        }

        printf("%s %d\n", produtos[i].data, soma);
    }
}

int main(){
    do{
        menu();
        opcaomenu();
    }while(escolha != 3);

    return 0;
}
