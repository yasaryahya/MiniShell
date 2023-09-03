/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 22:08:22 by yyasar            #+#    #+#             */
/*   Updated: 2022/11/20 11:10:09 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*#include <fcntl.h>

int	main(void)
{
	int	fd = open("dosya.txt", O_WRONLY | O_CREAT | O_RDONLY, 777);
	int	fd2 = open("yahya.txt", O_WRONLY | O_CREAT | O_RDONLY, 777);

	ft_putchar_fd('c', fd);
	ft_putchar_fd('z', fd2);
	printf("%d\n", fd);
	printf("%d", fd2);
}*/