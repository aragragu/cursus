/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:01:43 by aragragu          #+#    #+#             */
/*   Updated: 2023/11/29 19:35:51 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int		i;
	char	c;

	i = 0;
	c = '\n';
	if (!s || fd < 0)
		return ;
	ft_putstr_fd(s, fd);
	write(fd, &c, 1);
}
