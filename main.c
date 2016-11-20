/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 09:31:59 by nidzik            #+#    #+#             */
/*   Updated: 2016/11/20 20:29:29 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int main(int ac, char ** av)
{
  char *str;
  char *str2;
  char *str3;
  int i;

  i = 0;
  if (ac == 1)
  {
      printf("at least 1 arg plz..\n");
      return (1);
  }
  init_genv();
  while (i < 100)
  {
  str =  mallocc(sizeof(char) * (ft_strlen(av[1]) +1), g_env.page);
  i++;
  }
  i =0;
str =  mallocc(sizeof(char) * (ft_strlen(av[1]) +1), g_env.page);
str =  mallocc(sizeof(char) * (ft_strlen(av[1]) +1), g_env.page);
str =  mallocc(sizeof(char) * (ft_strlen(av[1]) +1), g_env.page);
str =  mallocc(sizeof(char) * (ft_strlen(av[1]) +1), g_env.page);
str =  mallocc(sizeof(char) * (ft_strlen(av[1]) +1), g_env.page);
str =  mallocc(sizeof(char) * (ft_strlen(av[1]) +1), g_env.page);
str =  mallocc(sizeof(char) * (ft_strlen(av[1]) +1), g_env.page);

  str2 = mallocc(sizeof(char) * (ft_strlen(av[2]) +1), g_env.page);
  str3 = mallocc(sizeof(char) * (ft_strlen(av[3]) +1), g_env.page);

  while (av[1][i] != '\0'){
	  str[i] = av[1][i];
	  i++;}
  str[i] = '\0';  
  i = 0;
  while (av[2][i] != '\0'){
	  str2[i] = av[2][i];
	  i++;}
  str2[i] = '\0';
  i = 0 ;
  while (av[3][i] != '\0'){
	  str3[i] = av[3][i];
	  i++;}
  str3[i] = '\0';

  printf("&str  at %p  - > %p ", &str, str);fflush(stdout);
  ft_putchar('\n');
  //ft_putendl(str);
  if (ft_strlen(av[1]) < 420){
  ft_putendl(str);
//  ft_putendl("str after str2 was malloc");
  ft_putendl(str2); 
  ft_putendl(str3); }

  show_alloc_mem(); 
  return (0);
}
