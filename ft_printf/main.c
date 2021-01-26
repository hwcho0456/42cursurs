#include <stdio.h>
#include "ft_printf.h"

int main()
{
	int a = ft_printf("%.0g %.1g %.2g", -9.9, -9.5, -9.9);	
	printf("\n");	
	int b = printf("%.0g %.1g %.2g", -9.9, -9.5, -9.9);	
	printf("\n");
	printf("ft vs real : %d %d\n", a, b);
	return 0;
}
