#include <stdlib.h>
#include <gtk/gtk.h>

#include "timerhandler.h"
#include "portrw.h"

gboolean
timer_handler(GtkWidget* widget)
{
  extern int count;
  extern int value[1023];
  
  value[count] = get_data_point();
  count++;
  gtk_widget_queue_draw(widget);
  
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
