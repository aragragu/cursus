/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:58:16 by aragragu          #+#    #+#             */
/*   Updated: 2023/12/05 14:28:27 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		d_len;
	size_t		s_len;
	size_t		x;

	s_len = ft_strlen(src);
	if (size == 0)
		return (s_len);
	d_len = ft_strlen(dst);
	if (size <= d_len)
		return (size + s_len);
	x = 0;
	while (src[x] && d_len + x < size - 1)
	{
		dst[d_len + x] = src[x];
		x++;
	}
	dst[d_len + x] = '\0';
	return (d_len + s_len);
}
