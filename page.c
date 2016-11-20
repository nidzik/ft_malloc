/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:43:29 by nidzik            #+#    #+#             */
/*   Updated: 2016/11/20 19:48:27 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"


t_page*			find_page(size_t size)
{
	size_t		type;
	t_page*		page;
	ft_putendl("avt");

	type = get_type(size);
	page = g_env.page;
				printf("avt %p \n", page->start);fflush(stdout);
	while (page)
	{
		printf("pageol %p   pageatrat %p   pagenext %p",page, page->start, page->next );fflush(stdout);
		if (page->type == type && page->full == 0)
		{
			printf("1st if %d \n", (int)(get_page_size_max(type)));fflush(stdout); 
			if ((size_t)(page->size + size + 32) > (size_t)(get_page_size_max(type)) )
			{

				page->full = 1;
				page->next = new_page(type);
				printf("2nd %p \n", page->next);
				page = page->next ;
				return(page->start);
			}
			else
			{
				printf("else %p  %d adding %d \n", page, (int)page->size, (int)size);fflush(stdout);
				page->size += size + 32;
				return (page->start);
			}

		}
		//ft_putstr("infiniteloop");
			page = page->next;
	}
	ft_putendl("apr");
	page = new_page(type);

	return (page->start);
}


/* size_t		get_max_size(size_t type, size_t size) */
/* { */
/* 	if (type == TINY) */
/* 		return (PAGE_TINY_SIZE); */
/* 	else if (type == SMALL) */
/* 		return (PAGE_SMALL_SIZE); */
/* 	else if (type == LARGE) */
/* 		return (size); */
/* 	return (0); */
/* } */
