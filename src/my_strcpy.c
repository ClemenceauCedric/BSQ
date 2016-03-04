/*
** my_strcpy.c for all in /home/clemen_j/tek1/ElemProg_C/BSQ/CPE_2015_BSQ/src
**
** Made by Cédric Clemenceau
** Login   <clemen_j@epitech.net>
**
** Started on  Mon Dec  7 21:41:47 2015 Cédric Clemenceau
** Last update Sat Dec 19 16:38:08 2015 Cédric Clemenceau
*/

#include "struct.h"

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (src);
}
