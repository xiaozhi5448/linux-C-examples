#include<gtk-2.0/gtk/gtk.h>
void destroy(GtkButton* button, gpointer data){
    gtk_widget_destroy(GTK_WIDGET(button));
}
void create_label(GtkButton* button, GtkWindow* window){
    GtkWidget* label = gtk_label_new("按钮已经被删除");
    gtk_widget_show(label);
    gtk_container_add(GTK_CONTAINER(window), label);
}
int main(int argc, char* argv[]){
    gtk_init(&argc, &argv);
    GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "destroy");
    gtk_widget_set_size_request(window, 200, 100);

    GtkWidget* button = gtk_button_new_with_label("button");
    gtk_container_add(GTK_CONTAINER(window), button);

    g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(destroy), NULL);
    g_signal_connect(G_OBJECT(button), "destroy", G_CALLBACK(create_label), window);

    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}