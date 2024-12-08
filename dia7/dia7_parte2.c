/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dia7_parte2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 03:09:23 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/12/08 05:23:39 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../42_Libft/libft.h"
# include <stdio.h>

void	ft_print_operators(int *operators, int len);

int check_cat(long result, int *factors, int len, int *operators)
{
	int		cat;
	int 	i;
	long	tmp;
	char	*str1;
	char	*str2;
	char	*strcat;

	cat = 0;
	while (cat < len - 1)
	{
		i = 0;
		tmp = factors[0];
		while (i < len - 1)
		{
			if (i == cat)
			{
				str1 = ft_ltoa(tmp);
				str2 = ft_ltoa(factors[i + 1]);
				strcat = ft_strjoin(str1, str2);
				tmp = ft_atol(strcat);
				free(str1);
				free(str2);
				free(strcat);
			}
			else
			{
				if (operators[i] == 0)
					tmp += factors[i + 1];
				else if (operators[i] == 1)
					tmp *= factors[i + 1];
			}
			i++;
		}
		if (tmp == result)
		{
			ft_print_operators(operators, len - 1);
			printf("Result: %ld ", result);
			printf("tmp: %ld\n", tmp);
			i = 0;
			while (i < len)
			{
				printf(" %d", factors[i]);
				i++;
			}
			printf("\nCat: %d\n", cat);
			return (1);
		}
		cat++;
	}
	return (0);
}

void	iter_operators(int *operators, int len)
{
	int i;

	i = len - 1;
	while (i >= 0)
	{
		if (operators[i] >= 1)
		{
			operators[i] = 0;
			i--;
		}
		else
		{
			operators[i]++;
			return ;
		}
	}
}

int check_operators(int *operators, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (operators[i] < 1)
			return (0);
		i++;
	}
	return (1);
}

void	ft_print_operators(int *operators, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (operators[i] == 0)
			ft_printf(" + ");
		else if (operators[i] == 1)
			ft_printf(" * ");
		else if (operators[i] == 2)
			ft_printf(" # ");
		i++;
	}
	ft_printf("\n");
}

int check_factors(int *factors, int len, long result)
{
	long	tmp;
	int		*operators;
	int 	i;

	operators = malloc(sizeof(int) * (len - 1));
	i = 0;
	while (i < len - 1)
	{
		operators[i] = 0;
		i++;
	}
	while (0 == 0)
	{
		//ft_print_operators(operators, len);
		i = 1;
		tmp = factors[0];
		while (i < len)
		{
			if (operators[i - 1] == 0)
				tmp += factors[i];
			else if (operators[i - 1] == 1)
				tmp *= factors[i];
			i++;
		}
		if (tmp == result)
		{
			free(operators);
			//ft_printf("Result: %d\n", result);
			return (1);
		}
		else
		{
			if (check_cat(result, factors, len, operators))
			{
				free(operators);
				return (1);
			}
		}
		if (check_operators(operators, len - 1))
			break ;
		iter_operators(operators, len - 1);
	}
	free(operators);
	return (0);
}

long	checkline(char *line)
{
	long		result;
	int			*factors;
	char		**split1;
	char		**split2;
	int			split2_len;
	int			i;

	split1 = ft_split_p(line, ':');
	split2 = ft_split_p(split1[1], ' ');
	result = ft_atol(split1[0]);
	split2_len = ft_splitlen(split2);
	i = 0;
	factors = malloc(sizeof(int) * split2_len);
	while (i < split2_len)
	{
		factors[i] = ft_atoi(split2[i]);
		i++;
	}
	if (check_factors(factors, split2_len, result))
	{
		free(factors);
		ft_free_split(split1);
		ft_free_split(split2);
		return (result);
	}
	free(factors);
	ft_free_split(split1);
	ft_free_split(split2);
	return (0);
}

int main(int argc, char **argv)
{
	t_file		*file;
	t_strlist	*list;
	long		result;

	if (argc != 2)
	{
		ft_printf("Error: use ./dia7 <infile.txt>\n");
		return (1);
	}
	file = ft_create_file_from_filename(argv[1]);
	//ft_file_print(file);
	//ft_printf("\n\n");
	list = file->list_content;
	result = 0;
	while (list)
	{
		result += checkline(list->str);
		//ft_printf("\n");
		list = list->next;
	}
	printf("Result: %ld\n", result);
	ft_file_clear(&file);
	return (0);
}