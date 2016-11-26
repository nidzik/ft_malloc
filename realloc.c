/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 19:59:35 by nidzik            #+#    #+#             */
/*   Updated: 2016/11/26 11:10:50 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		*realloc(void *ptr, size_t size)
{
	if(!ptr)
	{
		ft_putendl("no ptr go to mall(size)");
		return (ptr = mallocc(size, g_env.page));
	}
	else if (!size && ptr)
	{
		ft_putendl("!size && ptr go to mall(1)");
		free(ptr);
		ptr = mallocc(1, g_env.page);
		return (ptr);
	}
	else if (ptr && size)
	{
		ft_putendl("go ti reall");
		find_page_free();
/* 		check_size_ptr(size, ptr); */
	}
	else
	{
		ft_putendl("realloc failed for unknow reason");
		return (NULL);
	}
	return(NULL);
}


/* void		*check_size_ptr(size_t size, void *ptr) */
/* { */
/* 	if (ptr->size < size) */
/* } */
