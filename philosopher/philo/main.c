/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:24:32 by aragragu          #+#    #+#             */
/*   Updated: 2024/12/01 15:52:49 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	intitialize_mutex(t_data *data)
{
	if (pthread_mutex_init(&data->dead_lock, NULL) != 0)
		return (my_perror("Failed to initialize dead_lock mutex"), 0);
	if (pthread_mutex_init(&data->meal_lock, NULL) != 0)
		return (my_perror("Failed to initialize dead_lock mutex"), 0);
	if (pthread_mutex_init(&data->write_lock, NULL) != 0)
		return (my_perror("Failed to initialize dead_lock mutex"), 0);
	if (pthread_mutex_init(&data->full_lock, NULL) != 0)
		return (my_perror("Failed to initialize dead_lock mutex"), 0);
	data->dead_flag = 0;
	data->full_flag = 0;
	return (1);
}

int	intialize_struct(t_data *data)
{
	data->start_time = get_current_time();
	if (!intitialize_mutex(data))
		return (0);
	if (!fill_philos(data))
		return (0);
	return (1);
}

int	fill_argument2(int argc, char **argv, t_data *data)
{
	int		flag;

	flag = 1;
	if (argc == 5 || argc == 6)
	{
		data->num_of_philos = ft_atoi(argv[1], &flag);
		if (!flag || data->num_of_philos == 0)
			return (my_perror("invalid argc\n"), 0);
		data->time_to_die = ft_atoi(argv[2], &flag);
		if (!flag || data->time_to_die == 0)
			return (my_perror("invalid argc\n"), 0);
		data->time_to_eat = ft_atoi(argv[3], &flag);
		if (!flag || data->time_to_eat == 0)
			return (my_perror("invalid argc\n"), 0);
		data->time_to_sleep = ft_atoi(argv[4], &flag);
		if (!flag || data->time_to_sleep == 0)
			return (my_perror("invalid argc\n"), 0);
	}
	if (argc == 6)
	{
		data->num_times_to_eat = ft_atoi(argv[5], &flag);
		if (!flag || data->num_times_to_eat == 0)
			return (my_perror("invalid argc\n"), 0);
	}
	return (1);
}

int	fill_argument1(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (my_perror("malloc error\n"), 0);
	data->num_of_argc = argc;
	if (!valid_numbers(argv))
		return (free(data), 0);
	if (!fill_argument2(argc, argv, data))
		return (free(data), data = NULL, 0);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_of_philos);
	if (!data->forks)
		return (free(data), data = NULL, 0);
	data->philos = malloc(sizeof(t_philo) * data->num_of_philos);
	if (!data->philos)
		return (free(data->forks), data->forks = NULL,
			free(data), data = NULL, 0);
	if (!intialize_struct(data))
		return (0);
	clean_resources(data);
	free_data(data);
	return (1);
}

int	main(int argc, char *argv[])
{
	if (argc == 5 || argc == 6)
	{
		if (!fill_argument1(argc, argv))
			return (0);
	}
	else if (argc < 5 || argc > 6)
		my_perror("invalid arguments\n");
	return (0);
}
