#include <stdlib.h> 
#include "../malloc.h"
int main() 
{ 
int i; 
char *addr; 

i = 0; 
while (i < 1024) 
{
	addr = (char*)mallocc(1024, g_env.page);	
	//ft_putendl("ENDTHISMALLOCMAIN STARTING SHOWALLOMEME");
	//ft_putendl("1111111111111 end show alloc meme in main go to free ");
	addr[0] = 42;
	free(addr);
	i++; 
} 
	show_alloc_mem();
return (0); 
} 
