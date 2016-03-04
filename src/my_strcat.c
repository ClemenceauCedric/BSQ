/*
** my_strcat.c for my_ls in /home/clemen_j/tek1/System_Unix/MyLs/PSU_2015_my_ls/src
**
** Made by Cédric Clemenceau
** Login   <clemen_j@epitech.net>
**
** Started on  Sun Nov 29 20:40:28 2015 Cédric Clemenceau
** Last update Fri Dec 18 23:45:34 2015 Cédric Clemenceau
*/

#include "struct.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	n;

  n = my_strlen(dest);
  i = 0;
  while (src[i])
    {
      dest[n + i] = src[i];
      i++;
    }
  dest[n + i] = '\0';
  return (dest);
}
