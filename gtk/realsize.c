#include<gtk-2.0/gtk/gtk.h>
#include<gtk-2.0/gdk/gdk.h>
static void set_label(GtkWidget* window){
    char info[50];
    snprintf(info, 50, "窗口尺寸：%d * %d", window->allocation.width, window->allocation.height);
    gtk_window_set_title(GTK_WINDOW(window), info);
}

int main(int argc, char *argv[]){
    gtk_init(&argc, &argv);
    GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window),"此处显示屏幕尺寸");

    gtk_widget_set_size_request(window, 100, 100);

    GtkWidget* label = gtk_label_new_with_mnemonic("改变窗口大小");
    gtk_container_add(GTK_CONTAINER(window), label);

    g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(G_OBJECT(window), "size-allocate", G_CALLBACK(set_label), NULL);

    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}