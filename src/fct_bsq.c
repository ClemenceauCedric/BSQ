/*
** fct_bsq.c for bsq in /home/clemen_j/tek1/ElemProg_C/BSQ/CPE_2015_BSQ
**
** Made by Cédric Clemenceau
** Login   <clemen_j@epitech.net>
**
** Started on  Mon Dec 14 12:50:44 2015 Cédric Clemenceau
** Last update Mon Dec 21 17:56:35 2015 Clémenceau Cedric
*/

#include "struct.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i])
    i++;
  return (i);
}

int	print_tab(t_info *data)
{
  int	i;
  int	j;

  i = 0;
  while (i < data->lines)
    {
      j = 0;
      while (j < data->cols)
	{
	  write(1, &data->map[i][j], 1);
	  j++;
	}
      i++;
    }
  return (0);
}

int	tab_int(t_info *data)
{
  int	i;

  i = 0;
  if ((data->tab = malloc(sizeof(int *) * data->lines + 1)) == NULL)
    return (0);
  while (i < data->lines)
    {
      if ((data->tab[i] = malloc(sizeof(int) * data->cols)) == NULL)
	return (0);
      i++;
    }
  algo(data);
  return (0);
}

int	conditions(t_info *data)
{
  int	x;
  int	y;
  int	tmp;

  y = 1;
  while (y < data->lines)
    {
      x = 1;
      while (x < data->cols - 1)
  	{
	  if (data->map[y][x] != 'o')
	    {
	      tmp = data->tab[y - 1][x];
	      tmp = (tmp > data->tab[y][x - 1]) ? data->tab[y][x - 1] : tmp;
	      tmp = (tmp > data->tab[y - 1][x - 1]) ? data->tab[y - 1][x - 1] : tmp;
	      data->tab[y][x] = tmp + 1;
	    }
	  else
	    data->tab[y][x] = 0;
	  ++x;
    	}
      y++;
    }
  return (0);
}

int	algo(t_info *data)
{
  int	x;
  int	y;

  x = 0;
  y = 0;
  while (data->map[y])
    {
      x = 0;
      while (x < data->cols)
	{
	  if (y == 0 || x == 0)
	    data->tab[y][x] = (data->map[y][x] == '.') ? 1 : 0;
	  x++;
	}
      y++;
    }
  conditions(data);
  calc_pos(data);
  return (0);
}
