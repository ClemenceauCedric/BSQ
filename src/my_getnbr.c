/*
** my_getnbr.c for get_nbr in /home/clemen_j/rendu/Piscine_C_J04
**
** Made by Cédric Clemenceau
** Login   <clemen_j@epitech.net>
**
** Started on  Sun Oct 11 08:07:34 2015 Cédric Clemenceau
** Last update Sun Nov 22 19:07:38 2015 Cédric Clemenceau
*/

#include "header.h"

int	my_getnbr(char *str)
{
  int	nb;
  int	i;
  int	boole;

  nb = 0;
  i = 0;
  boole = 0;
  if (str[i] == '-')
    {
      nb = -nb;
      i++;
      boole = 1;
    }
    while (str[i])
      {
	nb = 10 * nb + (str[i] - 48);
	i++;
      }
    return (boole == 1 ? -nb : nb);
}
