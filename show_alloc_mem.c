/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 13:12:07 by nidzik            #+#    #+#             */
/*   Updated: 2016/11/24 19:27:42 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void			show_alloc_mem()
{
	t_page		*p;
	t_header	*h;
	void		*ptr;
	static size_t  op = 0;
	p = g_env.page;
	while (p)
	{
		ft_putstr("page start : ");
		ft_atoi_hex(p->start);
		printf(" pstart+size %p size %lu ",p->start + p->size,p->size);fflush(stdout);
		ft_putchar('\n');
		h = p->start;
		while (h)
		{
			if (!h->free || h->free)
					{
				ptr = h + 1;
				printf("%lu h->size %lu   h->free %d  ",op++,h->size, h->free);fflush(stdout);
				ft_atoi_hex(h + 1);
				ft_putstr(" to ");
				ft_atoi_hex((char *)ptr + h->size);
				ft_putstr(" octets : ");
				ft_putnbr(h->size);
				printf(" next %p ",h->next);fflush(stdout);
				ft_putchar('\n');
				}
			h = h->next;
		}
		p = p->next;
	}
}
