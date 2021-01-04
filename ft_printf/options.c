/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:05:30 by hcho              #+#    #+#             */
/*   Updated: 2021/01/04 15:20:10 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct	option
{
	char	minus;
	char	plus;
	char	space;
	char	sharp;
	char	zero;
	int		width;
	int		prec;
	int		len;
}				options;

options			*init_option(void)
{
	options	*list;

	list = (options *)malloc(sizeof(options));
	if (!list)
		return (0);
	list->minus = 0;
	list->plus = 0;
	list->space = 0;
	list->sharp = 0;
	list->zero = 0;
	list->width = 0;
	list->prec = 0;
	list->len = 0;
	return (list);
}

options			*get_flag(const char *format, size_t *i, options *list)
{
	while (*(format + *i))
	{
		if (*(format + *i) == '-')
			list->minus = 1;
		else if (*(format + *i) == '+')
			list->plus = 1;
		else if (*(format + *i) == ' ')
			list->space = 1;
		else if (*(format + *i) == '#')
			list->sharp = 1;
		else if (*(format + *i) == '0')
			list->zero = 1;
		else 
			break ;
		*i += 1;
	}
	return (list);
}

options			*get_width(const char *format, va_list ap, size_t *i, options *list)
{
	while (*(format + *i) >= '0' && *(format + *i) <= '9')
	{
		list->width = 10 * list->width + *(format + *i) - '0';
		*i += 1;
	}
	if (*(format + *i) == '*')
	{
		list->width = va_arg(ap, int);
		*i += 1;
	}
	if (list->width < 0)
	{
		list->minus = 1;
		list->width = -list->width;
	}
	return (list);
}

options			*get_spec(const char *format, va_list ap, size_t *i, options *list)
{
	while (*(format + *i) >= '0' && *(format + *i) <= '9')
	{
		list->spec = 10 * list->width + *(format + *i) - '0';
		*i += 1;
	}
	if (*(format + *i) == '*')
	{
		list->spec = va_arg(ap, int);
		*i += 1;
	}
	if (list->spec < 0)
		list->spec = 0;
	return (list);
}

options			*get_length(const char *format,  size_t *i, options *list)
{
	if (*(format + *i) == 'l')
	{
		list->len += 1;
		*i += 1;
		if (*(format + *i) == 'l')

	}
}
