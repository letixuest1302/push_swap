/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia & lesainz <acornia@student.42ma    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 12:30:52 by acornia & l       #+#    #+#             */
/*   Updated: 2026/10/30 12:31:03 by acornia & l      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	first = *stack;
	*stack = (*stack)->next;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->next = NULL;
	return (1);
}

void	ra(t_node **stack_a)
{
	if (rotate(stack_a))
		write(1, "ra\n", 3);
}

void	rb(t_node **stack_b)
{
	if (rotate(stack_b))
		write(1, "rb\n", 3);
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	int	done_a;
	int	done_b;

	done_a = rotate(stack_a);
	done_b = rotate(stack_b);
	if (done_a && done_b)
		write(1, "rr\n", 3);
	else if (done_a)
		write(1, "ra\n", 3);
	else if (done_b)
		write(1, "rb\n", 3);
}
