import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class LeiDeGauss extends JFrame {
    private JTextField raioField;
    private JTextField densidadeField;
    private JTextField distanciaField;
    private JLabel resultadoLabel;

    public LeiDeGauss() {
        setTitle("Lei de Gauss - Campo Elétrico");
        setSize(300, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        JPanel painel = new JPanel();
        painel.setLayout(new BoxLayout(painel, BoxLayout.Y_AXIS));

        painel.add(new JLabel("Raio da esfera (cm):"));
        raioField = new JTextField();
        painel.add(raioField);

        painel.add(new JLabel("Densidade volumétrica (μC/m³):"));
        densidadeField = new JTextField();
        painel.add(densidadeField);

        painel.add(new JLabel("Distância (cm):"));
        distanciaField = new JTextField();
        painel.add(distanciaField);

        JButton calcularButton = new JButton("Calcular");
        painel.add(calcularButton);

        resultadoLabel = new JLabel("\n\nCampo Elétrico: ");
        painel.add(resultadoLabel);

        calcularButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                calcularCampoEletrico();
            }
        });

        add(painel);
    }

    private void calcularCampoEletrico() {
        double raio = Double.parseDouble(raioField.getText()) / 100; // converter cm para m
        double densidade = Double.parseDouble(densidadeField.getText()) * 1e-6; // converter μC/m³ para C/m³
        double distancia = Double.parseDouble(distanciaField.getText()) / 100; // converter cm para m
        double epsilon0 = 8.85e-12;

        double campoEletrico;
        if (distancia <= raio) {
            campoEletrico = (densidade * distancia) / (3 * epsilon0);
        } else {
            double cargaTotal = (densidade * (4.0 / 3.0) * Math.PI * Math.pow(raio, 3));
            campoEletrico = (1 / (4 * Math.PI * epsilon0)) * (cargaTotal / Math.pow(distancia, 2));
        }

        resultadoLabel.setText(String.format("Campo Elétrico: %.2e N/C", campoEletrico));
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            new LeiDeGauss().setVisible(true);
        });
    }
}
