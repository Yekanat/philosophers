/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 01:59:57 by athekkan          #+#    #+#             */
/*   Updated: 2024/04/18 20:01:33 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

/*
 * Function: philo_usleep
 * -----------------------
 * Suspends the execution of the calling thread
 * for the specified number of milliseconds.
 * 
 * This function uses a busy-wait loop to wait
 * for the specified duration.
 * 
 * ms: The number of milliseconds to sleep.
 */
void	philo_usleep(int ms)
{
	u_int64_t	starting_t;

	starting_t = get_time();
	while ((get_time() - starting_t) < (u_int64_t)ms)
		usleep(ms / 10);
}

/*
 * Function: get_time
 * -------------------
 * Gets the current time in milliseconds since the Epoch.
 * 
 * This function retrieves the current system time
 * and converts it to milliseconds.
 * 
 * Returns: The current time in milliseconds.
 */
u_int64_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / (u_int64_t)1000));
}

/*
 * Function: philo_init
 * ---------------------
 * Initializes a philosopher with the specified ID
 * and sets initial values for its attributes.
 * 
 * This function initializes a philosopher structure
 * with default values and sets its ID and next fork index.
 * 
 * env: A pointer to the environment structure.
 * i: The ID of the philosopher to initialize.
 *
 * Returns: 0 if successful, 1 otherwise.
 */
int	philo_init(t_env *env, int i)
{
	env->table[i].id = i;
	env->table[i].is_alive = 1;
	env->table[i].is_eating = 0;
	env->table[i].eat_count = 0;
	env->table[i].env = env;
	if (i == env->number_of_philosophers - 1)
		env->table[i].next_fork = 0;
	else
		env->table[i].next_fork = i + 1;
	if (pthread_mutex_init(&env->table[i].fork, NULL))
		return (1);
	return (0);
}

/*
 * Function: init_symposium
 * -------------------------
 * Initializes the symposium environment
 * with the specified arguments.
 * 
 * This function initializes the symposium environment
 * by parsing command-line arguments,
 * allocating memory for philosophers
 * and initializing mutexes.
 * 
 * env: A pointer to the environment structure.
 * argc: The number of command-line arguments.
 * argv: The array of command-line arguments.
 *
 * Returns: 0 if successful, 1 otherwise.
 */
int	init_symposium(t_env *env, int argc, char **argv)
{
	int	i;

	env->number_of_philosophers = ft_atoi(argv[1]);
	env->time_to_die = ft_atoi(argv[2]);
	env->time_to_eat = ft_atoi(argv[3]);
	env->time_to_sleep = ft_atoi(argv[4]);
	env->start_time = get_time();
	if (argc == 6)
		env->max_eat = ft_atoi(argv[5]);
	else
		env->max_eat = -1;
	env->table = (t_philo *)malloc(sizeof(t_philo)
			* env->number_of_philosophers);
	if (pthread_mutex_init(&env->lock, NULL))
		return (1);
	i = 0;
	while (i < env->number_of_philosophers)
	{
		if (philo_init(env, i))
			return (1);
		i++;
	}
	return (0);
}
