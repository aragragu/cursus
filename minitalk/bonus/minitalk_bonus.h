/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 02:43:13 by aragragu          #+#    #+#             */
/*   Updated: 2024/03/26 03:07:18 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "../ft_printf/ft_printf.h"

int		ft_atoi(const char *str);
int		checkdigits(char *s);
void	bad_pid(void);
void	bad_pid_limit(void);
void	synthax_error(void);

#endif 