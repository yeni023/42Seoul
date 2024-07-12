/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:33:12 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/12/20 17:15:37 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>

# define KO 1
# define OK 0

typedef struct s_info
{
	int				num_of_philos;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	int				must_eat_count;
	long long		start_time;
	pthread_mutex_t	mutex_of_full_philo_cnt;
	int				full_philo_cnt;
	pthread_mutex_t	mutex_of_dead_philo_flag;
	int				dead_philo_flag;
	pthread_mutex_t	mutex_of_start_flag;
	int				start_thread_cnt;
}	t_info;

typedef struct s_philo
{
	pthread_t		thread_id;
	int				id;
	pthread_mutex_t	mutex_of_eat;
	int				eat_cnt;
	long long		last_eat_time;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	t_info			*info;
}	t_philo;

/* main.c */
int			check_philo_is_alive(t_philo *philos, t_info *info);
void		monitoring_thread(t_philo *philos, t_info *info);
void		init_thread(t_philo *philos, t_info *info);
void		join_thread(t_info *info, t_philo *philos, pthread_mutex_t *forks);

/* philo_thread.c */
int			print_int_mutex(t_philo *philo, char *message);
int			pick_up_fork(t_philo *philo);
int			eat_or_die(t_philo *philo);
void		put_down_fork(t_philo *philo);
void		*thread_func_philo(void *philos);

/* utils.c */
int			ft_atoi(char *str);
void		destroy_all_mutex(t_info *info, t_philo *philos,
				pthread_mutex_t *forks);
void		free_all(t_info *info, t_philo *philos, pthread_mutex_t *forks);

/* etc_message.c */
void		msleep(long long target_time);
int			guarded_malloc(void **addr, int size);
int			print_error(char *message);
long long	get_millisec(void);

/* init.c */
int			init_mutex_in_info(t_info **info);
int			init_info(int argc, char **argv, t_info **info);
int			init_philos(t_philo **philos, t_info *info, pthread_mutex_t *forks);
int			init_forks(pthread_mutex_t **forks, int num_of_philos);

#endif
