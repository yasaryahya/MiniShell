/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 21:10:19 by yyasar            #+#    #+#             */
/*   Updated: 2022/11/20 01:05:22 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new -> next = *lst;
	*lst = new;
}
/*
int	main(void)
{
	t_list	*lst;
	t_list	*lst1;
	t_list	*new;

	new = ft_lstnew("42");
	ft_lstadd_front(&lst, new);
	printf("%s\n", lst->content);
	printf("%s\n", new->content);
	printf("%p", new->next);
}
*/
