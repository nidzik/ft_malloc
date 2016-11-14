/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 19:11:17 by nidzik            #+#    #+#             */
/*   Updated: 2016/11/13 21:21:09 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		*create_block(size_t size, void *start_page)
{
	t_header *head;

	head = start_page;
	while (head->next)
	{
		printf("search for next head avalible\n");
		if (head->free == 1 && head->size >= size)
		{
			printf("head free and > size\n");fflush(stdout);
			create_head(size, head , head->next);
			return (head + 1);
		}
		head = head->next; 
	}
	printf("no head avalible found\n");fflush(stdout);
	create_head(size, head, NULL);
	return (head + 1);
}

void		create_head(size_t size, t_header *head, t_header *next)
{

	printf("creating header\n");
	head->size = size;
	head->free = 0;
	head->next = next;

}
