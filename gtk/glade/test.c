#include<gtk-3.0/gtk/gtk.h>
int main(int argc, char *argv[]){
    gtk_init(&argc, &argv);
    GtkBuilder* builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "ui.glade", NULL);
    GtkWidget* window = GTK_WIDGET(gtk_builder_get_object(builder, "MainWindow"));
    GtkWidget* label = GTK_WIDGET(gtk_builder_get_object(builder, "label"));
    gtk_label_set_text(GTK_LABEL(label), "hello world");
    gtk_widget_show_all(window);
    gtk_builder_connect_signals(builder, NULL);
    gtk_main();
    return 0;
}
