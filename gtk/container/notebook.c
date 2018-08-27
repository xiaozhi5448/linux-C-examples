#include<gtk-2.0/gtk/gtk.h>
void rotate_book(GtkButton* button, GtkNotebook* book){
    gtk_notebook_set_tab_pos(book, (book->tab_pos + 1) % 4);
}
void trans_border(GtkButton* button, GtkNotebook* book){
    gboolean tvar = FALSE;
    gboolean bvar = FALSE;
    if(gtk_notebook_get_show_tabs(book) == 0){
        tvar = TRUE;
    }
    if(gtk_notebook_get_show_border(book) == 0){
        bvar = TRUE;
    }
    gtk_notebook_set_show_tabs(book, tvar);
    gtk_notebook_set_show_border(book, bvar);
}
void delete_page(GtkButton* button, GtkNotebook* book){
    gint page = gtk_notebook_get_current_page(book);
    gtk_notebook_remove_page(book, page);
    gtk_widget_queue_draw(GTK_WIDGET( book));
}
int main(int argc, char *argv[]){
    gtk_init(&argc, &argv);
    GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "测试笔记本");
    g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(gtk_main_quit), NULL);

    
}