#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
//#include "../malloc.h"
#define Mo (1024 * 1024)
//void 	show_alloc_mem();
void	print(char *s)
{
	write(1, s, strlen(s));
}


int		main(void)
{
	char *addr;

	addr = malloc(16);
	putchar('a');
	free(NULL);
	free((void *)addr + 5);
	if (realloc((void *)addr + 5, 10) == NULL)
		print("Bonjours\n");
	//show_alloc_mem();
	return (0);
}
