#include <stdlib.h>
#include <gtk/gtk.h>
#include <cairo.h>

#include "guievents.h"
#include "timerhandler.h"
#include "portrw.h"

gboolean
timer_handler(GtkWidget* widget)
{
  /*
  //если передан нулевой параметр - возвращаем ложь
  if (widget->window == NULL) return FALSE;
  //увеличиваем значение переменной смещения графика
  count++;
  //обнуляем точку положения на графике
  t = 0;
  //заставляем окно перерисоваться
  gtk_widget_queue_draw(widget);
  */
  return TRUE;
}
