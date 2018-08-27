#include<gtk-2.0/gtk/gtk.h>
int main(int argc, char* argv[]){
    gtk_init(&argc, &argv);
    GtkWidget* window;
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(gtk_main_quit), NULL);

    GdkPixbuf* image_buf;
    image_buf = gdk_pixbuf_new_from_file("win7.jpg", NULL);
    GdkImage* image;
    image = gtk_image_new_from_pixbuf(image_buf);
    gtk_container_add(GTK_CONTAINER(window), image);
    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}