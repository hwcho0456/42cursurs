/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho </var/mail/hcho>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 18:28:13 by hcho              #+#    #+#             */
/*   Updated: 2020/12/22 18:34:34 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

char	*ft_strjoin(char const s1, char const s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	while (*(s1 + i))
		i++;
	j = 0;
	while (*(s2 + i))
		j++;
	
	str = (char *)malloc(sizeof(

}
