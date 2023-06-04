#include "../includes/push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}


t_stack	*stack_values_check(int ac, char **av)
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
		i++;
	}
	return (stack_a);
}

void	input(t_stack *stack_a, t_stack *stack_b)
{
	char	*input;

	input = get_next_line(0);
	while (input)
	{
		if (!exec(input, stack_a, stack_b))
		{
			write(2, "Error\n", 7);
			exit(-1);
		}
		input = get_next_line(0);
	}
}
