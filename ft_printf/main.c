#include <stdio.h>
#include "ft_printf.h"

int main()
{
	int a = ft_printf("%#20.10X\n", -27);
	int b = printf("%#20.10X\n", -27);
	printf("ft vs real : %d %d\n", a, b);
	return 0;
}
