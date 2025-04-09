/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:02:38 by athekkan          #+#    #+#             */
/*   Updated: 2024/04/18 20:07:23 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

/*
 * Function: input_check
 * ----------------------
 * Checks if the input arguments are valid.
 * 
 * This function verifies that all command-line arguments
 * consist of digits.
 * 
 * argv: The array of command-line arguments.
 *
 * Returns: 0 if input is valid, 1 otherwise.
 */
int	input_check(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < 48 || argv[i][j] > 57)
			{
				printf("ERROR:\nInvalid input\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
