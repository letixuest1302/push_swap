/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptative_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:39:15 by acornia           #+#    #+#             */
/*   Updated: 2026/10/28 15:53:55 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	adaptativ(t_node **stack_a, t_node **stack_b)
{
	float	disorder;

	disorder = disorder_index(*stack_a);
	if (disoder < 0.2f)
		simple_sort(stack_a, stack_b);
	else if (disorder < 0.5f)
		medium_sort(stack_a, stack_b);
	else
		complex_sort(stack_a, stack_b);
}

void	sort_stack(t_node **stack_a, t_node **stack_b, char *flag)
{
	if (!stack_a || !*stack_a)
		return ;
	if (flag == "--simple")
		simple_sort(stack_a, stack_b);
	else if (flag == "--medium")
		medium_sort(stack_a, stack_b);
	else if (flag == "--complex")
		complex_sort(stack_a, stack_b);
	else if (flag == "adaptative")
		adaptative(stack_a, stack_b);
}