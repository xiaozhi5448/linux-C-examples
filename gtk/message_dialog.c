#include<gtk-2.0/gtk/gtk.h>
static void button_clicked(GtkButton* button, GtkWindow* window){
    GtkWidget* dialog;
    dialog = gtk_message_dialog_new(
        window,
        GTK_DIALOG_MODAL,
        GTK_MESSAGE_INFO,
        GTK_BUTTONS_OK,
        "按钮被按下"
    );
    gtk_window_set_title(GTK_WINDOW(dialog), "消息对话框");
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}
int main(int argc, char* argv[]){
    gtk_init(&argc, &argv);
    GtkWidget* window;
    GtkWidget* button;
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "消息对话框示例");
    button = gtk_button_new_with_label("点击");
    gtk_container_add(GTK_CONTAINER(window), button);
    g_signal_connect(window, "delete_event", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(button_clicked), (gpointer)window);
    gtk_widget_show_all(window);
    gtk_main();
    return 0;

}