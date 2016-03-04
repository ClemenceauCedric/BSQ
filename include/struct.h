/*
** struct.h for BSQ in /home/clemen_j/tek1/ElemProg_C/BSQ/CPE_2015_BSQ
**
** Made by Cédric Clemenceau
** Login   <clemen_j@epitech.net>
**
** Started on  Mon Dec  7 12:49:22 2015 Cédric Clemenceau
** Last update Mon Dec 21 19:30:44 2015 Clémenceau Cedric
*/

#ifndef STRUCT_H_
# define STRUCT_H_

# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
#include <errno.h>
#include <string.h>

typedef struct	s_pos
{
  int		size;
  int		posx;
  int		posy;
}		t_pos;

typedef struct	s_info
{
  t_pos		pos;
  int		readed;
  int		cols;
  int		lines;
  char		**map;
  int		**tab;
  int		fd;
}		t_info;

char	*my_strcpy(char *, char *);
void	*my_realloc(void *, int);
char	*my_strcat(char *, char *);
char	*my_strdup(char *);
int	my_strlen(char *);
int	bsq(char *);
int	my_read(char *);
int	algo(t_info *);
int	print_tab(t_info *);
int	my_strlen(char *);
int	tab_int(t_info *);
void	my_free(t_info *);
int	my_put_nbr(int);
void	my_putchar(char);
int	conditions(t_info *);
int	draw_cube(t_info *);
int	calc_pos(t_info *);
int	draw_cube_next(t_info *, int, int);
int	draw_cube_prev(t_info *, int);

#endif /* !STRUCT_H_ */
