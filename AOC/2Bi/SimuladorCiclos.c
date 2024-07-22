#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct {
    char OpCode[7]; 
    int Operando1;  
    int Operando2;
} Valores;

Valores valores[50];


void Limpar() {
    for (int i = 0; i < 50; i++) {
        strcpy(valores[i].OpCode, "");
        valores[i].Operando1 = 0; 
        valores[i].Operando2 = 0; 
    }
}

// Função para executar as instruções
void Execucao(Valores valores[], int *MBR, int posicao[], int total) {
    for (int i = 0; i < total; i++) {
        switch (atoi(valores[i].OpCode)) { // Converte OpCode para inteiro e verifica qual instrução executar
            case 1:
                *MBR = posicao[valores[i].Operando1]; // Carrega valor da posição de memória no MBR
                break;
            case 10:
                posicao[valores[i].Operando1] = valores[i].Operando2; // Armazena valor em uma posição de memória
                break;
            case 11:
                *MBR += posicao[valores[i].Operando1]; // Soma valor da posição de memória ao MBR
                break;
            case 100:
                *MBR -= posicao[valores[i].Operando1]; // Subtrai valor da posição de memória do MBR
                break;
            case 101:
                *MBR *= posicao[valores[i].Operando1]; // Multiplica valor da posição de memória pelo MBR
                break;
            case 110:
                *MBR /= posicao[valores[i].Operando1]; // Divide o MBR pelo valor da posição de memória
                break;
            case 111:
                i = valores[i].Operando1 - 1; // Salto incondicional para uma linha específica
                break;
            case 1000:
                if (*MBR == 0) { // Salto se MBR for zero
                    i = valores[i].Operando1 - 1;
                }
                break;
            case 1001:
                if (*MBR < 0) { // Salto se MBR for negativo
                    i = valores[i].Operando1 - 1;
                }
                break;
            case 1010:
                *MBR = sqrt(*MBR); // Calcula a raiz quadrada do MBR
                break;
            case 1011:
                *MBR = -*MBR; // Inverte o sinal do MBR
                break;
            case 1111:
                posicao[valores[i].Operando1] = *MBR; // Armazena valor do MBR em uma posição de memória
                break;
            case 1100:
                break;
            default:
                printf("Codigo invalido\n");
                break;
        }
    }
}

// Função para inserir valores nas instruções
void InsercaoValores(Valores valores[], int *total) {
    for (int i = 0; i < 50; i++) {
        printf("Digite o OpCode, Operando1 e Operando2 (opcional): ");
        scanf("%s %d %d", valores[i].OpCode, &valores[i].Operando1, &valores[i].Operando2);
        (*total)++;
        if (strcmp(valores[i].OpCode, "001100") == 0) { // Verifica se o código é 'No Operation'
            printf("Codigo de 'No operation' reconhecido\n");
            break;
        }
    }
}

void exibirTabela() {
    printf("=======================================================\n");
    printf("=               INSTRUCOES:                           =\n");
    printf("=======================================================\n");
    printf("=  COD   -  OP1   -  OP2   -  RESULTADOS              =\n");
    printf("=-----------------------------------------------------=\n");
    printf("= 000001 -  #POS  -        - MBR <- #POS              =\n");
    printf("= 000010 -  #POS  - #DADO  - #POS <- #DADO            =\n");
    printf("= 000011 -  #POS  -        - MBR <- MBR + #POS        =\n");
    printf("= 000100 -  #POS  -        - MBR <- MBR - #POS        =\n");
    printf("= 000101 -  #POS  -        - MBR <- MBR * #POS        =\n");
    printf("= 000110 -  #POS  -        - MBR <- MBR / #POS        =\n");
    printf("= 000111 -  #LIN  -        - JUMP to #LIN             =\n");
    printf("= 001000 -  #LIN  -        - JUMP IF Z to #LIN        =\n");
    printf("= 001001 -  #LIN  -        - JUMP IF N to #LIN        =\n");
    printf("= 001010 -        -        - MBR <- raiz_quadrada(MBR)=\n");
    printf("= 001011 -        -        - MBR <- - MBR             =\n");
    printf("= 001111 -  #POS  -        - #POS <- MBR              =\n");
    printf("= 001100 -        -        - NOP                      =\n");
    printf("=======================================================\n");
    printf("DIGITE A OPERACAO: \n(OPCODE/OP1/OP2)\n");
}

// Função para exibir os dados de memória
void exibirDados(int posicao[], int tamanho, int MBR) {
    printf("=================================\n");
    printf("=        Dados de Memoria       =\n");
    printf("=================================\n");
    for (int i = 0; i < tamanho; i++) {
        if (posicao[i] != 0) {
            printf("Posicao %d: %d\n", i, posicao[i]); // Exibe posições de memória que não são zero
        }
    }
    printf("MBR = %d\n", MBR); // Exibe o valor atual do MBR
}

void opcoes() {
    printf("=========================\n");
    printf("=        Opcoes         =\n");
    printf("=========================\n");
    printf("=       1-Inserir       =\n");
    printf("=       2-Ver instrucao =\n");
    printf("=       3-Ver Dados     =\n");
    printf("=       4-Executar      =\n");
    printf("=       5-Limpar        =\n");
    printf("=       6-Sair          =\n");
    printf("=========================\n");
    printf("opcao: ");
}

int main() {
    int opcao = 0;
    int MBR = 0; 
    int posicao[500] = {0}; 
    int total = 0; 

    while (1) {
        opcoes();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                InsercaoValores(valores, &total); // Chama função para inserir valores
                break;
            case 2:
                exibirTabela(); // Chama função para exibir a tabela de instruções
                break;
            case 3:
                exibirDados(posicao, 500, MBR); // Chama função para exibir dados de memória
                break;
            case 4:
                Execucao(valores, &MBR, posicao, total); // Chama função para executar instruções
                break;
            case 5:
                Limpar(); // Chama função para limpar as instruções
                break;
            case 6:
                printf("Saindo...\n");
                exit(0); // Sai do programa
                break;
            default:
                printf("Numero invalido\n");
                break;
        }
    }
    return 0;
}
