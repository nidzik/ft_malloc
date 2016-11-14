/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:55:25 by nidzik            #+#    #+#             */
/*   Updated: 2016/11/14 09:41:14 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mach/vm_statistics.h>
#include "libft/libft.h"
#include <sys/mman.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>

#define FLAGS_PROT PROT_READ | PROT_WRITE
#define FLAGS_MAP MAP_ANON | MAP_PRIVATE
#define FLAGS FLAGS_PROT ,FLAGS_MAP, -1, 0

#define TINY 1
#define SMALL 2
#define LARGE 3

#define PAGE_SIZES getpagesize()

#define TINY_SIZE (size_t) (PAGE_SIZES)
#define SMALL_SIZE (size_t) (PAGE_SIZES * 20)

#define PAGE_TINY_SIZE TINY_SIZE * 100
#define PAGE_SMALL_SIZE SMALL_SIZE * 100

/*
 * s_page structure to stock all page allocated informations
 */
typedef struct			s_page
{
	size_t				size;
	int					full;
	void				*start;
	size_t				type;
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
void 		ft_header_info(void *header, site_t size);
void		ft_atoi_hex(void *ptr);

/* 			Malloc functions 		*/
void    	*mallocc(size_t size);

/* 			Free functions			*/
void 		free(void *ptr);

void		init_genv();
size_t		get_type(size_t size);
t_page 		*new_page(size_t size);
void		*create_block(size_t size, void *start_page);
void		create_head(size_t size, t_header *head, t_header *next);

