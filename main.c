/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 09:31:59 by nidzik            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2016/11/13 21:13:29 by nidzik           ###   ########.fr       */
=======
/*   Updated: 2016/11/13 18:28:20 by bbichero         ###   ########.fr       */
>>>>>>> dacd471f465c71e585000113ff03b98fe6dd66f8
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int main(int ac, char ** av)
{
<<<<<<< HEAD
  char *str;
  char *str2;
  int i;

  i = 0;
=======
	int nb;
	char *str;
	int i;

	(void)ac;
	if (ac > 1)
		nb = ft_strlen(av[1]);
	else 
		exit(1);
	str = mallocc((size_t) nb);
	ft_putnbr(nb);
	ft_putchar('\n');
	ft_putnbr( VM_FLAGS_SUPERPAGE_SIZE_ANY);
	i = 0;
	while (i < nb)
	{
		str[i] = av[1][i];
		i++;
	}
	str[i] = '\0';
	ft_putchar('\n');
	ft_putendl(str);
	return (0);
=======
>>>>>>> dacd471f465c71e585000113ff03b98fe6dd66f8
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
>>>>>>> d95450842da6ee4018c190b708a4ee30e409f125
}
