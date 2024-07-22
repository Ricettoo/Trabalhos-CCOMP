import java.util.Scanner;

class Transicao {
    int proximoEstado;
    char escrever;
    char mover;

    Transicao() {
        this.proximoEstado = -1;
        this.escrever = ' ';
        this.mover = ' ';
    }
}

public class MaquinaDeTuring {

    static void TabelaDeTransicao(int qtdLetras, char[] alfabeto, int qtdEstados, Transicao[][] tabela) {
        System.out.println("=====Tabela de transicao=====");
        System.out.print("   ");
        for (int i = 0; i < qtdLetras; i++) {
            System.out.print(alfabeto[i] + "   ");
        }
        System.out.println();

        for (int i = 0; i < qtdEstados; i++) {
            System.out.printf("%02d ", i);
            for (int j = 0; j < qtdLetras; j++) {
                System.out.printf("%d,%d ",(i+1),(j+1));
            }
            System.out.println();
        }
    }

    static int buscarIndice(char c, char[] alfabeto, int qtdLetras) {
        for (int i = 0; i < qtdLetras; i++) {
            if (alfabeto[i] == c) {
                return i;
            }
        }
        return -1; // Caractere nao encontrado
    }

    static boolean estadoFinal(int estado, int[] estadosFinais, int qtdEstadosFinais) {
        for (int i = 0; i < qtdEstadosFinais; i++) {
            if (estado == estadosFinais[i]) {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int qtdLetras, qtdLetrasFamiliar;
        char[] alfabeto = new char[24], alfabetoFamiliar = new char[24];
        String palavra;
        char marcadorInicio, simboloVazio;
        int qtdEstados, estadoInicial, qtdEstadosFinais;
        int[] estadosFinais = new int[10];

        System.out.print("Digite a quantidade de letras do alfabeto: ");
        qtdLetras = scanner.nextInt();
        scanner.nextLine(); // Limpa o '\n' do scan

        for (int i = 0; i < qtdLetras; i++) {
            System.out.print("Digite a " + (i + 1) + "a letra: ");
            alfabeto[i] = scanner.nextLine().charAt(0);
        }

        System.out.print("\nDigite a quantidade de letras do alfabeto familiar: ");
        qtdLetrasFamiliar = scanner.nextInt();
        scanner.nextLine();

        for (int i = 0; i < qtdLetrasFamiliar; i++) {
            System.out.print("Digite a " + (i + 1) + "a letra: ");
            alfabetoFamiliar[i] = scanner.nextLine().charAt(0);
        }

        System.out.print("\nDigite a quantidade de estados: ");
        qtdEstados = scanner.nextInt();

        System.out.print("\nDigite o estado inicial: ");
        estadoInicial = scanner.nextInt();

        System.out.print("\nDigite a quantidade de estados finais: ");
        qtdEstadosFinais = scanner.nextInt();

        for (int i = 0; i < qtdEstadosFinais; i++) {
            System.out.print("\nDigite o " + (i + 1) + "o estado final: ");
            estadosFinais[i] = scanner.nextInt();
        }

        System.out.print("\nDigite um marcador de inicio: ");
        marcadorInicio = scanner.next().charAt(0);

        System.out.print("\nDefina um simbolo para vazio: ");
        simboloVazio = scanner.next().charAt(0);

        System.out.print("Digite a palavra a ser testada: ");
        scanner.nextLine();
        palavra = scanner.nextLine();

        int qtdLetrasTotal = qtdLetras + qtdLetrasFamiliar;
        char[] alfabetoTotal = new char[24];
        System.arraycopy(alfabeto, 0, alfabetoTotal, 0, qtdLetras);
        System.arraycopy(alfabetoFamiliar, 0, alfabetoTotal, qtdLetras, qtdLetrasFamiliar);

        Transicao[][] tabela = new Transicao[10][24];
        for (int i = 0; i < qtdEstados; i++) {
            for (int j = 0; j < qtdLetrasTotal; j++) {
                tabela[i][j] = new Transicao();
            }
        }

        TabelaDeTransicao(qtdLetrasTotal, alfabetoTotal, qtdEstados, tabela);

        System.out.println("obs: Digite -1 para quando nao houver transicao\nDigite as transicoes: ");

        for (int i = 0; i < qtdEstados; i++) {
            for (int j = 0; j < qtdLetrasTotal; j++) {
                System.out.printf("Digite o estado futuro da transicao: %d,%d\n", i + 1, j + 1);
                int proximoEstado;
                char escrever, mover;
                proximoEstado = scanner.nextInt();
                if (proximoEstado == -1) {
                    System.out.println("O campo sera anulado!\n-----------------------------------");
                    tabela[i][j].proximoEstado = -1;
                    tabela[i][j].escrever = ' ';
                    tabela[i][j].mover = ' ';
                } else {
                    System.out.printf("Digite o alfabeto futuro da transicao: %d,%d\n", i + 1, j + 1);
                    escrever = scanner.next().charAt(0);
                    System.out.printf("Digite a direcao da transicao: %d,%d (D para Direita ou E para Esquerda)\n", i + 1, j + 1);
                    mover = scanner.next().charAt(0);
                    System.out.println("---------------------------------------");
                    tabela[i][j].proximoEstado = proximoEstado;
                    tabela[i][j].escrever = escrever;
                    tabela[i][j].mover = mover;
                }
            }
        }

        int estadoAtual = estadoInicial;
        int posicaoCabeca = 0;
        char[] fita = palavra.toCharArray();

        while (true) {
            char simboloAtual = fita[posicaoCabeca];
            int indiceSimbolo = buscarIndice(simboloAtual, alfabeto, qtdLetras);

            if (indiceSimbolo == -1 || estadoAtual == -1) {
                break;
            }

            Transicao transicao = tabela[estadoAtual][indiceSimbolo];

            if (transicao.proximoEstado == -1) {
                break;
            }

            fita[posicaoCabeca] = transicao.escrever;
            estadoAtual = transicao.proximoEstado;

            if (transicao.mover == 'D') {
                posicaoCabeca++;
            } else if (transicao.mover == 'E') {
                posicaoCabeca--;
            }

            if (estadoFinal(estadoAtual, estadosFinais, qtdEstadosFinais)) {
                break;
            }
        }

        System.out.println("Resultado: "+ marcadorInicio + new String(fita));
    }
}
