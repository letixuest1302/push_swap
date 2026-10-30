/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia & lesainz <acornia@student.42ma    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 12:58:05 by acornia           #+#    #+#             */
/*   Updated: 2026/10/30 14:25:43 by acornia & l      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	medium_sort(t_node **stack_a, t_node **stack_b)
{
	write(1, "Esto es medium\n", 15);
	simple_sort(stack_a, stack_b);
}

static int	index_max_pos(t_node *stack)
{
	int	max_idx;
	int	max_pos;
	int	current_pos;
	
	if (!stack)
		return (0);
	min_pos = 0;
	current_pos = 0;
	max_idx = stack->index;
	while (stack)
	{
		if (stack->index > max_idx)
		{
			max_idx = stack->index;
			max_pos = current_pos;
		}
		stack = stack->next;
		current_pos++;
	}
	return (max_pos);
}

static void push_chunks(t_node **stack_a, t_node **stack_b, int chunk)
{
	int	pushed;

	pushed = 0;
	while (*stack_a)
	{
		if ((*stack_a)->index <= pushed)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			pushed++;
		}
		else if ((*stack_a)->index <= (pushed + chunk))
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
			ra(stack_a);
	}
}