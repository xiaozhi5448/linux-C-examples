#include<gtk-2.0/gtk/gtk.h>
#include<glib-2.0/glib.h>
#include<gtk-2.0/gdk/gdkkeysyms.h>
int main(int argc, char* argv[]){
	gtk_init(&argc, &argv);
	GtkWidget* window;
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_signal_connect(GTK_OBJECT (window), "delete_event", G_CALLBACK(gtk_main_quit), NULL);

	GtkWidget* menubar;
	menubar = gtk_menu_bar_new();
	gtk_container_add(GTK_CONTAINER(window), menubar);

	GtkWidget* menuitem1;
	menuitem1 = gtk_menu_item_new_with_mnemonic("menu1");
	gtk_container_add(GTK_CONTAINER(menubar), menuitem1);

	GtkWidget* menuitem1_submenu;
	menuitem1_submenu = gtk_menu_new();
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menuitem1), menuitem1_submenu);

	GtkAccelGroup* accelgroup = gtk_accel_group_new();
	GtkWidget* open1;
	GtkWidget* save1;
	GtkWidget* close1;
	GtkWidget* exit1;
	open1 = gtk_menu_item_new_with_mnemonic("open");
	gtk_container_add(GTK_CONTAINER(menuitem1_submenu), open1);
	gtk_widget_add_accelerator(open1, "activate", accelgroup, GDK_o, (GdkModifierType)GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);

	save1 = gtk_menu_item_new_with_mnemonic("open");
	gtk_container_add(GTK_CONTAINER(menuitem1_submenu), save1);
	gtk_widget_add_accelerator(save1, "activate", accelgroup, GDK_s, (GdkModifierType)GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);

	close1 = gtk_menu_item_new_with_mnemonic("open");
	gtk_container_add(GTK_CONTAINER(menuitem1_submenu), close1);
	gtk_widget_add_accelerator(close1, "activate", accelgroup, GDK_c, (GdkModifierType)GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
	
	exit1 = gtk_menu_item_new_with_mnemonic("open");
	gtk_container_add(GTK_CONTAINER(menuitem1_submenu), exit1);
	gtk_widget_add_accelerator(exit1, "activate", accelgroup, GDK_x, (GdkModifierType)GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
	

	gtk_widget_show_all(window);
	gtk_main();
	return 0;
}
