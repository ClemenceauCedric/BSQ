/*
** main.c for all in /home/clemen_j/tek1/ElemProg_C/BSQ/CPE_2015_BSQ/src
**
** Made by Cédric Clemenceau
** Login   <clemen_j@epitech.net>
**
** Started on  Wed Dec  9 17:04:48 2015 Cédric Clemenceau
** Last update Mon Dec 21 19:36:51 2015 Clémenceau Cedric
*/

#include "struct.h"

int	read_line(char *buff, int fd)
{
  int	nbr_line;
  int	i;

  i = 0;
  nbr_line = 0;
  while (read(fd, &buff[i], 1) != -1 && buff[i] != '\n')
    nbr_line = 10 * nbr_line + (buff[i++] - 48);
  return (nbr_line);
}

char	*read_cols(char *buff, int fd, int readed)
{
  int	i;

  i = 0;
  if ((buff = malloc(sizeof(char) * 2)) == NULL)
    return (0);
  while ((readed = (read(fd, &buff[i], 1)) != -1) && buff[i++] != '\n')
    {
      buff[i] = '\0';
      buff = my_realloc(buff, 2);
    }
  buff[i] = '\0';
  return (buff);
}

int	mappy(int *i, t_info *data, char * buff)
{
  if ((data->map[*i] = malloc(sizeof(char) * (data->cols + 1))) == NULL)
    return (0);
  buff[data->readed] = '\0';
  my_strcpy(data->map[*i], buff);
  (*i)++;
  return (*i);
}

int		my_read(char *str)
{
  t_info	*data;
  char		*buff2;
  char		buff[4096];
  int		i;

  i = 1;
  if ((data = malloc(sizeof(t_info))) == NULL)
    return (0);
  if ((data->fd = open(str, O_RDONLY)) == -1)
    return (-1);
  data->lines = read_line(buff, data->fd);
  if ((data->map = malloc(sizeof(char *) * (data->lines + 1))) == NULL)
    return (0);
  data->map[0] = read_cols(buff, data->fd, data->readed);
  data->cols = (my_strlen(data->map[0]));
  if ((buff2 = malloc(data->cols)) == NULL)
    return (0);
  while ((data->readed = read(data->fd, buff2, data->cols)) != 0 && i < data->lines)
    mappy(&i, data, buff2);
  tab_int(data);
  print_tab(data);
  my_free(data);
  free(data);
  free(buff2);
  return (0);
}

int	main(int ac, char **av)
{
  if (ac != 2)
    write(1, "error args\n", 11);
  my_read(av[1]);
  return (0);
}
