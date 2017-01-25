/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 13:12:07 by nidzik            #+#    #+#             */
/*   Updated: 2017/01/25 21:02:28 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void			puttypepage(t_page *page)
{
	if (page->type == 1)
		ft_putstr("TINY : ");
	else if (page->type == 2)
		ft_putstr("MEDIUM : ");
	else
		ft_putstr("LARGE : ");
	ft_atoi_hex(page);
	ft_putchar('\n');
	return ;
}

void			show_alloc_mem(void)
{
	t_page		*p;
	t_header	*h;
	void		*ptr;

	p = g_env.page;
	while (p)
	{
		puttypepage(p);
		ft_atoi_hex(p);
		h = p->start;
		while (h)
		{
			if (!h->free || h->free)
			{
				ptr = h + 1;
				ft_atoi_hex(h + 1);
				ft_putstr(" - ");
				ft_atoi_hex((char *)ptr + h->size);
				ft_putstr(" octets : ");
				ft_putchar('\n');
			}
			h = h->next;
		}
		p = p->next;
	}
}
