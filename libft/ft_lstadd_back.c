/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 21:31:54 by yyasar            #+#    #+#             */
/*   Updated: 2022/10/28 00:54:32 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!*lst)
		*lst = new;
	else
	{
		temp = ft_lstlast(*lst);
		temp->next = new;
	}
}
/*
int	main(void)
{
	t_list	*lst;
	t_list	*lst1;
	t_list	*new;

	lst = ft_lstnew("yahya");
	lst1 = ft_lstnew("42");
	new = ft_lstnew("kou");
	lst->next = lst1;
	ft_lstadd_back(&lst, new);
	printf("%d", ft_lstsize(lst));
}
*/