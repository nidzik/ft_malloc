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
addr[0] = 42;
i++; 
} 
return (0); 
} 
