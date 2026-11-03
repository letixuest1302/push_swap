/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia & lesainz <acornia@student.42ma    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 12:58:05 by acornia           #+#    #+#             */
/*   Updated: 2026/11/03 10:34:20 by acornia & l      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

static void	push_back(t_node **stack_a, t_node **stack_b)
{
	int	max_pos;
	int	size;

	while (*stack_b)
	{
		max_pos = index_max_pos(*stack_b);
		size = stack_size(*stack_b);
		if (max_pos <= size / 2)
		{
			while (max_pos > 0)
			{
				rb(stack_b);
				max_pos--;
			}
		}
		else
		{
			while (max_pos < size)
			{
				rrb(stack_b);
				max_pos++;
			}
		}
		pa(stack_a, stack_b);
	}
}

void	medium_sort(t_node **stack_a, t_node **stack_b)
{
	int	size;
	int	chunk_size;

	size = stack_size(*stack_a);
	if (size <= 100)
		chunk_size = 15;
	else
		chunk_size = 30;
	push_chunks(stack_a, stack_b, chunk_size);
	push_back(stack_a, stack_b);
}