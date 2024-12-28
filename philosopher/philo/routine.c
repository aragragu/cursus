/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:23:30 by aragragu          #+#    #+#             */
/*   Updated: 2024/11/24 17:26:34 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	improved_printf(philo->id, "has taken a fork", philo);
	if (philo->num_of_philos == 1)
	{
		pthread_mutex_unlock(philo->right_fork);
		return (1);
	}
	pthread_mutex_lock(philo->left_fork);
	improved_printf(philo->id, "has taken a fork", philo);
	return (0);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	improved_printf(philo->id, "is eating", philo);
	ft_usleep(philo->time_to_eat, philo);
}

void	put_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	put_to_sleep(t_philo *philo)
{
	improved_printf(philo->id, "is sleeping", philo);
	ft_usleep(philo->time_to_sleep, philo);
}

void	*routine(void *argc)
{
	t_philo		*philo;

	philo = (t_philo *)argc;
	if (philo->id % 2 == 0)
		ft_usleep(philo->time_to_eat, philo);
	while (check_flag(philo))
	{
		if (take_fork(philo))
			return (NULL);
		eat(philo);
		put_fork(philo);
		put_to_sleep(philo);
		improved_printf(philo->id, "is thinking", philo);
	}
	return (NULL);
}
