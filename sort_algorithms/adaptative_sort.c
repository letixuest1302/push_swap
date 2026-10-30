/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptative_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia & lesainz <acornia@student.42ma    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:39:15 by acornia           #+#    #+#             */
/*   Updated: 2026/10/30 12:30:40 by acornia & l      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strcmp(const char *flag, const char *str);

static	void	adaptative(t_node **stack_a, t_node **stack_b)
{
	float	disorder;

	disorder = disorder_index(*stack_a);
	if (disorder < 0.2f)
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
	if (flag && ft_strcmp(flag, "--simple") == 0)
		simple_sort(stack_a, stack_b);
	else if (flag && ft_strcmp(flag, "--medium") == 0)
		medium_sort(stack_a, stack_b);
	else if (flag && ft_strcmp(flag, "--complex") == 0)
		complex_sort(stack_a, stack_b);
	else if (flag && ft_strcmp(flag, "--adaptative") == 0)
		adaptative(stack_a, stack_b);
	else
		adaptative(stack_a, stack_b);
}

int	ft_strcmp(const char *flag, const char *str)
{
	int	i;

	i = 0;
	while (flag[i] == str[i] && flag[i] != '\0')
		i++;
	return (flag[i] - str[i]);
}
