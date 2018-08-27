#include<gtk-2.0/gtk/gtk.h>
int main(int argc, char*argv[]){
    gtk_init(&argc, &argv);
    GtkWidget* window;
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "文本区域");
    g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget* scrollwin;
    scrollwin = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(window), scrollwin);
    gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(scrollwin), GTK_SHADOW_IN);

    GtkWidget* textarea;
    textarea = gtk_text_view_new();
    gtk_text_buffer_set_text(gtk_text_view_get_buffer(GTK_TEXT_VIEW(textarea)), "这是测试文本", -1);
    gtk_container_add(GTK_CONTAINER(scrollwin), textarea);

    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}