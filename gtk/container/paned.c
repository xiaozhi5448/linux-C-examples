#include<gtk-2.0/gtk/gtk.h>
int main(int argc, char *argv[]){
    gtk_init(&argc, &argv);
    GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "分栏窗体");
    g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget* vpanel = gtk_vpaned_new();
    gtk_container_add(GTK_CONTAINER(window), vpanel);
    gtk_paned_set_position(GTK_PANED(vpanel), 0);

    GtkWidget* scroll1 = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scroll1), GTK_POLICY_NEVER, GTK_POLICY_ALWAYS);
    gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(scroll1), GTK_SHADOW_OUT);
    gtk_paned_pack1(GTK_PANED(vpanel), scroll1, TRUE, TRUE);
    GtkWidget* text1 = gtk_text_view_new();
    gtk_widget_set_size_request(text1, 200, 100);
    gtk_container_add(GTK_CONTAINER(scroll1), text1);

    GtkWidget* scroll2 = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scroll2), GTK_POLICY_NEVER, GTK_POLICY_ALWAYS);
    gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(scroll2), GTK_SHADOW_OUT);
    gtk_paned_pack2(GTK_PANED(vpanel), scroll2, TRUE, TRUE);
    GtkWidget* text2 = gtk_text_view_new();
    gtk_widget_set_size_request(text2, 200, 100);
    gtk_container_add(GTK_CONTAINER(scroll2), text2);

    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}