/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:55:25 by nidzik            #+#    #+#             */
/*   Updated: 2016/11/11 12:18:20 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mach/vm_statistics.h>
#include "libft/libft.h"
#include <sys/mman.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>

/*
 * s_page structure to stock all page allocated informations
 */
typedef struct			s_page
{
	size_t				size;
	int					full;
	void				*start;
	char				type;
	void				*next;
}						t_page;

/*
 * s_header have all chunk information (mandatory 8 bytes)
 * 4 byte for the chuck size and 4 more to stock the pointer
 * to the next chunk
 */
typedef struct			s_header
{
	size_t				size;
	int					free;
	time_t				time;
	void				*next;
}						t_header;

/*
 * s_env stock all allocated memory informations
 * and it's global varibale
 */
typedef struct			s_env
{
	t_page				*page;
	int					set;
}						t_env;

extern t_env			g_env;
/* g_lock permit to lock or unlock a memory mutex */
pthread_mutex_t			g_lock;

/* 		Show all memory functions 	*/
void 		show_alloc_mem();
void 		ft_header_info();
void		ft_atoi_hex(void *ptr);

/* 			Malloc functions 		*/
void    	*mallocc(size_t size);
