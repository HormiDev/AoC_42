/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dia4_parte2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:34:14 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/12/04 17:56:35 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../42_Libft/libft.h"

int check_XMAS(t_file *file, int i, int j)
{
	if (i > 0 && j > 0 && ft_strlen_p(file->array_content[i]) - i > 1 && file->lines - j > 1)
		if (((file->array_content[i - 1][j - 1] == 'M' && file->array_content[i + 1][j + 1] == 'S') ||
			(file->array_content[i + 1][j + 1] == 'M' && file->array_content[i - 1][j - 1] == 'S')) &&
			((file->array_content[i + 1][j - 1] == 'M' && file->array_content[i - 1][j + 1] == 'S') ||
			(file->array_content[i - 1][j + 1] == 'M' && file->array_content[i + 1][j - 1] == 'S')))
			return (1);
	return (0);
}


int main(int argc, char **argv)
{
	t_file	*file;
	int i;
	int j;
	int result;
	
	if (argc != 2)
	{
		ft_printf("Usage: %s file_name\n", argv[0]);
		return (0);
	}
	file = ft_create_file_from_filename(argv[1]);
	ft_file_print(file);
	ft_printf("\n");
	i = 0;
	result = 0;
	while (i < file->lines)
	{
		j = 0;
		while (file->array_content[i][j])
		{
			if (file->array_content[i][j] == 'A')
			{
				result += check_XMAS(file, i, j);
			}
			j++;
		}
		i++;
	}
	ft_printf("Result: %d\n", result);
	ft_file_clear(&file);
}
