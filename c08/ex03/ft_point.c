#include "ft_point.h"
#include <stdio.h>

//Functiot to set struct's variables to a value.
void set_point(t_point *point)
{
  point->x = 432;
  point->y = 231;
}

//We decleare a t_point structure. We then pass its address to the set_point function and set each
//variable to a previously specified value.

int main(void)
{
  t_point point;
  set_point(&point);
  printf("%i\n", point.x);
  printf("%i\n", point.y);
  return 0;
}
