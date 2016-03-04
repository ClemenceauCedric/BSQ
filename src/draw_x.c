/*
** draw_x.c for bsq in /home/clemen_j/Work/CPE/CPE_2015_BSQ
**
** Made by Clémenceau Cedric
** Login   <clemen_j@epitech.net>
**
** Started on  Mon Dec 21 18:49:20 2015 Clémenceau Cedric
** Last update Tue Dec 22 14:35:33 2015 Clémenceau Cedric
*/

#include "struct.h"

int	draw_cube(t_info *data)
{
  int	y;
  int	x;

  y = data->pos.posy - data->pos.size;
  x = data->pos.posx - data->pos.size;
  while (y != data->pos.posy)
    {
      while (x != data->pos.posx)
	{
	  data->map[y][x] = 'x';
	  x++;
	}
      x = data->pos.posx - data->pos.size;
      y++;
    }
  return (0);
}

int	draw_cube_next(t_info *data, int x, int y)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (j != y)
    {
      while (i != x)
	{
	  if (data->map[j][i] == '.')
	    {
	      data->map[j][i] = 'x';
	      return (0);
	    }
	  else
	    i++;
	}
      i = 0;
      j++;
    }
  return (0);
}

int	draw_cube_prev(t_info *data, int x)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (i != x)
    {
      if (data->map[j][i] == '.')
	{
	  data->map[j][i] = 'x';
	  return (0);
	}
      else
	i++;
    }
  return (0);
}
