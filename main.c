/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 09:31:59 by nidzik            #+#    #+#             */
/*   Updated: 2017/01/24 20:33:10 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <unistd.h>
#include <string.h>



#define M (1024 * 1024)

int main(int ac, char ** av)
{
  char *str;
  char *str2;
  char *str3;
  char *str4;
  int i;
  (void)ac;
  //init_genv();

/*
  char yol[4][4];

  (void)yol;
  str = (char *)mallocc(10, g_env.page);
  str3 = mallocc(5000,g_env.page);
    str4 = mallocc(500000,g_env.page);
	strcpy(str4, "bonjour");
	str2 = reallocc(str4, 1000000);
  show_alloc_mem();fflush(stdout);
ft_putendl(str2);  
return 0;
*/

//  str = malloccc(1);
  str2 = mallocc(1, g_env.page);
//  printf("\n :: %p \n", str);
  str2 = "q";
  ft_putendl(str2);
//  str2 = malloc(1);
   show_alloc_mem();
  // str3 = realloc(str,2);	  
  
  //show_alloc_mem();
  return (0);
/*
	  char *addr;

	  addr = malloccc(16);
	  free(NULL);
	  
	  free((void*)addr + 5);
	  if (reallocc((void*)addr + 5, 10) == NULL)
		  printf("Bonjours\n");
  show_alloc_mem();fflush(stdout);
	  return (0);
*/

/*
  char    *addr1;
  char    *addr2;
  char    *addr3;


  addr1 = (char*)malloccc(16*M);
  strcpy(addr1, "Bonjours\n");
  printf("%s\n",addr1);
  addr2 = (char*)malloccc(16*M);
  addr3 = (char*)reallocc(addr1, 128*M);
  addr3[127*M] = 42;
  printf("%s\n",addr3);

  return (0);
*/


/*
  addr1 = (char *)malloccc(16*M);
  strcpy(addr1, "Bonjours\n");
  printf("WTF..%p",addr1);fflush(stdout);
  show_alloc_mem();fflush(stdout);
  addr3 = (char*)reallocc(addr1, 128*M);
  addr3[127*M] = 42;
  printf("WTF..%s",addr1);

  return (0);
*/

/*
  (void)ac;
  printf("%d",getpagesize());fflush(stdout);
  str =  mallocc(sizeof(char) * (ft_strlen(av[1]) +1), g_env.page);

  ft_putendl("STR MALLOC");

  str2 =  mallocc(sizeof(char) * (ft_strlen(av[2]) +1), g_env.page);    
  ft_putendl("STR2 MALLOC show mem : ");  
show_alloc_mem();


 str3 = mallocc(sizeof(char) * (ft_strlen(av[3]) +1), g_env.page);
free(str3);
 free(str2);
show_alloc_mem();
 ft_putendl("UPUPUP");
printf("\n reall %p\n",reallocc(str, 150));fflush(stdout);
  ft_putendl("reMALLOC");
free(str);
 show_alloc_mem();
  return 0;
*/

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
