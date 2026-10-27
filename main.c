/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:43:36 by acornia           #+#    #+#             */
/*   Updated: 2026/10/27 15:17:07 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (!parse_args(argc, argv, &stack_a));
		return (error(&stack_a, NULL));
	assign_index(stack_a);
	
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
