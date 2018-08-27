#include<gtk-2.0/gtk/gtk.h>
#include<gtk-2.0/gdk/gdk.h>
#include<gtk-2.0/gdk/gdkkeysyms.h>

GtkWidget* create_menu(){
    GtkWidget* menu;
    menu = gtk_menu_new();

    GtkAccelGroup* accelGroup = gtk_accel_group_new();

    GtkWidget* copy = gtk_menu_item_new_with_label("copy");
    gtk_container_add(GTK_CONTAINER(menu), copy);
    gtk_widget_add_accelerator(copy, "activate", accelGroup, GDK_c, (GdkModifierType)GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
    g_signal_connect(G_OBJECT(copy), "activate", NULL, NULL);

    GtkWidget* cut = gtk_menu_item_new_with_label("cut");
    gtk_container_add(GTK_CONTAINER(menu), cut);
    gtk_widget_add_accelerator(cut, "activate", accelGroup, GDK_x, (GdkModifierType)GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
    g_signal_connect(G_OBJECT(cut), "activate", NULL, NULL);

    GtkWidget* delete = gtk_menu_item_new_with_label("delete");
    gtk_container_add(GTK_CONTAINER(menu), delete);
    gtk_widget_add_accelerator(delete, "activate", accelGroup, GDK_F4, (GdkModifierType)0, GTK_ACCEL_VISIBLE);
    g_signal_connect(G_OBJECT(delete), "activate", NULL, NULL);

    gtk_menu_set_accel_group(GTK_MENU(menu),accelGroup);
   // gtk_window_add_accel_group(GTK_WINDOW(window), accelGroup);
    gtk_widget_show_all(menu);
    return menu;
}
static gint button_press(GtkWidget* menu, GdkEvent* event){
    if(event->type == GDK_BUTTON_PRESS){
        GdkEventButton* bevent = (GdkEventButton*)event;
        gtk_menu_popup(GTK_MENU(menu), NULL, NULL, NULL, NULL, bevent->button, bevent->time);
        return TRUE;
    }
    return FALSE;
}


int main(int argc, char* argv[]){
    gtk_init(&argc, &argv);
    GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window),"测试弹出式菜单");

    GtkWidget* menu = create_menu();
    GtkWidget* button = gtk_button_new_with_label("按下按钮");
    g_signal_connect_swapped(G_OBJECT(button), "event", G_CALLBACK(button_press), menu);
    gtk_container_add(GTK_CONTAINER(window), button);
    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}