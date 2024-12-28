/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:55:45 by aragragu          #+#    #+#             */
/*   Updated: 2024/12/01 15:53:06 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

size_t	get_current_time(void)
{
	struct timeval	time;
	size_t			milleseconds;

	if (gettimeofday(&time, NULL) == -1)
		my_perror("gettimeofday() error\n");
	milleseconds = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (milleseconds);
}

void	ft_usleep(size_t milliseconds, t_philo *philo)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
	{
		pthread_mutex_lock(philo->dead_lock);
		if (*philo->dead)
		{
			pthread_mutex_unlock(philo->dead_lock);
			return ;
		}
		pthread_mutex_unlock(philo->dead_lock);
		usleep(100);
	}
	return ;
}

void	improved_printf(int id, char *str, t_philo *philo)
{
	size_t	current;

	current = get_current_time() - philo->start_time;
	pthread_mutex_lock(philo->write_lock);
	if (check_flag(philo))
		printf("%zu %d %s\n", current, id, str);
	pthread_mutex_unlock(philo->write_lock);
}

int	check_flag(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*(philo->dead) == 1)
	{
		pthread_mutex_unlock(philo->dead_lock);
		return (0);
	}
	pthread_mutex_unlock(philo->dead_lock);
	pthread_mutex_lock(philo->full_lock);
	if (*(philo->full) == 1)
	{
		pthread_mutex_unlock(philo->full_lock);
		return (0);
	}
	pthread_mutex_unlock(philo->full_lock);
	return (1);
}

void	clean_resources(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->num_of_philos)
	{
		if (pthread_mutex_destroy(&data->forks[i]))
			my_perror("coudn't destroy mutex\n");
		i++;
	}
	if (pthread_mutex_destroy(&data->dead_lock))
		my_perror("coudn't destroy mutex\n");
	if (pthread_mutex_destroy(&data->meal_lock))
		my_perror("coudn't destroy mutex\n");
	if (pthread_mutex_destroy(&data->write_lock))
		my_perror("coudn't destroy mutex\n");
	if (pthread_mutex_destroy(&data->full_lock))
		my_perror("coudn't destroy mutex\n");
}
