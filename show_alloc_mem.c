/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 13:12:07 by nidzik            #+#    #+#             */
/*   Updated: 2016/11/20 14:14:34 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		show_alloc_mem()
{
	t_page *p;
	t_header *h;
	void *ptr;

	p = g_env.page;

	while (p)
	{
		ft_atoi_hex(p->start);
		h = p->start;
		while (h)
		{
			if (!h->free)
			{
				ptr = h + 1;
				ft_atoi_hex(h + 1);
				ft_putstr(" to ");
				ft_atoi_hex((char *)ptr  + h->size);
				ft_putstr(" octets : ");
					ft_putnbr(h->size); 
				ft_putchar('\n');
				
			}
			h = h->next;
		}
		p = p->next;
	}
}
