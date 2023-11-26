/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:07:18 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/11/20 11:12:57 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_node
{
	int				val;
	struct s_node	*left;
	struct s_node	*right;
}	t_node;

typedef struct s_stack
{
	struct s_node	*top;
	struct s_node	*bottom;
}	t_stack;

typedef struct s_var
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
	long			*list;
	int				list_size;
	int				a_size;
	int				b_size;
}	t_var;

/* args.c */
char	*join_argv(int ac, char **av);
void	check_overlap(t_var *stack, int check);
void	check_validate_args(int ac, char **av, t_var *var);

/* check_sort.c */
void	checker(t_var *stacks);
int		is_sort(t_var *stack);

/* checker_utils.c */
void	command_check(char *in, t_var *stacks);
void	input(t_var *stacks);

/* main.c */
void	ft_error(void);
int		main(int ac, char **av);

/* operationp.c */
void	pa(t_var *stacks);
void	pb(t_var *stacks);

/* operations.r */
void	ra(t_var *stacks);
void	rb(t_var *stacks);
void	rr(t_var *stacks);

/* operations.rr */
void	rra(t_var *stacks);
void	rrb(t_var *stacks);
void	rrr(t_var *stacks);

/* operations.c */
void	sa(t_var *stacks);
void	sb(t_var *stacks);
void	ss(t_var *stacks);

/* stack_pop.c */
t_node	*pop_top(t_stack *stack);
t_node	*pop_bottom(t_stack *stack);

/* push_stack.c */
void	push_top(t_stack *stack, t_node *new_node);
void	push_bottom(t_stack *stack, t_node *new_node);

/* stack.c */
void	init_stack(t_var *var);
t_node	*add_new_node(int n);
void	stacking(t_var *stack);

/* utils_split.c */
void	ft_free(char **arr, int i);
char	**ft_split(char const *s, char c);

/* utils.c */
int		ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
int		is_number(char *str);
long	ft_atoi(const char *str);
int		ft_strcmp(char *s1, char *s2);

/* gnl */
size_t	gnl_strlen(const char *s);
char	*gnl_strchr(const char *s, int c);
char	*gnl_strdup(const char *s1);
char	*gnl_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
char	*gnl_substr(char const *s, unsigned int start, size_t len);

#endif