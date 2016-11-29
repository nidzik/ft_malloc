/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 09:31:59 by nidzik            #+#    #+#             */
/*   Updated: 2016/11/29 06:09:41 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int main(int ac, char ** av)
{
  char *str;
  char *str2;
  char *str3;
  char *str4;
  int i;

  (void)ac;
  printf("%d",getpagesize());fflush(stdout);
  str =  mallocc(sizeof(char) * (ft_strlen(av[1]) +1), g_env.page);

  ft_putendl("STR MALLOC");

  str2 =  mallocc(sizeof(char) * (ft_strlen(av[2]) +1), g_env.page);    
  ft_putendl("STR2 MALLOC show mem : ");  
show_alloc_mem();
free(str2);
printf("\n reall %p\n",realloc(str, 150));fflush(stdout);
 str3 = mallocc(sizeof(char) * (ft_strlen(av[3]) +1), g_env.page);
  ft_putendl("reMALLOC");
/* free(str); */
 show_alloc_mem();
  return 0;


/*
  int j;
  char* addr;

  j = 0;
  while (j < 4096)
  {
	  addr = (char*)mallocc(9024, g_env.page);
	  addr[0] = 42;
	  free(addr);
	 j++;
  }
  show_alloc_mem();
  return (0);

  init_genv();
  i = 0;
  if (ac == 1)
  {
      printf("at least 1 arg plz..\n");
      return (1);
  }
*/
/*  while (i < 100)
  {
  str =  mallocc(sizeof(char) * (ft_strlen(av[1]) +1), g_env.page);
  i++;
  }
  i =0;
str =  mallocc(sizeof(char) * (ft_strlen(av[1]) +1), g_env.page);
str =  mallocc(sizeof(char) * (ft_strlen(av[1]) +1), g_env.page);
str =  mallocc(sizeof(char) * (ft_strlen(av[1]) +1), g_env.page);
free(str);
str =  mallocc(sizeof(char) * (ft_strlen(av[1]) +1), g_env.page);
str =  mallocc(sizeof(char) * (ft_strlen(av[1]) +1), g_env.page);
str =  mallocc(sizeof(char) * (ft_strlen(av[1]) +1), g_env.page);
*/
str =  mallocc(sizeof(char) * (ft_strlen(av[1]) +1), g_env.page);

  str2 = mallocc(sizeof(char) * (ft_strlen(av[2]) +1), g_env.page);
  str3 = mallocc(sizeof(char) * (ft_strlen(av[3]) +1), g_env.page);
  str4 = mallocc(sizeof(char) * (ft_strlen(av[1]) +1), g_env.page);
  while (av[1][i] != '\0'){
	  str[i] = av[1][i];
	  str4[i] = av[1][i];
	  i++;}
  str[i] = '\0';  
  str4[i] = '\0';  
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
  ft_putendl(str3); 
  ft_putendl(str4); }
  show_alloc_mem();
//  free(str2);
//  free(str3);
  //str3 = mallocc(sizeof(char) * (ft_strlen(av[3]) +1), g_env.page);
  realloc(str2, 10);
  show_alloc_mem(); 
  ft_putendl(str);
  ft_putendl(str3);
  ft_putendl(str4); 
  return (0);
}
