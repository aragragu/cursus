/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:34:42 by aragragu          #+#    #+#             */
/*   Updated: 2023/11/23 16:46:31 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memset(void *s, int x, size_t len)
{
	size_t			i;

	i = 0;
	while (i < len)
	{
		*((unsigned char *)s + i) = (unsigned char)x; 
		i++;
	}
	return (s);
}
