/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia & lesainz <acornia@student.42ma    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 12:29:01 by acornia           #+#    #+#             */
/*   Updated: 2026/11/03 15:32:54 by acornia & l      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "split/split.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct	s_bench
{
	int		enabled;
	float	disorder;
	char	*strategy;
	char	*complexity;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		total_ops;
}	t_bench;

/*Operaciones Swap*/
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
/*Operaciones Push*/
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
/*Operaciones Rotate*/
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
/*Operaciones Reverse Rotate*/
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);
/*Gestion de errores*/
int		error(t_node *stack_a, char **split);
void	free_stack(t_node *stack);
void	free_split(char	**split);
/*Indice de desordenacion*/
float	disorder_index(t_node *stack);
int		is_sorted(t_node *stack);
/*Parseo*/
void	assign_index(t_node *stack_a);
int		parse_args(int argc, char **argv, int start, t_node **stack);
/*Comprobacion de argumentos*/
int		numbers(char *str);
long	ft_atol(const char *str);
int		duplicate(t_node *stack, int n);
int		add_back(t_node **stack, int n);
/*Algoritmos de ordenacion*/
void	adaptative_sort(t_node **stack_a, t_node **stack_b, char *flag);
void	simple_sort(t_node **stack_a, t_node **stack_b);
void	medium_sort(t_node **stack_a, t_node **stack_b);
void	complex_sort(t_node **stack_a, t_node **stack_b);
/*Herramientas para los algoritmos*/
int		index_max_pos(t_node *stack);
int		index_min_pos(t_node *stack);
int		stack_size(t_node *stack);
void	sort_three(t_node **stack_a);
int		ft_strcmp(const char *flag, const char *str);
/*Herramientas para el bench*/
void	ft_putstr(char *str, int fd);
void	ft_putnbr_fd(int n, int fd);
void	print_bench(t_bench *bench);
/*Herramientas del main*/
int	handle_args(int argc, char **argv, t_node **stack, char **flag, t_bench *bench);


#endif