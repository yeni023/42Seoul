/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:58:55 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/09/21 16:58:57 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(char *msg)
{
	printf("Error\n%s", msg);
	exit(1);
}

int	print_error_ver2(char *message)
{
	ft_putstr_fd("Error\n", 2);
	perror(message);
	exit(1);
	return (0);
}
