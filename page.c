/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:43:29 by nidzik            #+#    #+#             */
/*   Updated: 2016/11/22 04:49:12 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_page*			find_page(size_t size)
{
	size_t		type;
	t_page*		page;

	type = get_type(size);
	page = g_env.page;
	while (page)
	{
/* 		printf("pageol %p   pageatrat %p   pagenext %p",page, page->start, page->next );fflush(stdout); */
		if (page->type == type && page->full == 0)
		{
/* 			printf(" \n %lu    %lu \n", page->size +size + 32, page->size + size + sizeof(t_page)); */
			if ((size_t)(page->size + size + 32) > (size_t)(get_page_size_max(type)))
			{
				page->full = 1;
				page->next = new_page(type);
				page = page->next;
				page->size += size + 32;//+ sizeof(t_header);
				return (page->start);
			}
			else
			{

				page->size += size + 32;//+ sizeof(t_header);
					printf("%d\n",(int)page->size);
				return (page->start);
			}
		}
		if (page->next)
			page = page->next;
		else
			break ;
	}
	page->next = new_page(type);
	page = page->next;
				ft_putendl("ASDASDASDASD");
/* /!\ ca va peut etre tout faire bug x) */
				page->size += size + 32;// + sizeof(t_header);
	return (page->start);
}
