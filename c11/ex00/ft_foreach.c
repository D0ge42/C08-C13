#include <stdio.h>

void plus(int n)
{
  n+=1;
  printf("%i\n",n);;
}

void	ft_foreach(int *tab, int lenght, void (*f)(int))
{
	int	i;

	i = 0;
  while (i < lenght)
    (f)(tab[i++]);
}


int main()
{
  int tab[5] = {0,1,2,3,4};
  ft_foreach(tab,5, plus);
}
