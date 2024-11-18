#include <stdio.h>
#include <stdlib.h>
#include <time.h>

  //Trabalho de Ordenaçao
  //Gabriel Ricetto Da Rocha

int comparacao = 0;
int movimento = 0;

void bubbleSort(int vetor[], int n) {
    comparacao = 0;
    movimento = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparacao++;
            if (vetor[j] > vetor[j + 1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
                movimento += 3;
            }
        }
    }
}

void selectionSort(int vetor[], int n) {
    comparacao = 0;
    movimento = 0;
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            comparacao++;
            if (vetor[j] < vetor[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = vetor[i];
            vetor[i] = vetor[minIndex];
            vetor[minIndex] = temp;
            movimento += 3;
        }
    }
}

void insertionSort(int vetor[], int n) {
    comparacao = 0;
    movimento = 0;
    for (int i = 1; i < n; i++) {
        int chave = vetor[i];
        int j = i - 1;
        while (j >= 0 && vetor[j] > chave) {
            comparacao++;
            vetor[j + 1] = vetor[j];
            j--;
            movimento++;
        }
        vetor[j + 1] = chave;
        movimento++;
    }
}

void gerarVetorAleatorio(int vetor[], int n) {
    for (int i = 0; i < n; i++) {
        vetor[i] = rand() % 10000;
    }
}

void gerarVetorOrdenado(int vetor[], int n) {
    for (int i = 0; i < n; i++) {
        vetor[i] = i;
    }
}

void gerarVetorInverso(int vetor[], int n) {
    for (int i = 0; i < n; i++) {
        vetor[i] = n - i;
    }
}

void copiarVetor(int origem[], int destino[], int n) {
    for (int i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
}

void executarTeste(int vetor[], int n, void (*sortFunc)(int[], int), const char *nomeAlgoritmo) {
    int *copiaVetor = (int *)malloc(n * sizeof(int));
    clock_t inicio, fim;
    double tempo_execucao;

    printf("\nResultados para %s:\n", nomeAlgoritmo);

    // Teste com vetor aleatório
    gerarVetorAleatorio(vetor, n);
    copiarVetor(vetor, copiaVetor, n);
    inicio = clock();
    sortFunc(copiaVetor, n);
    fim = clock();
    tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Vetor Aleatorio - Comparacoes: %d, Movimentacoes: %d, Tempo: %f segundos\n", comparacao, movimento, tempo_execucao);

    // Teste com vetor ordenado
    gerarVetorOrdenado(vetor, n);
    copiarVetor(vetor, copiaVetor, n);
    inicio = clock();
    sortFunc(copiaVetor, n);
    fim = clock();
    tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Vetor Ordenado - Comparacoes: %d, Movimentacoes: %d, Tempo: %f segundos\n", comparacao, movimento, tempo_execucao);

    // Teste com vetor inverso
    gerarVetorInverso(vetor, n);
    copiarVetor(vetor, copiaVetor, n);
    inicio = clock();
    sortFunc(copiaVetor, n);
    fim = clock();
    tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Vetor Inverso - Comparacoes: %d, Movimentacoes: %d, Tempo: %f segundos\n", comparacao, movimento, tempo_execucao);

    free(copiaVetor);
}

int main() {
    int opcaoAlgoritmo, tamanho;
    int *vetor;
    int continuar = 1;

    srand(time(NULL));

    while (continuar) {
        printf("\nEscolha o algoritmo de ordenacao:\n");
        printf("1. BubbleSort\n");
        printf("2. SelectSort\n");
        printf("3. InsertSort\n");
        printf("Opcao: ");
        scanf("%d", &opcaoAlgoritmo);

        printf("\nEscolha o tamanho do vetor:\n");
        printf("1. 100\n");
        printf("2. 1000\n");
        printf("3. 10000\n");
        printf("4. 100000\n");
        printf("Opcao: ");
        scanf("%d", &tamanho);

        switch (tamanho) {
            case 1: tamanho = 100; break;
            case 2: tamanho = 1000; break;
            case 3: tamanho = 10000; break;
            case 4: tamanho = 100000; break;
            default: printf("Tamanho invalido!\n"); return 1;
        }

        vetor = (int*)malloc(tamanho * sizeof(int));

        switch (opcaoAlgoritmo) {
            case 1:
                executarTeste(vetor, tamanho, bubbleSort, "BubbleSort");
                break;
            case 2:
                executarTeste(vetor, tamanho, selectionSort, "SelectSort");
                break;
            case 3:
                executarTeste(vetor, tamanho, insertionSort, "InsertSort");
                break;
            default:
                printf("Opcao invalida!\n");
                free(vetor);
                return 1;
        }

        printf("\nDeseja realizar outro teste? (1 - Sim, 0 - Nao): ");
        scanf("%d", &continuar);

        free(vetor);
    }

    printf("\nPrograma encerrado.\n");
    return 0;
}
