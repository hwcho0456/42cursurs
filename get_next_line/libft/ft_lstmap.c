/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 08:21:17 by hcho              #+#    #+#             */
/*   Updated: 2020/12/24 18:27:41 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*curr;
	t_list	*new_elem;

	if (!lst || !f)
		return (0);
	if ((new_list = ft_lstnew(f(lst->content))) == 0)
		return (0);
	curr = new_list;
	lst = lst->next;
	while (lst)
	{
		if ((new_elem = ft_lstnew(f(lst->content))) == 0)
		{
			ft_lstclear(&new_list, del);
			return (0);
		}
		curr->next = new_elem;
		curr = new_elem;
		lst = lst->next;
	}
	return (new_list);
}
