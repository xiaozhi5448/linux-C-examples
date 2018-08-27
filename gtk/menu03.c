#include<gtk-2.0/gtk/gtk.h>
void check_activate(GtkCheckMenuItem* item, GtkLabel* label){
    char* info;
    if(gtk_check_menu_item_get_active(item)){
        info = "复选框状态已选中";
    }else{
        info = "复选框状态为未选中";
    }
    gtk_label_set_text(label, info);
}
void radio_activate(GtkMenuItem* item1, GtkCheckMenuItem* item2){
    if(gtk_check_menu_item_get_active(item2)){
        gtk_check_menu_item_set_active(item2, FALSE);
    }
}
int main(int argc, char* argv[]){
    gtk_init(&argc, &argv);
    GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "测试复选菜单");
    g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget* vbox = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    GtkWidget* menubar = gtk_menu_bar_new();
    gtk_box_pack_start(GTK_BOX(vbox), menubar, TRUE, TRUE, 0);

    GtkWidget* item1 = gtk_menu_item_new_with_mnemonic("test");
    gtk_container_add(GTK_CONTAINER(menubar), item1);

    GtkWidget* submenu = gtk_menu_new();
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(item1), submenu);

    GtkWidget* item2 = gtk_check_menu_item_new_with_mnemonic("复选菜单项");
    gtk_container_add(GTK_CONTAINER(submenu), item2);
    
    GtkWidget* item3 = gtk_menu_item_new_with_mnemonic("清除复选框状态");
    gtk_container_add(GTK_CONTAINER(submenu), item3);

    GtkWidget* label = gtk_label_new("请改变复选框的状态");
    gtk_box_pack_start(GTK_BOX(vbox), label, TRUE, TRUE,0);

    g_signal_connect(G_OBJECT(item2), "activate", G_CALLBACK(check_activate), (gpointer)label);
    g_signal_connect(G_OBJECT(item3), "activate", G_CALLBACK(radio_activate), (gpointer)item2);
    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}