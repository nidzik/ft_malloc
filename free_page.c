/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_page.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 18:34:46 by nidzik            #+#    #+#             */
/*   Updated: 2017/01/27 20:03:12 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		free_page(t_page *p, t_page *prev)
{
	t_header	*h;

	h = p->start;
	if (prev == NULL)
		return ;
	while (h->next)
	{
		if (h->free == 1)
			h = h->next;
		else if (h->free == 0)
			return ;
	}
	prev->next = p->next;
	munmap(p, p->size);
}
