#include "../includes/push_swap.h"

int	exec(char *input, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strcmp(input, "sa\n")  == 0)
		swap_a(&stack_a);
	else if (ft_strcmp(input, "sb\n") == 0)
		swap_b(&stack_a);
	else if (ft_strcmp(input, "ss\n") == 0)
		swap_ss(&stack_a, &stack_b);
	else if (ft_strcmp(input, "pa\n") == 0)
		push_a(&stack_a, &stack_b);
	else if (ft_strcmp(input, "pb\n") == 0)
		push_b(&stack_a, &stack_b);
	else if (ft_strcmp(input, "ra\n") == 0)
		rotate_a(&stack_a);
	else if (ft_strcmp(input, "rb\n") == 0)
		rotate_b(&stack_b);
	else if (ft_strcmp(input, "rra\n") == 0)
		reverse_rotate_a(&stack_a);
	else if (ft_strcmp(input, "rrb\n") == 0)
		reverse_rotate_b(&stack_b);
	else
	{
		free(input);
		return (0);
	}
	free(input);
	return (1);
}

// static int	sort_checked(t_stack *stack)
// {
// 	while (stack -> next != NULL)
// 	{
// 		if (stack -> data > stack -> next -> data)
// 			return (0);
// 		stack = stack -> next;
// 	}
// 	return (1);
// }

static void ft_check_duplicates(t_stack *stack_a)
{
	t_stack *tmp;
	t_stack *tmp2;

	tmp = stack_a;
	while (tmp)
	{
		tmp2 = tmp -> next;
		while (tmp2)
		{
			if (tmp -> data == tmp2 -> data)
			{
				write(2, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
			tmp2 = tmp2 -> next;
		}
		tmp = tmp -> next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	// int		stack_n;

	if (is_parser_error(argc))
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	stack_b = NULL;
	stack_a = stack_values(argc, argv);
	ft_check_duplicates(stack_a);
	// stack_n = stack_size(stack_a);
    input(stack_a, stack_b);
	if (sort_checked(stack_a))
		write(1, "ok\n", 3);
    else if (!sort_checked(stack_a))
    {
        write(1, "ok\n", 3);
    }
	// free_stack(&stack_a);
	// free_stack(&stack_b);
	return (0);
}