/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dia13_parte2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 01:04:09 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/12/14 01:09:29 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../42_Libft/libft.h"
# include <stdio.h>

typedef struct s_claw_machine
{
	long			button_a[2];
	long			button_b[2];
	long			prize[2];
	t_list_dbl	*a_moves;
	t_list_dbl	*b_moves;
} t_claw_machine;

t_list	*parsing(t_file *file)
{
	t_list			*machines;
	t_claw_machine	*machine;
	long				i;
	char			**split1;
	char			**split2;

	machines = NULL;
	i = 0;
	while (file->array_content[i] != NULL)
	{
		machine = malloc(sizeof(t_claw_machine));
		machine->a_moves = NULL;
		machine->b_moves = NULL;
		split1 = ft_split(file->array_content[i], ' ');
		split2 = ft_split(split1[2], '+');
		machine->button_a[0] = ft_atol(split2[1]);
		ft_free_split(split2);
		split2 = ft_split(split1[3], '+');
		machine->button_a[1] = ft_atol(split2[1]);
		ft_free_split(split2);
		ft_free_split(split1);
		i++;
		split1 = ft_split(file->array_content[i], ' ');
		split2 = ft_split(split1[2], '+');
		machine->button_b[0] = ft_atol(split2[1]);
		ft_free_split(split2);
		split2 = ft_split(split1[3], '+');
		machine->button_b[1] = ft_atol(split2[1]);
		ft_free_split(split2);
		ft_free_split(split1);
		i++;
		split1 = ft_split(file->array_content[i], ' ');
		split2 = ft_split(split1[1], '=');
		machine->prize[0] = ft_atol(split2[1]) + 10000000000000;
		ft_free_split(split2);
		split2 = ft_split(split1[2], '=');
		machine->prize[1] = ft_atol(split2[1]) + 10000000000000;
		ft_free_split(split2);
		ft_free_split(split1);
		ft_lstadd_back(&machines, ft_lstnew(machine));
		i += 2;
	}
	return (machines);
}

long cmp_vector(long *a, long *b)
{
	if (a[0] == b[0] && a[1] == b[1])
		return (1);
	return (0);
}

void clear_machine(void *clear)
{
	t_claw_machine *machine;

	machine = (t_claw_machine *)clear;
	ft_list_dbl_clear(&machine->a_moves, free);
	ft_list_dbl_clear(&machine->b_moves, free);
	free(machine);
}
long	check_machine(t_claw_machine *machine)
{
	long *a_move;
	long *b_move;
	t_list_dbl *tmpa;
	t_list_dbl *tmpb;
	long result;

	a_move = malloc(sizeof(long) * 2);
	a_move[0] = machine->button_a[0];
	a_move[1] = machine->button_a[1];
	ft_list_dbl_addnew_back(&machine->a_moves, a_move);
	while (((long *)(ft_list_dbl_get_last(machine->a_moves)->content))[0] < machine->prize[0] && ((long *)(ft_list_dbl_get_last(machine->a_moves)->content))[1] < machine->prize[1])
	{
		a_move = malloc(sizeof(long) * 2);
		a_move[0] = ((long *)(ft_list_dbl_get_last(machine->a_moves)->content))[0] + machine->button_a[0];
		a_move[1] = ((long *)(ft_list_dbl_get_last(machine->a_moves)->content))[1] + machine->button_a[1];
		ft_list_dbl_addnew_back(&machine->a_moves, a_move);
	}
	b_move = malloc(sizeof(long) * 2);
	b_move[0] = machine->prize[0] - machine->button_b[0];
	b_move[1] = machine->prize[1] - machine->button_b[1];
	ft_list_dbl_addnew_back(&machine->b_moves, b_move);
	while (((long *)(ft_list_dbl_get_last(machine->b_moves)->content))[0] > 0 && ((long *)(ft_list_dbl_get_last(machine->b_moves)->content))[1] > 0)
	{
		b_move = malloc(sizeof(long) * 2);
		b_move[0] = ((long *)(ft_list_dbl_get_last(machine->b_moves)->content))[0] - machine->button_b[0];
		b_move[1] = ((long *)(ft_list_dbl_get_last(machine->b_moves)->content))[1] - machine->button_b[1];
		ft_list_dbl_addnew_back(&machine->b_moves, b_move);
	}

	tmpa = machine->a_moves;
	while (tmpa)
	{
		tmpb = machine->b_moves;
		while (tmpb)
		{
			if (cmp_vector((long *)tmpa->content, (long *)tmpb->content))
			{
				result = 3 * ft_list_dbl_get_position_node(tmpa) + ft_list_dbl_get_position_node(tmpb);
				printf("3*A:%d + B:%d = %ld\n", (3 * ft_list_dbl_get_position_node(tmpa)), ft_list_dbl_get_position_node(tmpb), result);
				return (result);
			}
			tmpb = tmpb->next;
		}
		tmpa = tmpa->next;
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_file	*file;
	t_list	*machines;
	t_list	*tmp;
	long		result;

	if (argc != 2)
	{
		printf("usage: %s <file>\n", argv[0]);
		return (1);
	}
	result = 0;
	file = ft_create_file_from_filename(argv[1]);
	ft_file_print(file);
	printf("\n\n");
	machines = parsing(file);
	tmp = machines;
	while (tmp)
	{
		result += check_machine((t_claw_machine *)tmp->content);
		tmp = tmp->next;
	}
	printf("Total result: %ld\n", result);
	ft_lstclear(&machines, clear_machine);
	ft_file_clear(&file);
}