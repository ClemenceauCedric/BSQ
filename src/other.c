/*
** other.c for bsq in /home/clemen_j/tek1/ElemProg_C/BSQ/CPE_2015_BSQ
**
** Made by Cédric Clemenceau
** Login   <clemen_j@epitech.net>
**
** Started on  Sun Dec 20 12:53:43 2015 Cédric Clemenceau
** Last update Tue Dec 22 20:37:49 2015 Clémenceau Cedric
*/

#include "struct.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_put_nbr(int nb)
{
  int	count;

  count = 0;
  if (nb >= 10)
    count = my_put_nbr(nb / 10);
  my_putchar(nb % 10 + 48);
  return (count + 1);
}

void	my_free(t_info *data)
{
  int	i;

  i = 0;
  while (data->map[i])
    {
      free(data->map[i]);
      free(data->tab[i]);
      i++;
    }
  free(data->map);
  free(data->tab);
}

void	help_algo(int x, int y, t_info *data)
{
  if (x == 1)
    draw_cube_next(data, x, y);
  else if (y == 1)
    draw_cube_prev(data, x);
  else
    draw_cube(data);
}

int	calc_pos(t_info *data)
{
  int	x;
  int	y;

  x = 0;
  y = 0;
  data->pos.size = data->tab[y][x];
  while (data->tab[y])
    {
      x = 0;
      while (x < data->cols - 1)
	{
	  if (data->pos.size < data->tab[y][x])
	    {
	      data->pos.size = data->tab[y][x];
	      data->pos.posx = x + 1;
	      data->pos.posy = y + 1;
	    }
	  x++;
	}
      y++;
    }
  help_algo(x, y, data);
  return (data->pos.size);
}
