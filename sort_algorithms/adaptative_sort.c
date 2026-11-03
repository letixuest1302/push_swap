/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptative_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia & lesainz <acornia@student.42ma    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:39:15 by acornia           #+#    #+#             */
/*   Updated: 2026/11/03 15:23:15 by acornia & l      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	set_bench_info(t_bench *bench, char *strategy, char *complexity)
{
	if (!bench)
		return ;
	bench->strategy = strategy;
	bench->complexity = complexity;
}

static	void	run_adaptative(t_node **stack_a, t_node **stack_b)
{
	float	disorder;

	disorder = disorder_index(*stack_a);
	if (disorder < 0.2f)
	{
		set_bench_info(bench, "Adaptative", "O(n)");
		simple_sort(stack_a, stack_b);
	}
	else if (disorder < 0.5f)
	{
		set_bench_info(bench, "Adaptative", "O(n√n)");
		medium_sort(stack_a, stack_b);
	}
	else
	{
		set_bench_info(bench, "Adaptative", "O(n log n)")
		complex_sort(stack_a, stack_b);
	}
}

void	select_algorithm(t_node **stack_a, t_node **stack_b, char *flag, t_bench *bench)
{
	float	disorder;

	disorder = disrder_index(*stack_a);
	if (bench)
		bench->disorder = disorder;
	if (flag && ft_strcmp(flag, "--simple") == 0)
	{
		set_bench_info(bench, "Simple", "O(n)");
		simple_sort(stack_a, stack_b);
	}
	else if (flag && ft_strcmp(flag, "--medium") == 0)
	{
		set_bench_info(bench, "Medium", "O(n√n)");
		medium_sort(stack_a, stack_b);
	}
	else if (flag && ft_strcmp(flag, "--complex") == 0)
	{
		set_bench_info(bench, "Complex", "O(n log n)")
		complex_sort(stack_a, stack_b);
	}
	else
		run_adaptative(stack_a, stack_b);
}

void	adaptative_sort(t_node **stack_a, t_node **stack_b, char *flag, t_bench *bench)
{
	if (!stack_a || !*stack_a)
		return ;
	select_algorithm(stack_a, stack_b, flag, bench);
	if (bench && bench->enabled)
		print_bench;
}

int	ft_strcmp(const char *flag, const char *str)
{
	int	i;

	i = 0;
	while (flag[i] == str[i] && flag[i] != '\0')
		i++;
	return (flag[i] - str[i]);
}
