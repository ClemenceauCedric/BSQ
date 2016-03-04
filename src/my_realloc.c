/*
** realloc.c for BSQ in /home/clemen_j/tek1/ElemProg_C/BSQ/CPE_2015_BSQ
**
** Made by Cédric Clemenceau
** Login   <clemen_j@epitech.net>
**
** Started on  Mon Nov 30 10:54:23 2015 Cédric Clemenceau
** Last update Mon Dec 21 22:15:30 2015 Clémenceau Cedric
*/

#include "struct.h"

void	*my_realloc(void *dest, int nb)
{
  void	*str;

  if (dest == NULL)
    {
      if ((str = malloc(nb + 1)) == NULL)
	return (0);
    }
  else
    {
      if ((str = malloc(sizeof(dest) * (my_strlen(dest) + nb))) == NULL)
	return (0);
      my_strcpy(str, dest);
      free(dest);
    }
  return (str);
}
