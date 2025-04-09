/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:04:57 by athekkan          #+#    #+#             */
/*   Updated: 2024/04/18 20:07:42 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

/*
 * Function: msg
 * -------------
 * Prints a message related to a philosopher's action.
 *
 * philo: Pointer to the philosopher performing the action.
 * str: The message to be printed.
 */
void	msg(t_philo *philo, char *str)
{
	u_int64_t	time;

	time = get_time() - philo->env->start_time;
	if (philo->is_alive || philo->env->number_of_philosophers == 1)
		printf("%lu %d %s\n", time, philo->id + 1, str);
}
