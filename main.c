/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 09:31:59 by nidzik            #+#    #+#             */
/*   Updated: 2016/11/13 21:13:29 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int main(int ac, char ** av)
{
  char *str;
  char *str2;
  int i;

  i = 0;
  if (ac == 1)
    {
      printf("at least 1 arg plz..\n");
      return (1);
    }
  init_genv();
str =  mallocc(sizeof(char) * ft_strlen(av[1]), g_env.page);
 while (av[1][i] != '\0')
   {
   str[i] = av[1][i];

   i++;
   }
 str[i] = '\0';
 printf("start at %p ", &str);fflush(stdout);
 ft_putchar('\n');
  ft_putendl(str);
     str2 =  mallocc(sizeof(char) * ft_strlen(av[1]), g_env.page);
   ft_putendl("str after str2 was malloc");
     ft_putendl(str); 
  return (0);
}
