#include <stdio.h>
#include "ft_printf.h"

int main()
{
	int a = ft_printf("%lg\n", 1.000003003e-100);
	int b = printf("%lg\n", 1.000003003e-100);
	printf("ft vs real : %d %d\n", a, b);
	return 0;
}
