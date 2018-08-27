#include<gtk-2.0/gtk/gtk.h>
static void font_dialog_response(GtkFontSelectionDialog* dialog, gint response, gpointer data){
    gchar* name;
    GtkWidget* message;
    switch(response){
        case(GTK_RESPONSE_APPLY):
        case(GTK_RESPONSE_OK):
            name = gtk_font_selection_dialog_get_font_name(dialog);
            message = gtk_message_dialog_new(
                NULL,
                GTK_DIALOG_MODAL,
                GTK_MESSAGE_INFO,
                GTK_BUTTONS_OK,
                name
            );
            gtk_window_set_title(GTK_WINDOW(message), "font selected:");
            gtk_dialog_run(message);
            gtk_widget_destroy(message);
            g_free(name);
            break;
        default:
            gtk_widget_destroy(dialog);
    }
    if(response == GTK_RESPONSE_OK){
        gtk_widget_destroy(dialog);
    }
    gtk_main_quit();
}

int main(int argc, char* argv[]){
    gtk_init(&argc, &argv);
    GtkWidget* dialog;
    dialog = gtk_font_selection_dialog_new("select font");
    gtk_font_selection_dialog_set_font_name(GTK_FONT_SELECTION_DIALOG(dialog), "Sans Bold Italic 12");
    gtk_font_selection_dialog_set_preview_text(GTK_FONT_SELECTION_DIALOG(dialog), "test content");
    g_signal_connect(G_OBJECT(dialog), "response", G_CALLBACK(font_dialog_response), NULL);
    gtk_widget_show_all(dialog);
    gtk_main();
    return 0;
}