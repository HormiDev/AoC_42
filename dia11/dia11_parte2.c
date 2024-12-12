/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dia11_parte2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:31:59 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/12/12 17:53:20 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../42_Libft/libft.h"
# include <stdio.h>

int contador;

void	blinking(t_list_dbl *lst)
{
	t_list_dbl	*tmp = lst;
	char	*str;
	
	
	while (tmp != NULL)
	{
		str = (char *)tmp->content;
		if (ft_atol(str) == 0)
		{
			free(str);
			tmp->content = ft_strdup("1");
		}
		else if (ft_strlen_p(str) % 2 == 0)
		{
			ft_list_dbl_add_prev(tmp, ft_list_dbl_new(ft_substr_p(str, 0, ft_strlen_p(str) / 2)));
			tmp->content = ft_substr_p(str, ft_strlen_p(str) / 2, ft_strlen_p(str) / 2);
			free(str);
			str = (char *)tmp->content;
			tmp->content = ft_ltoa(ft_atol(str));
			free(str);
		}
		else
		{
			tmp->content = ft_ltoa(ft_atol(str) * 2024);
			free(str);
		}
		tmp = tmp->next;
	}
}

void print_list(t_list_dbl *lst)
{
	t_list_dbl *tmp = lst;
	int i = 0;
	while (tmp != NULL)
	{
		ft_printf("[%s]", (char *)tmp->content);
		tmp = tmp->next;
		i++;
	}
	ft_printf("\n");
}

long root(t_list_dbl *lst_stones, int i, int max_blinkings, long **pre_calculated)
{
	long	result = 0;
	t_list_dbl *lst_root = NULL;
	t_list_dbl *tmp;
	int 		j;
	int			k;
	int 		pre_num;

	//ft_printf("blinking %d stones: %d\n", i, ft_list_dbl_size(lst_stones));
	//print_list(lst_stones);
	k = 0;
	while (k < 1 && i < max_blinkings)
	{
		
		blinking(lst_stones);
		lst_stones = ft_list_dbl_get_first(lst_stones);
		i++;
		k++;
		//ft_printf("blinking %d stones: %d\n", i, ft_list_dbl_size(lst_stones));
	}
	if (i < max_blinkings)
	{
		tmp = lst_stones;
		while (tmp != NULL)
		{
			j = 0;
			while (tmp != NULL && j < 1)
			{
				ft_list_dbl_addnew_back(&lst_root, ft_strdup_p((char *)tmp->content));
				tmp = tmp->next;
				j++;
			}
			if (ft_strlen_p((char *)lst_root->content) == 1)
			{
				pre_num = ft_atoi((char *)lst_root->content);
				if (pre_calculated[pre_num][i] != 0)
				{
					result += pre_calculated[pre_num][i];
					ft_list_dbl_clear(&lst_root, free);
				}
				else
				{
					pre_calculated[pre_num][i] = root(lst_root, i, max_blinkings, pre_calculated);
					result += pre_calculated[pre_num][i];
				}
			}
			else
				result += root(lst_root, i, max_blinkings, pre_calculated);
			if (i == 25)
				printf("contador: %d result: %ld\n", contador++, result);
			lst_root = NULL;
		}
	}
	else
		result = ft_list_dbl_size(lst_stones);
	//printf("contador: %d result: %ld\n", contador++, result);
	ft_list_dbl_clear(&lst_stones, free);
	return (result);
}

int main(int argc, char **argv)
{
	char		**split;
	t_list_dbl	*lst_stones = NULL;
	int			i;
	int			blinkings;
	long		result;
	long		**pre_calculated;
	
	if (argc != 3)
	{
		ft_printf("usage: %s \"stones\" <blinks>\n", argv[0]);
		return (1);
	}
	split = ft_split(argv[1], ' ');
	blinkings = ft_atoi(argv[2]);

	pre_calculated = (long **)malloc(sizeof(long *) * 10);
	i = 0;
	while (i < 10)
	{
		pre_calculated[i] = ft_calloc(blinkings, sizeof(long));
		i++;
	}

	i = 0;
	while (split[i] != NULL)
	{
		ft_list_dbl_addnew_back(&lst_stones, split[i]);
		i++;
	}

	i = 0;
	result = root(lst_stones, i, blinkings, pre_calculated);
	printf("Final result: %ld\n", result);
	free(split);
	i = 0;
	while (i < 10)
	{
		free(pre_calculated[i]);
		i++;
	}
	free(pre_calculated);
	return (0);
}