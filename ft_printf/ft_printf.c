/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 10:51:46 by hcho              #+#    #+#             */
/*   Updated: 2021/01/04 13:02:01 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

int		is_flag(const char c)
{
	if (c == '-')
	{
		
		return (1);
	}
	else if (c == '+')
		return (1);
	else if (c == ' ')
		return (1);
	else if (c == '#')
		return (1);
	else if (c == '0')
		return (1);
	return (0);
}

int		get_value(const char *format, va_list ap, size_t *i)
{
	int value;

	value = 0;
	while (*(format + *i) >= '0' && *(format + *i) <= '9')
	{
		value = 10 * value + *(format + *i) - '0';
		*i += 1;
	}
	if (*(format + *i) == '*')
	{
		value = va_arg(ap, int);
		*i += 1;
	}
	return (value);
}

void	process(const char *format, va_list ap, size_t *i, int *cnt)
{
	char flag[5];
	int	width;
	int prec;
	int	len;

	flag[0] = 0;
	flag[1] = 0;
	flag[2] = 0;
	flag[3] = 0;
	flag[4] = 0;
	width = 0;
	prec = 0;
	len = 0;
	while (is_flag(*(format + *i), flag))
		*i += 1;
	width = get_value(format, ap, &i);
	if (*(format + *i) == '.')
		prec = get_value(format, ap, &i);
	if (
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	i;
	int		cnt;	
	
	va_start(ap, format);
	cnt = 0;
	i = 0;
	while (*(format + i))
	{
		if (*(format + i) == '%')
		{
			i++;
			process(format, ap, &i, &cnt);
		}
		else
		{
			write(1, format + i, 1);
			cnt++;
		}
		i++;
	}
	va_end(ap);
	return (cnt);
}

int main()
{
	int a = ft_printf("%#s32435436564", 5);
}
