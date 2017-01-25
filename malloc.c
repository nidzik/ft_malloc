/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:24:23 by nidzik            #+#    #+#             */
/*   Updated: 2017/01/24 04:25:09 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_env		g_env;

void		*malloc(size_t size)
{
			ft_putchar('f');
	return(mallocc(size, g_env.page));
}
void		*mallocc(size_t size, t_page *p)
{
	size_t 	type;
/* 	t_page	*popopopo; */
	type = get_type(size);
	printf("\n%d\n", (int)type);fflush(stdout);
	if (!p)
	{
		printf("page do not exist %d \n", (int)type);fflush(stdout);
/*		if (type == 3)
		{

			popopopo = new_page(type);
			return (mmap(popopopo->start, size, FLAGS));
		}
		else*/
		//{
		g_env.page = new_page(type, size);
			g_env.page->size += size + 32;
			//}
		return (create_block(size, g_env.page->start));
/* 		printf("malloc at %p \n\n", (g_env.page->start));fflush(stdout); */
	}
	else if (p)
	{
		printf("page exist  p->start : %p \n", p->start);fflush(stdout);
/* 		if (type == 3) */
		
/* 			find_page(size); */

		
/* 		else */
			return (create_block(size, find_page(size)));
	}
	else
	{
		ft_putendl("bug");
		return (NULL);
	}
	return (g_env.page->start);
}
