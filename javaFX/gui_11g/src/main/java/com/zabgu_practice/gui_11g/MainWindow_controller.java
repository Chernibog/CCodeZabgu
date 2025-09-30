package com.zabgu_practice.gui_11g;

import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.input.MouseEvent;

import java.awt.*;

public class MainWindow_controller {

    // поля для воода переменных x, y, z
    public TextField field_x;
    public TextField field_y;
    public TextField field_z;

    // для вывода ответа
    public Label label_a_answ;
    public Label label_b_answ;

    public void calc_button_cliked(MouseEvent mouseEvent) {

        double x = 0.0, y = 0.0, z = 0.0;

        double a = 0.0, b = 0.0;

        // считываем данные, как текст
        String x_text = field_x.getText();
        String y_text = field_y.getText();
        String z_text = field_z.getText();

        // переводим их в число
        x = Double.parseDouble( x_text );
        y = Double.parseDouble( y_text );
        z = Double.parseDouble( z_text );

        // Вычисление a
        double innerAbs = y + Math.pow(x, 3) / 3.0;

        double sqrtAbs = Math.sqrt(Math.abs(innerAbs));

        double denominator = y * y + sqrtAbs;

        a = y + x / denominator;

        // Вычисление b
        double tgZOver2 = Math.tan(z / 2.0);

        b = 1.0 + tgZOver2 * tgZOver2;

        label_a_answ.setText( String.valueOf(a) );

        label_b_answ.setText( String.valueOf(b) );


    }
}
