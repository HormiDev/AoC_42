/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dia10_parte2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:12:05 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/12/10 21:12:30 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../42_Libft/libft.h"

int	check_routes(t_file *file, int i, int j)
{
	int		result;
	int		num;

	result = 0;
	num = file->array_content[i][j];
	if (num == '9')
	{
		return (1);
	}
	if (i > 0 && file->array_content[i - 1][j] == num + 1)
		result += check_routes(file, i - 1, j);
	if (i < file->lines - 1 && file->array_content[i + 1][j] == num + 1)
		result += check_routes(file, i + 1, j);
	if (j > 0 && file->array_content[i][j - 1] == num + 1)
		result += check_routes(file, i, j - 1);
	if (j < file->list_content->len - 1 && file->array_content[i][j + 1] == num + 1)
		result += check_routes(file, i, j + 1);
	return (result);
}

void	repair_file(t_file *file)
{
	int		i;
	int		j;

	i = 0;
	while (i < file->lines)
	{
		j = 0;
		while (j < file->list_content->len - 1)
		{
			if (file->array_content[i][j] == '.')
				file->array_content[i][j] = '9';
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_file		*file;
	int			result;
	int			i;
	int			j;
	
	if (argc != 2)
	{
		ft_printf("Usage: %s <file>\n", argv[0]);
		return (1);
	}
	file = ft_create_file_from_filename(argv[1]);
	ft_file_print(file);
	ft_printf("\n\n");
	result = 0;
	i = 0;
	while (i < file->lines)
	{
		j = 0;
		while (j < file->list_content->len - 1)
		{
			if (file->array_content[i][j] == '0')
			{
				result += check_routes(file, i, j);
				//repair_file(file);
				ft_printf("Result: %d\n", result);
			}
			j++;
		}
		i++;
	}
	ft_file_clear(&file);
	return (0);
}