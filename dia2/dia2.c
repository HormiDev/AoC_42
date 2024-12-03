/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dia2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:02:55 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/12/03 00:39:55 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../42_Libft/libft.h"

int check_line_asdent(int *num_array)
{
	int i;

	i = 0;
	while (num_array[i] != -1 && num_array[i + 1] != -1)
	{
		if (num_array[i + 1] - num_array[i] > 3 || num_array[i + 1] - num_array[i] < 1)
			return (0);
		i++;
	}
	free(num_array);
	return (1);
}

int check_line_desdent(int *num_array)
{
	int i;

	i = 0;
	while (num_array[i] != -1 && num_array[i + 1] != -1)
	{
		if (num_array[i] - num_array[i + 1] > 3 || num_array[i] - num_array[i + 1] < 1)
			return (0);
		i++;
	}
	free(num_array);
	return (1);
}

int check_line(char *line)
{
	int		*num_array;
	int		i;
	char	**split;

	split = ft_split(line, ' ');
	if (!split)
		return (0);
	num_array = (int *)malloc(sizeof(int) * ft_splitlen(split) + 1);
	if (!num_array)
	{
		ft_free_split(split);
		return (0);
	}
	i = 0;
	while (split[i])
	{
		num_array[i] = ft_atoi(split[i]);
		ft_printf("[%d]", num_array[i]);
		i++;
	}
	num_array[i] = -1;
	ft_free_split(split);
	if (num_array[0] < num_array[1])
		return (check_line_asdent(num_array));
	else if (num_array[0] > num_array[1])
		return (check_line_desdent(num_array));
	free(num_array);
	return (0);
}

int main(int argc, char **argv)
{
	t_file	*file;
	int 	line;
	int		result;
	int 	tmpresult;

	if (argc != 2)
	{
		ft_putstr_fd("Error: use <./dia2> <numeros.txt>\n", 2);
		return (1);
	}
	file = ft_create_file_from_filename(argv[1]);
	if (!file)
	{
		ft_putstr_fd("Error: file not found\n", 2);
		return (1);
	}
	line = 0;
	result = 0;
	tmpresult = 0;
	while (line < file->lines)
	{
		ft_printf("checking line %d\n", line);
		if (check_line(file->array_content[line]))
			result++;
		if (tmpresult < result)
		{
			ft_printf("Result: %d\n", result);
			tmpresult = result;
		}
		else
			ft_printf("\n");
		line++;
	}
	ft_file_clear(&file);
	ft_printf("Result: %d\n", result);
	return (0);
}