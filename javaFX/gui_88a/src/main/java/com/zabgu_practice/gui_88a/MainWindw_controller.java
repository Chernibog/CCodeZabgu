package com.zabgu_practice.gui_88a;

import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.input.MouseEvent;

public class MainWindw_controller {

    // тут хранится введённое значение
    public TextField textField_n;

    // для вывода ответа
    public Label label_answ;

    public void button_click(MouseEvent mouseEvent) {

        int n = 0;

        // считываем, как текст
        String n_text = textField_n.getText();

        // переводим в число
        n = Integer.parseInt( n_text );

        // вычисляем квадрат числа
        long square = (long) n * n;  // Используем long, чтобы избежать переполнения при больших n

        // проверяем, содержится ли цифра '3' в записи квадрата
        boolean containsThree = false;      // пока не нашли

        long temp = square;

        // пока temp не 0
        while (temp != 0) {

            long digit = temp % 10;  // получаем последнюю цифру

            // если эта цифра = 3
            if (digit == 3) {

                // нашли
                containsThree = true;

                break;      // если нашли 3, то завершаем цикл
            }

            temp /= 10;     // если нет, то убираем последнюю цифу
        }

        // выводим
        if (containsThree) {

            label_answ.setText( String.format("Цифра 3 входит в запись числа %d^2 = %d", n, square) );

        } else {

            label_answ.setText( String.format("Цифра 3 НЕ входит в запись числа %d^2 = %d", n, square) );

        }

    }
}
