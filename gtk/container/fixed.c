#include<gtk-2.0/gtk/gtk.h>
int main(int argc, char *argv[]){
    gtk_init(&argc, &argv);

    GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "测试固定布局");
    g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget* fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(window), fixed);

    GtkWidget* label = gtk_label_new("备注:");
    gtk_widget_set_size_request(label, 60, 20);
    gtk_fixed_put(GTK_FIXED(fixed), label, 20, 20);

    GtkWidget* text = gtk_text_view_new();
    gtk_widget_set_size_request(text, 100, 200);
    gtk_fixed_put(GTK_FIXED(fixed), text, 90, 20);

    GtkWidget* button = gtk_button_new_from_stock("gtk-quit");
    gtk_widget_set_size_request(button, 60, 30);
    gtk_fixed_put(GTK_FIXED(fixed), button, 120, 230);

    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);
    gtk_main();
    return 0;

}