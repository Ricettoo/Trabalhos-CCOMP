#include <windows.h>
#include <stdio.h>
#include <time.h>

// Função que representa a simulação a ser medida
void simulacaoCPU() {
    // Chamando a função X vezes, ela repete os 1.000.000 * QtdTeste
    for (int i = 0; i < 100000000; i++) {
        int resultado = i * i;
    }
}

// Função que representa a simulação a ser medida
void simulacaoMemoria() {
    // Chamando a função X vezes para criação de uma quantidade de pastas
    for (int i = 0; i < 500; i++) {
        FILE *arquivoTemp;
        char nomeArquivo[500];
        sprintf(nomeArquivo, "ARQ_TEMP_%d.txt", i);
        arquivoTemp = fopen(nomeArquivo, "w");
        if (arquivoTemp != NULL) {
            fclose(arquivoTemp);
        } else {
            printf("Erro ao criar o arquivo %s\n", nomeArquivo);
        }
    }
}

// Função para remover os arquivos temporários
void RemoveArqTemp() {
    // Função usada para dletar os Arquivos Temporários da Bench de Memória
    for (int i = 0; i < 500; i++) {
        char nomeArquivo[100];
        sprintf(nomeArquivo, "ARQ_TEMP_%d.txt", i);
        remove(nomeArquivo);
    }
}

int main() {
    int escolha;
    printf("Digite 1 ou 2 para escolher o benchmark:\n");
    printf("1 - Teste de CPU\n2 - Teste de Memoria\n");
    scanf("%d", &escolha);

    switch (escolha) {
    case 1:
        {
            int QtdTeste = 50;
            printf("Iniciando teste de CPU"); // Interface pra deixar mais apresentavel
            Sleep(500);
            printf(".");
            Sleep(500);
            printf(".");
            Sleep(500);
            printf(".\n");

            clock_t inicio = clock(); // inicia a contagem de tempo para comclusao do bench

            for (int i = 0; i < QtdTeste; i++) {
                simulacaoCPU(); // chama a função uma quantidade de vezes
                printf(".");
            }

            clock_t fim = clock(); // finaliza a contagem do bench

            double tempo_de_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC; // faz a conta de subtração e divisao para calcular o tempo de execuçao do bench

            printf("\nTempo total de execucao: %.3f segundos\n", tempo_de_execucao);  // Meu PC teve a media de 5.3 Segundos para execução, Ja o pc na universidade teve a media de 12 segundos

            if(tempo_de_execucao < 15){
                printf("O computador teve um otimo desempenho no tempo de execucao");
            } else{
                printf("O computador teve um mal desempenho no tempo_de_execucao");
            }
        }
        break;

    case 2:
        {
            int TTestes = 50;
            printf("Iniciando teste de Memoria"); // Interface para ficar mais apresentavel
            Sleep(500);
            printf(".");
            Sleep(500);
            printf(".");
            Sleep(500);
            printf(".\n");

            clock_t inicio = clock(); // Começa a contagem

            for (int i = 0; i < TTestes; i++) {
                simulacaoMemoria();
                RemoveArqTemp();
                printf(".");
            }

            clock_t fim = clock(); // Finaliza a contagem

            double tempo_de_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;

            printf("\nTempo total de execucao: %.3f segundos\n", tempo_de_execucao);

            if(tempo_de_execucao < 20){
                printf("O computador teve um otimo desempenho no tempo de execucao");
            } else{
                printf("O computador teve um mal desempenho no tempo_de_execucao");
            }  
        }
        break;

    default:
        printf("Numero nao reconhecido\n");
        break;
    }

    return 0;
}