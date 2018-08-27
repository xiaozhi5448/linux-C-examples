#include<gtk-2.0/gtk/gtk.h>
int main(int argc, char*argv[]){
    gtk_init(&argc, &argv);
    GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "组装盒模型");
    g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget* vbox = gtk_vbox_new(FALSE, 2);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    GtkWidget* hbox1 = gtk_hbox_new(FALSE, 15);
    gtk_box_pack_start(GTK_BOX(vbox), hbox1, TRUE, TRUE, 0);

    GtkWidget* lbName = gtk_label_new("姓名：");
    gtk_widget_set_size_request(lbName, 60, -1);
    gtk_box_pack_start(GTK_BOX(hbox1), lbName, FALSE, FALSE, 5);

    GtkWidget* entry = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox1), entry, TRUE, TRUE, 0);
    gtk_entry_set_invisible_char(GTK_ENTRY(entry), 8226);

    GtkWidget* hbox2 = gtk_hbox_new(FALSE, 15);
    gtk_box_pack_start(GTK_BOX(vbox), hbox2, TRUE, TRUE, 0);

    GtkWidget* lbSex = gtk_label_new("性别：");
    gtk_widget_set_size_request(lbSex, 60, -1);
    gtk_box_pack_start(GTK_BOX(hbox2), lbSex, TRUE, TRUE, 0);

    GSList* radioList = NULL;
    GtkWidget* radiobutton1 = gtk_radio_button_new_with_mnemonic(NULL, "男");
    gtk_box_pack_start(GTK_BOX(hbox2), radiobutton1, TRUE, TRUE, 15);
    gtk_radio_button_set_group(GTK_RADIO_BUTTON(radiobutton1), radioList);
    radioList = gtk_radio_button_get_group(GTK_RADIO_BUTTON(radiobutton1));

    GtkWidget* radiobutton2 = gtk_radio_button_new_with_mnemonic(NULL, "女");
    gtk_radio_button_set_group(GTK_RADIO_BUTTON(radiobutton2), radioList);
    radioList = gtk_radio_button_get_group(GTK_RADIO_BUTTON(radiobutton2));
    gtk_box_pack_start(GTK_BOX(hbox2), radiobutton2, FALSE, FALSE, 15);

    GtkWidget* button = gtk_button_new_from_stock(GTK_STOCK_CLOSE);
    gtk_box_pack_start(GTK_BOX(vbox), button, TRUE, TRUE, 5);
    
    g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);
    gtk_main();
    return 0;



}