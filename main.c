/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 09:31:59 by nidzik            #+#    #+#             */
/*   Updated: 2016/11/13 17:34:58 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int main(int ac, char ** av)
{
  if (ac == 1)
    {
      printf("at least 1 arg plz..\n");
      return (1);
    }
  init_genv();
  mallocc(sizeof(char) * ft_strlen(av[1]), g_env.page);
  mallocc(sizeof(char) * ft_strlen(av[1]), g_env.page);
  return (0);
}
