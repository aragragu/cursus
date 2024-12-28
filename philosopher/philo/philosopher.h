/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:25:02 by aragragu          #+#    #+#             */
/*   Updated: 2024/12/01 15:53:11 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;		
	int				num_of_philos;
	int				num_times_to_eat;
	int				*dead;
	int				*full;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
	pthread_mutex_t	*full_lock;
}					t_philo;

typedef struct s_data
{
	size_t			start_time;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				num_of_philos;
	int				num_times_to_eat;
	int				num_of_argc;
	int				dead_flag;
	int				full_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	full_lock;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}					t_data;

int		ft_atoi(const char *str, int *succes);
int		valid_numbers(char **argv);
int		fill_philos(t_data *data);
int		fill_argument1(int argc, char **argv);
int		fill_argument2(int argc, char **argv, t_data *data);
int		intialize_struct(t_data *data);
int		intitialize_mutex(t_data *data);
void	fill_philos_2(t_data *data, t_philo *philo, int i);
size_t	get_current_time(void);
int		initialize_forks(int num_of_philos, pthread_mutex_t *forks,
			t_philo *philos);
void	my_perror(char *str);
void	ft_usleep(size_t milliseconds, t_philo *philo);
int		take_fork(t_philo *philo);
void	eat(t_philo *philo);
void	put_fork(t_philo *philo);
void	put_to_sleep(t_philo *philo);
void	*routine(void *argc);
void	*philos_monitor(void *data);
int		check_flag(t_philo *philo);
void	improved_printf(int id, char *str, t_philo *philo);
void	free_data(t_data *data);
void	clean_resources(t_data *data);
int		check_args(char *argv);

#endif