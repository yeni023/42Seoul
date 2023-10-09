/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:36:33 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/10/09 14:57:58 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include "../src/libft/libft.h"

// client.c
void	check_handler(int signal);
void	print_pid(pid_t pid);
// server.c
void	send_error_message(void);
void	send_bit(pid_t pid, char input);
void	send_string(pid_t pid, char *input);

#endif