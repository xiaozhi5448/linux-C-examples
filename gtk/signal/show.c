#include<gtk-2.0/gtk/gtk.h>
gint delete_event(GtkWidget* window, GdkEvent* event, gpointer data){
    gtk_widget_hide(window);
    return TRUE;
}
void window2_show(GtkWindow* window, GtkLabel* label){
    gtk_label_set_text(label, "窗口二已显示");
}
void window2_hide(GtkWindow* window, GtkLabel* label){
    gtk_label_set_text(label, "窗口已隐藏");
}
void trans_show_hide(GtkButton* button, GtkWindow* window){
    gboolean visible;
    g_object_get(window, "visible", &visible, NULL);
    if(visible){
        gtk_widget_hide(GTK_WIDGET(window));
    }else{
        gtk_widget_show(GTK_WIDGET(window));
    }
}

int main(int argc, char *argv[]){
    gtk_init(&argc, &argv);
    GtkWidget* window1 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window1), "show_hide 测试");
    g_signal_connect(G_OBJECT(window1), "delete_event", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget* window2 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window2), "窗口2");
    gtk_widget_set_size_request(window2, 200, 100);
    
    GtkWidget* vbox = gtk_vbox_new(FALSE, 15);
    gtk_container_add(GTK_CONTAINER(window1), vbox);

    GtkWidget* label = gtk_label_new("");
    gtk_widget_set_size_request(label, 100, 50);
    gtk_box_pack_start(GTK_BOX(vbox), label, TRUE, TRUE, 0);

    GtkButton* button = gtk_button_new_with_label("显示、隐藏窗体2");
    gtk_widget_set_size_request(button, 100, 50);
    gtk_box_pack_start(GTK_BOX(vbox), button, TRUE, TRUE, 0);

    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(trans_show_hide), window2);
    g_signal_connect(G_OBJECT(window2), "show", G_CALLBACK(window2_show), label);
    g_signal_connect(G_OBJECT(window2), "hide", G_CALLBACK(window2_hide), label);
    g_signal_connect(G_OBJECT(window2), "delete_event", G_CALLBACK(delete_event), NULL);

    gtk_widget_show_all(window1);
    gtk_main();
    return 0;
}