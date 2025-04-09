/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 02:56:51 by athekkan          #+#    #+#             */
/*   Updated: 2024/04/18 20:14:22 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

/*
 * Function: ft_atoi
 * ------------------
 * Converts a string to an integer.
 *
 * str: The string to convert.
 *
 * Returns: The converted integer value.
 */
int	ft_atoi(const char *str)
{
	int	sign;
	int	num;
	int	i;

	sign = 1;
	num = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10;
		num += (str[i] - 48);
		i++;
	}
	num *= sign;
	return (num);
}

/*
 * Function: ft_exit
 * ------------------
 * Cleans up resources and exits the program.
 *
 * env: Pointer to the symposium environment.
 * status: Exit status code.
 *
 * Returns: The exit status code.
 */
int	ft_exit(t_env *env, int status)
{
	int	i;

	i = 0;
	while (i < env->number_of_philosophers)
	{
		pthread_mutex_destroy(&env->table[i].fork);
		printf ("philo id: %d\n", i + 1);
		printf ("eat count--- %d\n", env->table->eat_count);
		i++;
	}
	pthread_mutex_destroy(&env->lock);
	return (status);
}

/*
 * Function: main
 * ---------------
 * Entry point of the program.
 *
 * argc: Number of command-line arguments.
 * argv: Array of command-line arguments.
 *
 * Returns: The exit status code.
 */
int	main(int argc, char **argv)
{
	t_env	env;

	if (argc < 5 || argc > 6)
	{
		printf("ERROR: Argument count not valid\n");
		return (1);
	}
	if (input_check(argv))
		return (1);
	if (init_symposium(&env, argc, argv))
	{
		free(env.table);
		return (ft_exit(&env, 1));
	}
	if (stream(&env))
		return (ft_exit(&env, 1));
	return (ft_exit(&env, 0));
}
