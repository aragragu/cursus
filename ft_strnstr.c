/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:40:09 by aragragu          #+#    #+#             */
/*   Updated: 2023/11/29 18:30:37 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_ft_strncmp(const char *s1, const char *s2, size_t n, size_t len)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (i == len)
			return (1);
		if (s1[i] > s2[i] || s1[i] < s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (!*needle)
		return ((char *)haystack);
	if (!len)
		return (NULL);
	while (*haystack && len > 0)
	{
		if (*haystack == *needle 
			&& my_ft_strncmp(haystack, needle, ft_strlen(needle), len) == 0)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
