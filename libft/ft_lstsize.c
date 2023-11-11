/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 21:20:58 by yyasar            #+#    #+#             */
/*   Updated: 2022/10/28 00:14:49 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
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
	printf("%d\n", ft_lstsize(lst));
	printf("%s", lst2->content);
}
*/