#include<gtk-2.0/gtk/gtk.h>
int main(int argc, char* argv[]){
    gtk_init(&argc, &argv);
    GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window),"单选菜单");
    g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget* menubar = gtk_menu_bar_new();
    gtk_container_add(GTK_CONTAINER(window), menubar);

    GtkWidget* item1 = gtk_menu_item_new_with_label("单选菜单列表");
    gtk_container_add(GTK_CONTAINER(menubar), item1);

    GtkWidget* submenu = gtk_menu_new();
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(item1), submenu);

    GSList* radiolist = NULL;
    char info[50];
    GtkWidget* radioitem;
    for(int i = 0; i < 5 ; i++){
        snprintf(info, 50, "菜单项：%d", i);
        radioitem = gtk_radio_menu_item_new_with_label(radiolist, info);
        radiolist = gtk_radio_menu_item_get_group(GTK_RADIO_MENU_ITEM(radioitem));
        //gtk_container_add(GTK_CONTAINER(submenu), radioitem);
        if(i = 0){
            gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(radioitem), TRUE);
        }
    }
    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}