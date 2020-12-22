/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 01:36:18 by hcho              #+#    #+#             */
/*   Updated: 2020/11/30 16:25:10 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int f_len;
	int find;

	if (!*(to_find))
		return (str);
	while (*(str))
	{
		if (*(str) == *to_find)
		{
			find = 1;
			f_len = -1;
			while (*(to_find + (++f_len)))
			{
				if (*(str + f_len) != *(to_find + f_len))
				{
					find = 0;
					break ;
				}
			}
			if (find == 1)
				return (str);
		}
		str++;
	}
	return (0);
}
