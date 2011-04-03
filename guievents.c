#include <stdlib.h>
#include <gtk/gtk.h>
#include <cairo.h>

#include "guievents.h"

void
button_clicked (GtkWidget *wid, gpointer *data) {
  g_print ("Button clicked.\n");
}

gboolean
delete_event (GtkWidget * widget, GdkEvent * event, gpointer data) {
  g_print ("Delete event occurred\n");
  return FALSE;
}
 
void
destroy (GtkWidget * widget, gpointer data) {
  g_print ("Destroy signal was sent\n");
  gtk_main_quit ();
}

gboolean
on_expose_event (GtkWidget *widget, GdkEventExpose *event, gpointer data) {
  extern double coordy[1023];
  int i;
  cairo_t *cr;

  cr = gdk_cairo_create(widget->window);

  cairo_set_source_rgb(cr, 0, 0, 0);
  cairo_set_line_width (cr, 0.5);
  
/*
  for ( i = 0; i <= 1023; i++ ) {
    coordy[i] = rand()%32 + 100;
  }
*/
  for ( i = 0; i <= 1023 - 1; i++ ) {
      cairo_move_to(cr, i, coordy[i]);
      cairo_line_to(cr, i+1, coordy[i+1]);
  }

  cairo_stroke(cr);

  cairo_destroy(cr);

  return FALSE;
}

gboolean
ok_press (GtkWidget *widget, GdkEventKey *event, gpointer user_data) {
  extern double coordy[1023];
  int i;
  for ( i = 0; i <= 1023; i++ ) {
    coordy[i] = rand()%64 + 100;
  }

  g_print ("Draw widget pressed.\n");
  gtk_widget_queue_draw(widget);
    
  return TRUE;
}
