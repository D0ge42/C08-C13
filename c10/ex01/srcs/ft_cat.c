#include <fcntl.h>
#include <unistd.h>
#include "../includes/ft.h"

int open_file(char *file_path)
{
  int fd = open(file_path, O_RDWR);
  return fd;
}

int read_file(int fd,char str[BUFF], int buf)
{

  int sz = read(fd,str,buf);
  return sz;
}

int main(int ac, char **av)
{
  char c[BUFF];
  int i = 1;

  if(ac == 1)
  {
    ft_putstr("Not enough arguments", 2);
    return 0;
  }
  else
  {
    while(i < ac)
    {
      int fd = open_file(av[i]);
      if (fd == -1)
      {
        ft_putstr("Couldn't open file",2);
        return 0;
      }
      int sz = read_file(fd,c,BUFF);
      ft_putstr_buf(c,sz);
      i++;
    }
  }
  return 0;
}
