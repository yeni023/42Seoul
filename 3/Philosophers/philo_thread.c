/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:33:27 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/12/20 16:33:28 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_in_mutex(t_philo *philo, char *message)
{
	pthread_mutex_lock(&philo->info->mutex_of_dead_philo_flag);
	if (philo->info->dead_philo_flag == 0)
		printf("%lld %d %s\n", get_millisec() - philo->info->start_time,
			philo->id + 1, message);
	else
	{
		pthread_mutex_unlock(&philo->info->mutex_of_dead_philo_flag);
		return (KO);
	}
	pthread_mutex_unlock(&philo->info->mutex_of_dead_philo_flag);
	return (OK);
}

int	pick_up_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left);
	if (print_in_mutex(philo, "has taken a fork") == KO)
		return (KO);
	pthread_mutex_lock(philo->right);
	if (print_in_mutex(philo, "has taken a fork") == KO)
		return (KO);
	return (OK);
}

void	put_down_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->right);
	pthread_mutex_unlock(philo->left);
}

int	eat_or_die(t_philo *philo)
{
	if (pick_up_fork(philo) == KO)
		return (KO);
	pthread_mutex_lock(&(philo->mutex_of_eat));
	philo->last_eat_time = get_millisec();
	philo->eat_cnt++;
	if (print_in_mutex(philo, "is eating") == KO)
		return (KO);
	if (philo->eat_cnt == philo->info->must_eat_count)
	{
		pthread_mutex_lock(&(philo->info->mutex_of_full_philo_cnt));
		philo->info->full_philo_cnt++;
		pthread_mutex_unlock(&(philo->info->mutex_of_full_philo_cnt));
	}
	pthread_mutex_unlock(&(philo->mutex_of_eat));
	msleep(philo->info->time_to_eat);
	put_down_fork(philo);
	return (OK);
}

void	*thread_func_philo(void *philos)
{
	t_philo	*philo;

	philo = (t_philo *)philos;
	pthread_mutex_lock(&(philo->info->mutex_of_start_flag));
	philo->last_eat_time = philo->info->start_time;
	philo->info->start_thread_cnt += 1;
	pthread_mutex_unlock(&(philo->info->mutex_of_start_flag));
	if (philo->id % 2 == 1)
		usleep(1000);
	while (42)
	{
		if (eat_or_die(philo) == KO)
			break ;
		if (print_in_mutex(philo, "is sleeping") == KO)
			break ;
		msleep(philo->info->time_to_sleep);
		if (print_in_mutex(philo, "is thinking") == KO)
			break ;
	}
	return (NULL);
}
