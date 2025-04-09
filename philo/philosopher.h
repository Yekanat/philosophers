/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 02:56:19 by athekkan          #+#    #+#             */
/*   Updated: 2024/04/18 20:29:59 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIE "died"

# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>

struct	s_env;

typedef struct s_philo
{
	pthread_t		philo;
	int				id;
	int				is_alive;
	int				is_eating;
	int				eat_count;
	int				next_fork;
	u_int64_t		time_left;
	pthread_t		supervisor;
	pthread_mutex_t	fork;
	struct s_env	*env;
}	t_philo;

typedef struct s_env
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_eat;
	u_int64_t		start_time;
	pthread_mutex_t	lock;
	t_philo			*table;
}	t_env;

int			stream(t_env *env);
int			input_check(char **argv);
int			init_symposium(t_env *env, int argc, char **argv);
int			ft_atoi(const char *str);
u_int64_t	get_time(void);
void		philo_usleep(int ms);
void		msg(t_philo *philo, char *str);
void		single_simp(t_env *env);
void		*routine(void *data);

#endif