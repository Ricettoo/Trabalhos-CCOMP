#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Função para verificar se uma palavra é aceita
int Verificar(int EstInic, int QtdEstadoFinal, int* EstadosFinais, int QtdSimb, char* Simb, int Transicao[50][50], char* PalavraTeste) {
    int EstAtual = EstInic;

    // Encontra o índice do símbolo no alfabeto
    for (int i = 0; i < strlen(PalavraTeste); i++) {
        int simbIndex = -1;
        for (int j = 0; j < QtdSimb; j++) { 
            if (PalavraTeste[i] == Simb[j]) {
                simbIndex = j;
                break;
            }
        }
        // Se não está no alfabeto, rejeita a palavra
        if (simbIndex == -1) {
        	printf("Simb %c invalido\n",PalavraTeste[i]);
            return 0;
        }
        // Transição para o próximo estado
        EstAtual = Transicao[EstAtual-1][simbIndex];
    }

    // Verifica se o EstAtual é um estado de aceitação
    for (int i = 0; i < QtdEstadoFinal; i++) {
        if (EstAtual == EstadosFinais[i]) {
            return 1;
        }
    }

    return 0;
}

int main() {
    int EstInic, QtdEstados, QtdEstadoFinal, QtdSimb;
    int Transicao[50][50];
    int EstadosFinais[50];
    char PalavraTeste[100];
    char Simb[10];

    // Informações do usuário
    printf("\nDigite o estado inicial: ");
    scanf("%d", &EstInic);
    printf("\nDigite a quantidade de Estados: ");
    scanf("%d", &QtdEstados);
    printf("\nDigite a quantidade de Estados Finais: ");
    scanf("%d", &QtdEstadoFinal);

    for (int i = 0; i < QtdEstadoFinal; i++) {
        printf("\nDigite o %d estado final: ", (i + 1));
        scanf("%d", &EstadosFinais[i]);
    }

    printf("\nDigite a Quantidade de Simbolos no Alfabeto: ");
    scanf("%d", &QtdSimb);

    for (int i = 0; i < QtdSimb; i++) {
        printf("\nDigite o %d Simbolo: ", (i + 1));
        scanf(" %c", &Simb[i]);
    }

    // Preenchimento da tabela de transição (estado/símbolo)
    printf("\nCOMPLETE A TABELA DE TRANSICAO\n");
    for (int i = 0; i < QtdEstados; i++) {
        for (int j = 0; j < QtdSimb; j++) {
            printf("Preencha a transicao %d,%d: ", (i+1), (j+1));
            scanf("%d", &Transicao[i][j]);
        }
    }

    // Exibição da tabela de transição
    printf("\n==== TABELA DE TRANSICAO ====\n");
    printf("\nEstado");
    for (int i = 0; i < QtdSimb; i++) {
        printf(" | %c", Simb[i]);
    }
    printf("\n");

    for (int i = 0; i < QtdEstados; i++) {
        printf("Q%d     ", i);
        for (int j = 0; j < QtdSimb; j++) {
            printf("| %d ", Transicao[i][j]);
        }
        printf("\n");
    }


    //repeticao para testar letras + de uma vez
    while (true){
     
        printf("\nDigite a palavra a ser testada: ");

        scanf(" %s", PalavraTeste);

        int resultado = Verificar(EstInic,QtdEstadoFinal,EstadosFinais,QtdSimb,Simb,Transicao,PalavraTeste);

        if(resultado == 1) {
            printf("A palavra '%s' foi aceita\n", PalavraTeste);
            
        } else {
            printf("A palavra '%s' NAO foi aceita\n", PalavraTeste);
        }
    }       
}