#include <stdlib.h>
#include <gtk/gtk.h>
#include <cairo.h>

#include "guievents.h"
#include "timerhandler.h"

double coordy[1023];

void
init_data (void) {
  int i;
  for ( i = 0; i <= 1023; i++ ) {
    coordy[i] = rand()%64 + 100;
  }
}

int main (int argc, char *argv[]) {
  GtkWidget *window;
  GtkWidget *ok;
  GtkWidget *close;

  GtkWidget *vbox;
  GtkWidget *hbox;
  GtkWidget *halign;
  GtkWidget *valign;
  GtkWidget *draw_frame;
  GtkWidget *draw_area;

  init_data();

  /* Initialize GTK+ */
  g_log_set_handler ("Gtk", G_LOG_LEVEL_WARNING, (GLogFunc) gtk_false, NULL);
  gtk_init (&argc, &argv);
  g_log_set_handler ("Gtk", G_LOG_LEVEL_WARNING, g_log_default_handler, NULL);

  /* Create the main window */
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_container_set_border_width (GTK_CONTAINER (window), 8);
  gtk_window_set_title (GTK_WINDOW (window), "Hello World");
  gtk_window_set_position (GTK_WINDOW (window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 1044, 596);
  gtk_widget_realize (window);
  g_signal_connect (window, "destroy", gtk_main_quit, NULL);

  /* Create a horizontal box */
  vbox = gtk_vbox_new(FALSE, 3);

  draw_frame = gtk_frame_new("");
  gtk_frame_set_shadow_type(GTK_FRAME(draw_frame), GTK_SHADOW_ETCHED_IN);
  gtk_widget_set_size_request(draw_frame, 1024, 512);
  /* gtk_box_pack_start(GTK_BOX(vbox), draw_frame, TRUE, TRUE, 0); */
  gtk_container_add(GTK_CONTAINER(vbox), draw_frame);

  draw_area = gtk_drawing_area_new();
  gtk_widget_add_events(GTK_WIDGET(draw_area), GDK_BUTTON_PRESS_MASK | GDK_BUTTON_RELEASE_MASK | GDK_BUTTON_MOTION_MASK);
  gtk_widget_set_size_request(draw_area, 1024, 512);
  gtk_container_add(GTK_CONTAINER(draw_frame), draw_area);
  
  valign = gtk_alignment_new(0, 1, 0, 0);
  gtk_container_add(GTK_CONTAINER(vbox), valign);
  gtk_container_add(GTK_CONTAINER(window), vbox);

  hbox = gtk_hbox_new(TRUE, 3);

  ok = gtk_button_new_with_label("Ok");
  gtk_widget_set_size_request(ok, 70, 30);
  gtk_container_add(GTK_CONTAINER(hbox), ok);
  close = gtk_button_new_with_label("Close");
  gtk_container_add(GTK_CONTAINER(hbox), close);
  
  halign = gtk_alignment_new(1, 0, 0, 0);
  gtk_container_add(GTK_CONTAINER(halign), hbox);

  gtk_box_pack_start(GTK_BOX(vbox), halign, FALSE, FALSE, 0);

  g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(delete_event), NULL);
  g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(destroy), NULL);

  g_signal_connect(G_OBJECT(ok), "clicked", G_CALLBACK(button_clicked), NULL);
  g_signal_connect_swapped(G_OBJECT(close), "clicked", G_CALLBACK(gtk_widget_destroy), G_OBJECT(window));

  g_signal_connect(draw_area, "button-press-event", G_CALLBACK(ok_press), NULL);
  g_signal_connect(draw_area, "expose-event", G_CALLBACK (on_expose_event), NULL);

  g_timeout_add(100, (GSourceFunc) timer_handler, (gpointer) window);
  
  /* Enter the main loop */
  gtk_widget_show_all (window);
  gtk_main ();
  return 0;
}
