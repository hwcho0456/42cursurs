#include <stdio.h>
#include "ft_printf.h"

int main()
{
	int a = ft_printf("% .u\n", 0);
	int b = printf("% .u\n", 0);
	printf("ft vs real : %d %d\n", a, b);
	return 0;
}
