#include<gtk-2.0/gtk/gtk.h>
int main(int argc, char* argv[]){
    gtk_init(&argc, &argv);
    GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "测试对齐容器");
    g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget* vbox = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    GtkWidget* align1 = gtk_alignment_new(0, 0, 0, 0);
    gtk_widget_set_size_request(align1, 100, 100);
    gtk_box_pack_start(GTK_BOX(vbox), align1, FALSE, FALSE, 0);
    GtkWidget* label1 = gtk_label_new("左上对齐");
    gtk_container_add(GTK_CONTAINER(align1), label1);

    GtkWidget* align2 = gtk_alignment_new(1, 0, 0, 0);
    gtk_widget_set_size_request(align2, 100, 100);
    gtk_box_pack_start(GTK_BOX(vbox), align2, FALSE, FALSE, 0);
    GtkWidget* label2 = gtk_label_new("右上对齐");
    gtk_container_add(GTK_CONTAINER(align2), label2);

    GtkWidget* align3 = gtk_alignment_new(0, 1, 0, 0);
    gtk_widget_set_size_request(align3, 100, 100);
    gtk_box_pack_start(GTK_BOX(vbox), align3, FALSE, FALSE, 0);
    GtkWidget* label3 = gtk_label_new("左下对齐");
    gtk_container_add(GTK_CONTAINER(align3), label3);

    GtkWidget* align4 = gtk_alignment_new(1, 1, 0, 0);
    gtk_widget_set_size_request(align4, 100, 100);
    gtk_box_pack_start(GTK_BOX(vbox), align4, FALSE, FALSE, 0);
    GtkWidget* label4 = gtk_label_new("右下对齐");
    gtk_container_add(GTK_CONTAINER(align4), label4);

    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}