/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 07:59:47 by hcho              #+#    #+#             */
/*   Updated: 2020/12/24 08:43:38 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		cnt;
	t_list	*list;

	cnt = 0;
	list = lst;
	while (list)
	{
		list = list->next;
		cnt++;
	}
	return (cnt);
}
