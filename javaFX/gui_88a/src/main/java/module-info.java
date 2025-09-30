module com.zabgu_practice.gui_88a {
    requires javafx.controls;
    requires javafx.fxml;


    opens com.zabgu_practice.gui_88a to javafx.fxml;
    exports com.zabgu_practice.gui_88a;
}