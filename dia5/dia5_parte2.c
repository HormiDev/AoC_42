/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dia5_parte2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:21:48 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/12/06 00:11:08 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../42_Libft/libft.h"

void	check_and_repair(int *update, int rule1, int rule2)
{
	int		i;
	int 	n1;
	int 	n2;
	int		tmp;

	i = 0;
	n1 = -1;
	n2 = -1;
	while (update[i] != -1)
	{
		if (update[i] == rule1)
			n1 = i;
		if (update[i] == rule2)
			n2 = i;
		i++;
	}
	if (n1 < 0 || n2 < 0)
		return ;
	if (n2 < n1)
	{
		tmp = update[n1];
		update[n1] = update[n2];
		update[n2] = tmp;
	}
}

int	repair_update(int *update, t_list *lst_rules)
{
	int		result;
	int		i;

	while (lst_rules)
	{
		check_and_repair(update, ((int *)lst_rules->content)[0], ((int *)lst_rules->content)[1]);
		lst_rules = lst_rules->next;
	}
	i = 0;
	while (update[i] != -1)
		i++;
	i--;
	i = i/2;
	result = update[i];
	return (result);
}

int	check_rule(int *update, int rule1, int rule2)
{
	int		i;
	int 	n1;
	int 	n2;

	i = 0;
	n1 = -1;
	n2 = -1;
	while (update[i] != -1)
	{
		if (update[i] == rule1)
			n1 = i;
		if (update[i] == rule2)
			n2 = i;
		i++;
	}
	if (n1 < 0 || n2 < 0)
		return (1);
	if (n2 < n1)
		return (0);
	return (1);
}

int	check_update(int *update, t_list *lst_rules)
{
	while (lst_rules)
	{
		if (!check_rule(update, ((int *)lst_rules->content)[0], ((int *)lst_rules->content)[1]))
			return (0);
		lst_rules = lst_rules->next;
	}
	return (1);
}

void	create_rules_list(t_file *file, t_list **lst_rules)
{
	int			*content;
	char		**split;
	int			i;

	i = 0;
	*lst_rules = NULL;
	while (file->array_content[i][0] != '\n')
	{
		split = ft_split(file->array_content[i], '|');
		content = malloc(sizeof(int) * 2);
		content[0] = ft_atoi(split[0]);
		content[1] = ft_atoi(split[1]);
		ft_lstadd_back(lst_rules, ft_lstnew(content));
		i++;
		ft_free_split(split);
	}
	ft_printf("hola\n");
	t_list *tmp = *lst_rules;
	ft_printf("hola\n");
	while (tmp != NULL)
	{
		ft_printf("rule: %d,%d\n", ((int *)tmp->content)[0], ((int *)tmp->content)[1]);
		tmp = tmp->next;
	}
}

void	create_update_list(t_file *file, t_list **lst_update)
{
	int			*content;
	char		**split;
	int			i;
	int			j;
	int 		split_len;

	i = 0;
	*lst_update = NULL;
	while (file->array_content[i][0] != '\n')
		i++;
	i++;
	while (file->array_content[i] != NULL)
	{
		split = ft_split(file->array_content[i], ',');
		split_len = ft_splitlen(split);
		content = malloc(sizeof(int) * split_len + 1);
		content[split_len] = -1;
		j = 0;
		while (j < split_len)
		{
			content[j] = ft_atoi(split[j]);
			j++;
		}
		ft_lstadd_back(lst_update, ft_lstnew(content));
		i++;
		ft_free_split(split);
	}
	t_list *tmp = *lst_update;
	while (tmp != NULL)
	{
		j = 0;
		while (((int *)tmp->content)[j] != -1)
		{
			ft_printf("[%d]", ((int *)tmp->content)[j]);
			j++;
		}
		ft_printf("\n");
		tmp = tmp->next;
	}
}

void	print_update(t_list *lst_update)
{
	int		i;

	i = 0;
	while (((int *)lst_update->content)[i] != -1)
	{
		ft_printf("[%d]", ((int *)lst_update->content)[i]);
		i++;
	}
	ft_printf("\n");
}

int main(int argc, char **argv)
{
	t_file	*file;
	t_list	*lst_rules;
	t_list	*lst_update;
	int		result;
	
	result = 0;
	if (argc != 2)
	{
		ft_printf("Usage: %s file_name\n", argv[0]);
		return (0);
	}
	file = ft_create_file_from_filename(argv[1]);
	ft_file_print(file);
	ft_printf("\n");
	create_rules_list(file, &lst_rules);
	create_update_list(file, &lst_update);
	while (lst_update != NULL)
	{
		if (!check_update(lst_update->content, lst_rules))
		{
			print_update(lst_update);
			while (!check_update(lst_update->content, lst_rules))
				repair_update(lst_update->content, lst_rules);
			result = result + repair_update(lst_update->content, lst_rules);
			print_update(lst_update);
		}
		ft_printf("result: %d\n", result);
		lst_update = lst_update->next;
	}
	ft_file_clear(&file);
	return (0);
}