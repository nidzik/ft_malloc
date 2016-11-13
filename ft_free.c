#include "malloc.h"

int         ft_page(t_page *page)
{
    if (page->size == 0 || strlen(page->type) == 0 || !page->start)
        return (0);

    while (page)
    {

    }

    return (1);
}

int         ft_header(t_header *header)
{
    return (1);
}

void        free(void *ptr)
{
    t_header	*header;
	t_page		*page;

    // Check if header and page exist
    if (ptr && ft_page(page) && ft_header(header))
    {
        pthread_mutex_lock(&g_lock); // Lock mutex before use it



        pthread_mutex_unlock(&g_lock); // Unlock mutex to let it use by other process
    }
    header->free = 1;
}
