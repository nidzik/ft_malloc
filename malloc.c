/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:24:23 by nidzik            #+#    #+#             */
/*   Updated: 2016/11/11 12:22:00 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void *mallocc(size_t size)
{
  void *str;
  char *strr;
  str = NULL;
  str = (void *)mmap(0, size + 1, PROT_READ | PROT_WRITE, MAP_ANON |   MAP_PRIVATE, -1 , 0);
  //  printf("\n%s\n",perror(strr));
  perror(strr);fflush(stdout);
  return(str);
}
