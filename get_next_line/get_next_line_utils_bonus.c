/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:23:15 by aragragu          #+#    #+#             */
/*   Updated: 2023/12/28 14:52:42 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	if (s == NULL)
		return (0);
	len = 0;
	while (s[len] != '\0')
		++len;
	return (len);
}

char	*ft_strlcpy(char *dest, char *src, int stop)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		if (stop && src[i] == '\n')
		{
			++i;
			break ;
		}
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	if (c == '\0')
		return (1);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *buff)
{
	char			*ptr;
	size_t			i;
	size_t			y;
	size_t			len;

	len = ft_strlen(s1) + ft_strlen(buff);
	ptr = malloc(sizeof(char) * (len + 1));
	i = 0;
	y = 0;
	while (s1 != NULL && s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	free(s1);
	while (buff != NULL && buff[y] != '\0')
	{
		ptr[i++] = buff[y++];
	}
	ptr[i] = '\0';
	return (ptr);
}
