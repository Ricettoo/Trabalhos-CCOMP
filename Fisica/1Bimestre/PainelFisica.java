package Segundo_Ano.Fisica;

import javax.swing.JOptionPane;

//• • 16 Um trenó com um pinguim, pesando 80 N, esá em repouso sobre uma ladeira de ânulo ) = 20º com a horizontal (Fig. 6-23). 
//Entre o trenó e a ladeira, o coeiciente de arito estático é 0,25 e o coeiciente de atrito cinético é 0,15.
// (a) Qual é o menor módulo da força P, paralela ao plano, que impede o trenó de deslizar ladeira abaixo?
// (b) Qual é o menor módulo F que faz o trenó começar a subir a ladeira?
// (c) Qual é o valor de F que faz o renó subir a ladeira com velocidade constante?
//imagem: https://imgur.com/a/imk6tll
    
public class PainelFisica{
    public static void main(String [] args){
        double N; // N é a força normal
        double angulo;
        double atritoEstat; //μs
        double atritoCinet;//μk


        //painel para Imput 
        
        String Nimput = JOptionPane.showInputDialog("Digite o valor de N(Peso)");
        N = Double.parseDouble(Nimput);
        
        String anguloImput = JOptionPane.showInputDialog("Digite o angulo em graus");
        angulo = Double.parseDouble(anguloImput);
        
        String atritoEstatImput = JOptionPane.showInputDialog("Digite o atrito estatico");
        atritoEstat = Double.parseDouble(atritoEstatImput);
        
        String atritoCinetImput = JOptionPane.showInputDialog("Digite o atrito Cinetico");
        atritoCinet = Double.parseDouble(atritoCinetImput);

        //transformacao de angulo para radius

        double angRadiano = Math.toRadians(angulo);
        double cosseno = Math.cos(angRadiano);
        double seno = Math.sin(angRadiano);

        //menor modulo da forca P que impede o treno de deslizar ladeira abaixo

        double menorModuloP = (N * seno) - (atritoEstat * (N * cosseno));
        String menorModuloPFormatado = String.format("%.2f",menorModuloP);


        //menor modulo da forca F que afaz o treno comecar a subir a ladeira

        double menorModuloF = (N * seno) + (atritoEstat * (N * cosseno));
        String menorModuloFFormatado = String.format("%.2f",menorModuloF);

        //Valor de F que faz o treno subir a ladeira com velocidade constante

        double ForcaPraSubir = (N * seno) + (atritoCinet * (N* cosseno));
        String ForcaPraSubirFormatado = String.format("%.2f",ForcaPraSubir);

        JOptionPane.showMessageDialog(null,"menor Modulo que impede da forca P que impede o treno de deslizar ladeira abaixo ≈ " + menorModuloPFormatado +
        "\nmenor modulo da forca F que faz o treno subir a ladeira ≈ " + menorModuloFFormatado + 
        "\nvalor de F que faz o treno subir a ladeira com velocidade constante ≈ " + ForcaPraSubirFormatado);
    }           
}