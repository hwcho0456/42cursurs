#include <stdio.h>
#include "ft_printf.h"

int main()
{
	wchar_t *s = L"안녕하세요";
	int a = ft_printf("%lc\n", s);
	int b = printf("%S\n", s);
	printf("ft vs real : %d %d\n", a, b);
	return 0;
}
