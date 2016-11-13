/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 09:31:59 by nidzik            #+#    #+#             */
/*   Updated: 2016/11/13 18:28:20 by bbichero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int main(int ac, char ** av)
{
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
  if (ac == 1)
    {
      printf("at least 1 arg plz..\n");
      return (1);
    }
  init_genv();
  mallocc(sizeof(char) * ft_strlen(av[1]), g_env.page);
  mallocc(sizeof(char) * ft_strlen(av[1]), g_env.page);
  return (0);
>>>>>>> d95450842da6ee4018c190b708a4ee30e409f125
}
