/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:33:37 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/12/20 16:37:48 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int			sign;
	long long	result;
	int			base;

	base = 0;
	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str++ - '0';
		base++;
	}
	result *= sign;
	if (result > 2147483647 || result < -2147483648
		|| base == 0 || base > 11 || *str)
		return (-1);
	return (result);
}

void	destroy_all_mutex(t_info *info, t_philo *philos, pthread_mutex_t *forks)
{
	int	i;
	int	num_of_philos;

	if (info)
	{
		num_of_philos = info->num_of_philos;
		pthread_mutex_destroy(&(info->mutex_of_full_philo_cnt));
		pthread_mutex_destroy(&(info->mutex_of_dead_philo_flag));
		pthread_mutex_destroy(&(info->mutex_of_start_flag));
	}
	i = -1;
	if (philos)
		while (++i < num_of_philos)
			pthread_mutex_destroy(&(philos[i].mutex_of_eat));
	i = -1;
	if (forks)
		while (++i < num_of_philos)
			pthread_mutex_destroy(&forks[i]);
}

void	free_all(t_info *info, t_philo *philos, pthread_mutex_t *forks)
{
	destroy_all_mutex(info, philos, forks);
	if (info)
		free(info);
	if (philos)
		free (philos);
	if (forks)
		free(forks);
}
