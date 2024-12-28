/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:49:16 by aragragu          #+#    #+#             */
/*   Updated: 2024/11/27 16:38:15 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	full_philos(t_data *data)
{
	int		i;
	int		count;
	t_philo	*philo;

	i = 0;
	count = 0;
	philo = data->philos;
	while (i < data->num_of_philos)
	{
		pthread_mutex_lock(data->philos[i].meal_lock);
		if (philo[i].meals_eaten >= philo[i].num_times_to_eat)
			count++;
		pthread_mutex_unlock(data->philos[i].meal_lock);
		i++;
	}
	if (count == data->num_of_philos)
	{
		pthread_mutex_lock(&data->full_lock);
		data->full_flag = 1;
		pthread_mutex_unlock(&data->full_lock);
		return (1);
	}
	return (0);
}

int	check_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->meal_lock);
	if ((get_current_time() - philo->last_meal) > philo->time_to_die)
	{
		pthread_mutex_unlock(philo->meal_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}

int	check_dead_philos(t_data *data)
{
	int		i;
	t_philo	*philos;

	philos = data->philos;
	i = 0;
	while (i < data->num_of_philos)
	{
		if (check_dead(&philos[i]))
		{
			improved_printf(data->philos[i].id, "died", &philos[i]);
			pthread_mutex_lock(philos[i].dead_lock);
			*philos[i].dead = 1;
			pthread_mutex_unlock(philos[i].dead_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

void	*philos_monitor(void *argc)
{
	t_data	*data;

	data = (t_data *)argc;
	while (1)
	{
		if (check_dead_philos(data))
			break ;
		if (data->num_of_philos > 1 && data->num_times_to_eat > 0)
		{
			if (full_philos(data))
				break ;
		}
	}
	return (NULL);
}
