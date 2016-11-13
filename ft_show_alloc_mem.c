
#include "malloc.h"

void 		ft_header_info(void *header, size_t size)
{
	ft_atoi_hex(header);
	ft_putstr(" - ");
	ft_putstr(header + size);
	ft_putstr(ft_strjoin(" : ", size));
	ft_putstr(" octets\n");
}

void		show_alloc_mem()
{
	t_header	*header;
	t_page		*page;

	pthread_mutex_lock(&g_lock); // Lock mutex before use it
	if (g_env.page)
	{
		page = g_env.page;
		while (page) // for each page type, this will print the start page and all memory allocated part, with range and size
		{
			ft_putstr(ft_strjoin(page->type, " : "));
			ft_atoi_hex(page->start);
			ft_putchar('\n');
			header = page->start;
			// Print memory range and size
			while (header)
			{
				if (!header->free)
					ft_header_info(header, header->size);// Print all header informations
				header = header->next;
			}
			page = page->next;
		}
	}
	pthread_mutex_unlock(&g_lock); // Unlock mutex to let it use by other process
}
