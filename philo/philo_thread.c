/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:29:10 by athekkan          #+#    #+#             */
/*   Updated: 2024/04/18 20:29:11 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

/*
 * Function: stream
 * -----------------
 * Starts the simulation stream for all philosophers.
 * This function initiates the simulation stream
 * by creating and joining threads for each philosopher.
 *
 * env: Pointer to the symposium environment.
 *
 * Returns: 0 if successful, 1 otherwise.
 */
int	stream(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->number_of_philosophers)
	{
		if (pthread_create(&env->table[i].philo, NULL,
				&routine, &env->table[i]))
			return (1);
		i++;
	}
	i = 0;
	while (i < env->number_of_philosophers)
	{
		if (pthread_join(env->table[i].philo, NULL))
			return (1);
		i++;
	}
	free(env->table);
	return (0);
}
