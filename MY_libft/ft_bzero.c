/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:26:44 by aragragu          #+#    #+#             */
/*   Updated: 2023/11/25 18:41:41 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_bzero(char *s, size_t n)
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

// int main(int argc, char *argv[])
// {
// 	int i = 0;
		
// 	if (argc < 2)
// 		return 0;
// 	ft_bzero(argv[1], ft_strlen(argv[1]));
// 	printf("|%s|\n", argv[1]);
// }
