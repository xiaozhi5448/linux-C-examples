#include<gtk-2.0/gtk/gtk.h>
int main(int argc, char* argv[]){
    GtkWidget* window;
    GtkWidget* button;
    GtkWidget* toggle;
    GtkWidget* vbox;


    gtk_init(&argc, &argv);
    vbox = gtk_vbox_new(FALSE, 0);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_window_set_title(GTK_WINDOW(window), "Hello world");
    gtk_widget_set_size_request(window, 400, 200);

    button = gtk_button_new_from_stock(GTK_STOCK_CLOSE);

    toggle = gtk_toggle_button_new_with_label("toggle");
    // gtk_container_add(GTK_CONTAINER(window), button);
    // gtk_container_add(GTK_CONTAINER(window), toggle);
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(gtk_main_quit), NULL);
    gtk_box_pack_start(GTK_BOX(vbox), button, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), toggle, FALSE, FALSE, 0);



    GtkWidget* checkbutton1;
    GtkWidget* checkbutton2;
    GtkWidget* checkbutton3;
    checkbutton1 = gtk_check_button_new_with_mnemonic("option 1");
    checkbutton2 = gtk_check_button_new_with_mnemonic("option 2");
    checkbutton3 = gtk_check_button_new_with_mnemonic("option 3");
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON( checkbutton1), TRUE);
    gtk_box_pack_start(GTK_BOX(vbox), checkbutton1, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), checkbutton2, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), checkbutton3, FALSE, FALSE, 0);

    GtkWidget* radio1, *radio2, *radio3;
    radio1 = gtk_radio_button_new_with_label(NULL, "option 1");
    radio2 = gtk_radio_button_new_with_label_from_widget((GtkRadioButton*)radio1, "option 2");
    radio3 = gtk_radio_button_new_with_label_from_widget((GtkRadioButton*)radio1, "option 3");
    gtk_box_pack_start(GTK_BOX(vbox), radio1, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), radio2, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), radio3, TRUE, TRUE, 0);
    
    GtkWidget* label;
    label = gtk_label_new("label");
    gtk_label_set_justify(GTK_LABEL(label), GTK_JUSTIFY_LEFT);
    gtk_box_pack_start(GTK_BOX(vbox), label, TRUE, TRUE, 0);

    

    
    GtkWidget *button1, *button2,*button3, *button4;
    GtkWidget *arrow1, *arrow2, *arrow3, *arrow4;
    button1 = gtk_button_new();
    button2 = gtk_button_new();
    button3 = gtk_button_new();
    button4 = gtk_button_new();
    arrow1 = gtk_arrow_new(GTK_ARROW_UP, GTK_SHADOW_OUT);
    arrow2 = gtk_arrow_new(GTK_ARROW_DOWN, GTK_SHADOW_OUT);
    arrow3 = gtk_arrow_new(GTK_ARROW_LEFT, GTK_SHADOW_OUT);
    arrow4 = gtk_arrow_new(GTK_ARROW_RIGHT, GTK_SHADOW_OUT);
    gtk_container_add(GTK_CONTAINER(button1), arrow1);
    gtk_container_add(GTK_CONTAINER(button2), arrow2);
    gtk_container_add(GTK_CONTAINER(button3), arrow3);
    gtk_container_add(GTK_CONTAINER(button4), arrow4);
    gtk_box_pack_start(GTK_BOX(vbox), button1, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), button2, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), button3, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), button4, TRUE, TRUE, 0);





    GtkTooltips *tooltips;
    tooltips = gtk_tooltips_new();
    gtk_tooltips_set_tip(tooltips, button, "this is tips information!", "tips");

    GtkWidget *processbar;
    processbar = gtk_progress_bar_new();
    gtk_progress_bar_set_orientation(GTK_PROGRESS_BAR(processbar), GTK_PROGRESS_LEFT_TO_RIGHT);
    gtk_progress_bar_set_text(GTK_PROGRESS_BAR( processbar), "请稍后");
    gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(processbar), 0.5);
    gtk_box_pack_start(GTK_BOX(vbox), processbar, TRUE, TRUE, 0);


    GtkWidget *dialog, *diaLabel;
    dialog = gtk_dialog_new_with_buttons("close the window",
                                        GTK_WINDOW(window),
                                        GTK_DIALOG_MODAL,
                                        GTK_STOCK_CANCEL,
                                        GTK_RESPONSE_REJECT,
                                        GTK_STOCK_OK,
                                        GTK_RESPONSE_OK,
                                        NULL);
    diaLabel = gtk_label_new_with_mnemonic("确认关闭窗口？");
    gtk_box_pack_start_defaults(GTK_BOX(GTK_DIALOG(dialog)->vbox), diaLabel);

    gtk_widget_show_all(GTK_WIDGET(dialog));
    gint res = gtk_dialog_run(GTK_DIALOG(dialog));
    if(res == GTK_RESPONSE_OK){
        gtk_widget_destroy(window);
        gtk_widget_destroy(dialog);
        return 0;
    }else{
        gtk_widget_destroy(dialog);
    }

    gtk_container_add(GTK_CONTAINER(window), vbox);

    // gtk_widget_show(checkbutton1);
    // gtk_widget_show(checkbutton2);
    // gtk_widget_show(checkbutton3);
    // gtk_widget_show(toggle);
    // gtk_widget_show(button);
    // gtk_widget_show(vbox);
    // gtk_widget_show(window);
    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}