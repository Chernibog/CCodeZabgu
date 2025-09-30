package com.zabgu_practice.gui_88a;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;

public class HelloApplication extends Application {
    @Override
    public void start(Stage stage) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(HelloApplication.class.getResource("main_windw.fxml"));
        Scene scene = new Scene(fxmlLoader.load(), 434, 227);
        stage.setTitle("Hello!");
        stage.setScene(scene);
        stage.show();
    }
}
