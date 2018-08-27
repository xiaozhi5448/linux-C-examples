#include<gtk-2.0/gtk/gtk.h>
gint delete_event(GtkWidget* widget, GdkEvent* event, gpointer data){
    printf("程序已退出！\n");
    return TRUE;
}
void destory(GtkWidget* widget, gpointer data){
    gtk_main_quit();
}
int main(int argc, char* argv[]){
    GtkWidget* window;
    GtkWidget* button;
    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(delete_event), NULL);
    g_signal_connect(G_OBJECT(window), "destory", G_CALLBACK(destory), NULL);
    button = gtk_button_new_with_label("hello world");
    g_signal_connect_swapped(G_OBJECT(button), "clicked", G_CALLBACK(gtk_widget_destroy), window);
    gtk_container_add(GTK_CONTAINER(window), button);
    gtk_widget_show(button);
    gtk_widget_show(window);
    gtk_main();
    return 0;
}