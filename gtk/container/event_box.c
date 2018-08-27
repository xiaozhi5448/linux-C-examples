#include<gtk-2.0/gtk/gtk.h>
static void counter(GtkWidget* eventbox){
    static int i = 0;
    static char info[50];
    snprintf(info, 50, "单击次数：%d", ++i);
    GtkWidget* dialog = gtk_message_dialog_new(
        NULL,
        GTK_DIALOG_MODAL,
        GTK_MESSAGE_INFO,
        GTK_BUTTONS_OK,
        info
    );
    gtk_window_set_title(GTK_WINDOW(dialog), "显示单击次数");
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}
int main(int argc, char* argv[]){
    gtk_init(&argc, &argv);
    GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "测试事件盒");
    g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget* event_box = gtk_event_box_new();
    gtk_container_add(GTK_CONTAINER(window), event_box);

    GtkWidget* label = gtk_label_new("点击标签");
    gtk_widget_set_size_request(label, 60, -1);
    gtk_container_add(GTK_CONTAINER(event_box), label);

    g_signal_connect(G_OBJECT(event_box), "button_press_event", G_CALLBACK(counter), NULL);

    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}