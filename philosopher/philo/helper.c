/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:44:52 by aragragu          #+#    #+#             */
/*   Updated: 2024/12/01 15:34:33 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	fill_philos_2(t_data *data, t_philo *philo, int i)
{
	philo->id = i + 1;
	philo->eating = 0;
	philo->meals_eaten = 0;
	philo->last_meal = data->start_time;
	philo->time_to_die = data->time_to_die;
	philo->time_to_eat = data->time_to_eat;
	philo->time_to_sleep = data->time_to_sleep;
	philo->num_of_philos = data->num_of_philos;
	if (data->num_of_argc == 6)
		philo->num_times_to_eat = data->num_times_to_eat;
	else
		philo->num_times_to_eat = 0;
	philo->dead = &data->dead_flag;
	philo->full = &data->full_flag;
	philo->write_lock = &data->write_lock;
	philo->dead_lock = &data->dead_lock;
	philo->meal_lock = &data->meal_lock;
	philo->full_lock = &data->full_lock;
	philo->start_time = data->start_time;
}

int	initialize_forks(int num_of_philos, pthread_mutex_t *forks,
	t_philo *philos)
{
	int		i;

	i = 0;
	while (i < num_of_philos)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
			return (my_perror("Failed to initialize mutex"), 0);
		i++;
	}
	i = 0;
	while (i < num_of_philos)
	{
		if (num_of_philos == 1)
		{
			philos[i].right_fork = &forks[i];
			philos[i].left_fork = &forks[i];
		}
		else
		{
			philos[i].right_fork = &forks[i];
			philos[i].left_fork = &forks[(i + 1) % num_of_philos];
		}
		i++;
	}
	return (1);
}

int	join_threads(t_data *data, pthread_t monitor)
{
	t_philo	*philo;
	int		i;

	philo = data->philos;
	i = 0;
	while (i < data->num_of_philos)
	{
		if (pthread_join(philo[i].thread, NULL) != 0)
			return (my_perror("error joining thread\n"), 0);
		i++;
	}
	if (pthread_join(monitor, NULL) != 0)
		return (my_perror("error joining thread\n"), 0);
	return (1);
}

int	handle_threads(t_data *data)
{
	int			i;
	pthread_t	monitor;

	i = 0;
	if (pthread_create(&monitor, NULL, philos_monitor, (void *)data) != 0)
		return (my_perror("Failed to create monitor thread\n"), 0);
	while (i < data->num_of_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL, routine,
				(void *)&data->philos[i]) != 0)
			return (my_perror("Failed to create philosopher thread\n"), 0);
		i++;
	}
	if (!join_threads(data, monitor))
		return (0);
	return (1);
}

int	fill_philos(t_data *data)
{
	int					i;

	i = 0;
	if (!initialize_forks(data->num_of_philos, data->forks, data->philos))
		return (0);
	data->start_time = get_current_time();
	while (i < data->num_of_philos)
	{
		fill_philos_2(data, &data->philos[i], i);
		i++;
	}
	if (!handle_threads(data))
		return (0);
	return (1);
}
