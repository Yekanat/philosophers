/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 02:56:58 by athekkan          #+#    #+#             */
/*   Updated: 2024/04/18 20:30:31 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

/*
 * Function: eating
 * ----------------
 * Simulates a philosopher eating.
 * This function implements the behavior of a philosopher
 * while eating, including acquiring forks,
 * eating for a specified duration, and updating the eat count.
 *
 * philo: Pointer to the philosopher.
 */
void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	msg(philo, FORK);
	pthread_mutex_lock(&philo->env->table[philo->next_fork].fork);
	msg(philo, FORK);
	philo->is_eating = 1;
	philo->time_left += philo->env->time_to_die;
	msg(philo, EAT);
	philo_usleep(philo->env->time_to_eat);
	philo->eat_count++;
	philo->is_eating = 0;
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->env->table[philo->next_fork].fork);
}

/*
 * Function: kill_all_simps
 * -------------------------
 * Kills all philosophers.
 * This function sets the is_alive flag to 0
 * for all philosophers in the environment,
 * effectively killing them.
 *
 * env: Pointer to the symposium environment.
 */
void	kill_all_simps(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->number_of_philosophers)
	{
		env->table[i].is_alive = 0;
		i++;
	}
}

/*
 * Function: supervisor
 * ---------------------
 * Monitors a philosopher's activity and decides
 * whether it should die.
 * 
 * This function supervises a philosopher's activity and decides
 * whether it should die based on
 * predefined conditions.
 * If the philosopher exceeds its time to eat
 * or reaches the maximum eat count,
 * it dies; otherwise, it is considered to have died of starvation.
 *
 * data: Pointer to the philosopher.
 *
 * Returns: Always returns NULL.
 */
void	*supervisor(void *data)
{
	t_philo	*philo;

	philo = (t_philo *) data;
	while (get_time() < philo->time_left && (philo->env->max_eat == -1
			|| philo->eat_count < philo->env->max_eat))
		;
	if (philo->eat_count >= philo->env->max_eat && philo->env->max_eat > 0)
		philo->is_alive = 0;
	else
	{
		pthread_mutex_lock(&philo->env->lock);
		msg(philo, DIE);
		kill_all_simps(philo->env);
		pthread_mutex_unlock(&philo->env->lock);
	}
	return ((void *) 0);
}

/*
 * Function: routine
 * ------------------
 * Executes the routine of a philosopher.
 * This function represents the routine
 * executed by each philosopher,
 * including setting up the supervisor,
 * eating, sleeping, and thinking.
 *
 * data: Pointer to the philosopher.
 *
 * Returns: Always returns NULL.
 */
void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	philo->time_left = philo->env->time_to_die + get_time();
	if (philo->id % 2 != 0 && philo->env->number_of_philosophers > 1)
		philo_usleep(10);
	if (pthread_create(&philo->supervisor, NULL, &supervisor, data))
		return ((void *) 1);
	pthread_detach(philo->supervisor);
	while (philo->is_alive)
	{
		if (philo->env->number_of_philosophers == 1)
			single_simp(philo->env);
		else
		{
			eating(philo);
			msg(philo, SLEEP);
			philo_usleep(philo->env->time_to_sleep);
			msg(philo, THINK);
		}
	}
	return ((void *) 0);
}
