void button_clicked (GtkWidget *wid, gpointer *data);
gboolean delete_event (GtkWidget * widget, GdkEvent * event, gpointer data);
void destroy (GtkWidget * widget, gpointer data);
gboolean on_expose_event (GtkWidget *widget, GdkEventExpose *event, gpointer data);
void init_draw_area (GtkWidget *widget);
gboolean ok_press (GtkWidget *widget, GdkEventKey *event, gpointer user_data);
