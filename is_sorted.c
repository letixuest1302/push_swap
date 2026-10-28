/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:15:46 by acornia           #+#    #+#             */
/*   Updated: 2026/10/28 15:16:555 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
//para manejar decimales. calcula el indice de ordenacion

float	disorder_index(t_node *stack)
{
	float	total_pairs;
	float	mistakes;
	t_node	*current;
	t_node	*compare;

	if (!stack || !stack->next)
		return (0.0f);
	mistakes = 0.0f;
	total_pairs = 0.0f;
	current = stack;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			total_pairs += 1.0f;
			if (current->value > compare->value)
				mistakes += 1.0f;
			compare = compare->next;
		}
		current = current->next;
	}
	if (total_pairs == 0.0f)
		return (0.0f);
	return (mistakes / total_pairs);
}