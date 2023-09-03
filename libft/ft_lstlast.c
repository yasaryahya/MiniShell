/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 21:27:08 by yyasar            #+#    #+#             */
/*   Updated: 2022/11/20 00:48:48 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
/*
int	main(void)
{
	t_list	*lst;
	t_list	*lst1;
	t_list	*lst2;

	lst = ft_lstnew("yahya");
	lst1 = ft_lstnew("42");
	lst2 = ft_lstnew("kou");
	lst->next = lst1;
	lst1->next = lst2;
	printf("%s", ft_lstlast(lst)->content);
}
*/