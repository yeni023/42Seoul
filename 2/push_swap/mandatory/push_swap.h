/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:51:08 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/11/20 16:06:08 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

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

/* sort_check.c */
char	**multifree(char **res);
void	sorted_check(int *arr, int arrlen);

/* args_check.c */
int		*make_arr(char **split, t_var *data);
void	repeat_check(int n, char **split, int i);
void	split_check_init_arr(char **split, int *arr);
void	check_vacant_str(char *s);
int		*push_arg_check(int ac, char **av, t_var *data);

/* check_sort.c */
void	is_sort(t_var *stack);
int		find_max(t_var *stack);
void	indexing(t_var *stack);

/* find.c */
int		find_a_max(t_var *stacks);
int		find_a_mid(int n, t_var *stacks);
int		find_a_min(t_var *stacks);
int		find_a(int n, t_var *stack);

/* main.c */
void	ft_error(void);
int		main(int ac, char **av);

/* move_pa_pb.c */
void	pa(t_var *stacks);
void	pb(t_var *stacks);

/* move_ra_rb_rr.c */
void	ra(t_var *stacks);
void	rb(t_var *stacks);
void	rr(t_var *stacks);

/* move_rra_rrb_rrr.c */
void	rra(t_var *stacks);
void	rrb(t_var *stacks);
void	rrr(t_var *stacks);

/* move_sa_sb_ss.c */
void	sa(t_var *stacks);
void	sb(t_var *stacks);
void	ss(t_var *stacks);

/* rotate.c */
void	a_rotate(t_var *stacks, int a);
void	b_rotate(t_var *stacks, int b);
void	same_rotate(t_var *stack, int *a, int *b);
void	min_rotate(t_var *stack, int *a, int *b);

/* sort_utils.c */
void	sort_big_last(t_var *stacks);
void	devide_pivot(t_var *stack);
int		find_bigger(int a, int b, int a_loc, int b_loc);

/* sort.c */
void	swaping(t_var *stack);
void	sort_three(t_var *stack);
void	sort_all(t_var *stack);

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
int		get_stack_min(t_var *stacks);
int		get_stack_max(t_var *stacks);

/* utils_split.c */
void	free_arr(char **arr, int i);
char	**ft_split(char const *s, char c);

/* utils.c */
int		ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
int		is_number(char *str);
long	ft_atoi(const char *str);

#endif