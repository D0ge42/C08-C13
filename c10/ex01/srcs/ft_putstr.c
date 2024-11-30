#include "/home/doge/c10/ex01/includes/ft.h"

void ft_putstr(char *str, int fd)
{
  while(*str)
    write(fd,str++,1);
}

void ft_putstr_buf(char *str, int size)
{
  int i;
  i = 0;
  while(i < size)
    write(1,&(str[i++]),1);
}
