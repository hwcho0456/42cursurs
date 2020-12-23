/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 13:59:35 by hcho              #+#    #+#             */
/*   Updated: 2020/12/23 18:11:52 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int s_len;
	unsigned int len;

	s_len = 0;
	len = 0;
	while (*(src + s_len))
		s_len++;
	if (size == 0)
		return (s_len);
	while (!*(src + len) && size > 1)
	{
		*(dest + len) = *(src + len);
		len++;
		size--;
	}
	*(dest + len) = 0;
	return (s_len);
}
