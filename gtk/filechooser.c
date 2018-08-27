#include<gtk-2.0/gtk/gtk.h>
#include<stdio.h>
int main(int argc, char* argv[]){
    GtkWidget* dialog;
    gtk_init(&argc, &argv);
    dialog = gtk_file_chooser_dialog_new(
        "make directory",
        NULL,
        GTK_FILE_CHOOSER_ACTION_CREATE_FOLDER,
        GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
        GTK_STOCK_OK, GTK_RESPONSE_OK,
        NULL
    );
    gint res = gtk_dialog_run(GTK_DIALOG(dialog));
    gchar* filename;
    if(res = GTK_RESPONSE_OK){
        filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
        printf("已创建目录：%s\n", filename);
    }
    gtk_widget_destroy(dialog);
    return 0;
}