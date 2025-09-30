module com.zabgu_practice.gui_11g {
    requires javafx.controls;
    requires javafx.fxml;
    requires java.desktop;


    opens com.zabgu_practice.gui_11g to javafx.fxml;
    exports com.zabgu_practice.gui_11g;
}