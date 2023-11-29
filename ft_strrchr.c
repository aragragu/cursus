/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:43:30 by aragragu          #+#    #+#             */
/*   Updated: 2023/11/29 17:56:14 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int c)
{
	int			i;
	char		*str;

	i = 0;
	str = (char *)string;
	while (string[i])
		i++;
	while (i >= 0)
	{
		if (string[i] == (char)c)
			return (&str[i]);
		i--;
	}
	return (0);
}
