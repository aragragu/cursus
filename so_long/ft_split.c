/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:12:14 by aragragu          #+#    #+#             */
/*   Updated: 2024/06/08 18:49:30 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = s;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}
static void	*ft_calloc(size_t count, size_t size)
{
	void	*data;

	if (count > 0 && size > 9223372036854775807ULL / count)
		return (0);
	data = malloc(count * size);
	if (!data)
		return (NULL);
	ft_bzero(data, (count * size));
	return (data);
}


static	int	count_words(const char *s, char c)
{
	size_t		count;
	const char	*ptr;

	count = 0;
	ptr = s;
	while (*ptr)
	{
		while (*ptr == c)
			ptr++;
		if (*ptr)
		{
			while (*ptr && *ptr != c)
				ptr++;
			count++;
		}
	}
	return (count);
}

static	size_t	count_letter(const char *s, int position, char c)
{
	size_t		i;
	char		*p;

	p = (char *)s;
	i = 0;
	while (*(s + position + i) && *(s + position + i) != c)
		i++;
	return (i);
}

static void	ft_free1(char **reslut, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		free(reslut[i]);
		i++;
	}
	free(reslut);
}

static	char	**allocation(char **s, const char *x, int i, char c)
{
	int			z;
	int			y;

	y = 0;
	while (x[i])
	{
		z = 0;
		while (x[i] && x[i] == c)
			++i;
		if (x[i])
		{
			s[y] = (char *)ft_calloc((count_letter(x, i, c) + 1), sizeof(char));
			if (!s[y])
			{
				ft_free1(s, y);
				return (NULL);
			}
			while (x[i] && x[i] != c)
				s[y][z++] = x[i++];
			y++;
		}
	}
	return (s);
}

char	**ft_split(char const *s, char c)
{
	int			i;
	char		**result;
	size_t		count;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	result = (char **)ft_calloc((count + 1), sizeof(char *));
	if (!result)
		return (NULL);
	result[count] = NULL;
	i = 0;
	result = allocation(result, s, i, c);
	return (result);
}
