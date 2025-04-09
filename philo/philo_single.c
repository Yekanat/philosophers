/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_single.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:13:39 by athekkan          #+#    #+#             */
/*   Updated: 2024/04/18 20:15:48 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

/*
 * Function: single_simp
 * ----------------------
 * Simulates a single philosopher's action.
 *
 * env: Pointer to the symposium environment.
 */
void	single_simp(t_env *env)
{
	msg(&env->table[0], FORK);
	philo_usleep(env->time_to_die);
	env->table[0].is_alive = 0;
}
