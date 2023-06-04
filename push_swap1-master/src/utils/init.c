/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 04:48:16 by ohamadou          #+#    #+#             */
/*   Updated: 2023/06/04 12:03:22 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

//fill stacck a with the provided values
t_stack	*stack_values(int ac, char **av)
{
	t_stack		*stack_a;
	long int	nb;
	int			i;
	int			is_stack_created;

	stack_a = NULL;
	nb = 0;
	i = 1;
	is_stack_created = 0;
	while (i < ac)
	{
		char **str = ft_split(av[i], ' ');
		if (str == NULL)
			exit_error(&stack_a, NULL);
		while (*str)
		{
			if (!ft_isdigit(**str) && **str != '-' && **str != '+')
				exit_error(&stack_a, NULL);
			nb = ft_atoi(*str);
			if (nb > INT_MAX || nb < INT_MIN)
				exit_error(&stack_a, NULL);
			if (is_stack_created == 0)
			{
				stack_a = create_new_stack((int)nb);
				is_stack_created = 1;
			}
			else
				add_element_bottom(&stack_a, create_new_stack((int)nb));
			str++;
		}
		// nb = ft_atoi(av[i]);
		// if (nb > INT_MAX || nb < INT_MIN)
		// 	exit_error(&stack_a, NULL);
		// if (i == 1)
		// 	stack_a = create_new_stack((int)nb);
		// else
		// 	add_element_bottom(&stack_a, create_new_stack((int)nb));
		i++;
	}
	return (stack_a);
}

//assign an index go each value in the stack a.
void	indexation(t_stack *stack_a, int size)
{
	t_stack	*hgh;
	t_stack	*ptr;
	int		data;

	while (--size > 0)
	{
		ptr = stack_a;
		data = INT_MIN;
		hgh = NULL;
		while (ptr)
		{
			if (ptr -> data == INT_MIN && ptr -> index == 0)
				ptr -> index = 1;
			if (ptr -> data > data && ptr -> index == 0)
			{
				data = ptr -> data;
				hgh = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr -> next;
		}
		if (hgh != NULL)
			hgh -> index = size;
	}
}
