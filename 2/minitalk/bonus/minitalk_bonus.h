/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:18:15 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/10/09 14:59:28 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <signal.h>
# include "../src/libft/libft.h"

//client_bonus.c
void	send_error_message(void);
void	check_message(int signal);
void	send_bit(pid_t pid, char input);
void	send_string(pid_t pid, char *input);
//server_bonus.c
void	check_handler(int signal, siginfo_t *info, void *s);
void	print_pid(pid_t pid);

#endif