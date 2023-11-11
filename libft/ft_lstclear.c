/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 21:42:28 by yyasar            #+#    #+#             */
/*   Updated: 2022/11/20 00:59:55 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (lst && del)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			del((*lst)->content);
			free(*lst);
			*lst = tmp;
		}
	}
}
/*
void	del(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*lst;
	t_list	*lst1;
	t_list	*lst2;

	lst = ft_lstnew(ft_strdup("yahya"));
	lst1 = ft_lstnew(ft_strdup("yasar"));
	lst2 = ft_lstnew(ft_strdup("42"));
	lst->next = lst1;
	lst1->next = lst2;
	printf("%s\n", lst->content);
	printf("%s\n", lst1->content);
	printf("%s\n", lst2->content);
	ft_lstclear(&lst, del);
	printf("%s\n", lst->content);
	printf("%s\n", lst1->content);
	printf("%s\n", lst2->content);
}
*/