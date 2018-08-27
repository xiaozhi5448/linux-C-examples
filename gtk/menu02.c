#include<gtk-2.0/gtk/gtk.h>
#include<gtk-2.0/gdk/gdkkeysyms.h>
#include<gtk-2.0/gdk/gdk.h>
static void callback_func(GtkMenuItem* item, GtkWindow* window){
    const char* label = gtk_label_get_label(GTK_LABEL(GTK_BIN(item)->child));
    GtkWidget* dialog = gtk_message_dialog_new(
        window,
        GTK_DIALOG_MODAL,
        GTK_MESSAGE_INFO,
        GTK_BUTTONS_OK,
        "%s菜单被选择",
        label
    );
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}
int main(int argc, char* argv[]){
    gtk_init(&argc, &argv);
    GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "测试二级菜单");
    g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(gtk_main_quit), NULL);

    GtkAccelGroup* accelGroup = gtk_accel_group_new();
    GtkWidget* menubar = gtk_menu_bar_new();
    gtk_container_add(GTK_CONTAINER(window), menubar);

    GtkWidget* first1 = gtk_menu_item_new_with_mnemonic("first1");
    gtk_container_add(GTK_CONTAINER(menubar), first1);

    GtkWidget* submenu1 = gtk_menu_new();
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(first1), submenu1);

    GtkWidget* second1 = gtk_menu_item_new_with_mnemonic("second 1");
    gtk_container_add(GTK_CONTAINER(submenu1), second1);
    gtk_widget_add_accelerator(
        second1,
        "activate",
        accelGroup,
        GDK_1,
        GDK_CONTROL_MASK,
        GTK_ACCEL_VISIBLE
    );
    g_signal_connect(G_OBJECT(second1), "activate", G_CALLBACK(callback_func), (gpointer)window);


    GtkWidget* second2 = gtk_menu_item_new_with_mnemonic("second 2");
    gtk_container_add(GTK_CONTAINER(submenu1), second2);
    gtk_widget_add_accelerator(
        second2,
        "activate",
        accelGroup,
        GDK_2,
        GDK_CONTROL_MASK,
        GTK_ACCEL_VISIBLE
    );
   // g_signal_connect(G_OBJECT(second2), "activate", G_CALLBACK(callback_func), (gpointer)window);


    GtkWidget* submenu2 = gtk_menu_new();
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(second2), submenu2);

    GtkWidget* third1 = gtk_menu_item_new_with_mnemonic("third 3");
    gtk_container_add(GTK_CONTAINER(submenu2), third1);
    gtk_widget_add_accelerator(
        third1,
        "activate",
        accelGroup,
        GDK_3,
        GDK_CONTROL_MASK,
        GTK_ACCEL_VISIBLE
    );
    g_signal_connect(G_OBJECT(third1), "activate", G_CALLBACK(callback_func), (gpointer)window);

    GtkWidget* third2 = gtk_menu_item_new_with_mnemonic("third 4");
    gtk_container_add(GTK_CONTAINER(submenu2), third2);
    gtk_widget_add_accelerator(
        third2,
        "activate",
        accelGroup,
        GDK_4,
        GDK_CONTROL_MASK,
        GTK_ACCEL_VISIBLE
    );
    g_signal_connect(G_OBJECT(third2), "activate", G_CALLBACK(callback_func), (gpointer)window);


    gtk_widget_show_all(window);
    gtk_main();
    return 0;





}