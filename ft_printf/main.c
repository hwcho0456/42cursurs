#include <stdio.h>
#include "ft_printf.h"

int main()
{
	char *s = "abcde";
	int t;
	int u;
	int a = ft_printf("%30.0s \n%n", s, &u);
	int b = printf("%+- 0#.s \n%n", s, &t);
	printf("%d %d\n", u, t);
	printf("ft vs real : %d %d\n", a, b);
	return 0;
}
