package com.zabgu_practice.gui_11g;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;

public class HelloApplication extends Application {
    @Override
    public void start(Stage stage) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(HelloApplication.class.getResource("main_window.fxml"));
        Scene scene = new Scene(fxmlLoader.load(), 600, 338);
        stage.setTitle("Приветсвую!");
        stage.setScene(scene);
        stage.show();
    }
}
