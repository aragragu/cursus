/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:59:18 by aragragu          #+#    #+#             */
/*   Updated: 2023/11/25 19:00:00 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}

// int main(int argc, char *argv[])
// {
// 	int i = 'a';
	
// 	if (argc < 2)
// 		return 0;
// 	printf("%d\n", ft_isalpha(argv[1][0]));
// 	printf("%d", ft_isalpha(i));
// }