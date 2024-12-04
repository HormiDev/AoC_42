/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dia4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:17:07 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/12/04 17:09:38 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../42_Libft/libft.h"

int check_XMAS(t_file *file, int i, int j)
{
	int	count;
	
	count = 0;
	if (i > 2 && file->array_content[i - 1][j] == 'M' && file->array_content[i - 2][j] == 'A' && file->array_content[i - 3][j] == 'S')
		count++;
	if (i > 2 && ft_strlen_p(file->array_content[i]) - j > 3 && file->array_content[i - 1][j + 1] == 'M' && file->array_content[i - 2][j + 2] == 'A' && file->array_content[i - 3][j + 3] == 'S')
		count++;
	if (ft_strlen_p(file->array_content[i]) - j > 3 && file->array_content[i][j + 1] == 'M' && file->array_content[i][j + 2] == 'A' && file->array_content[i][j + 3] == 'S')
		count++;
	if (ft_strlen_p(file->array_content[i]) - j > 3 && file->lines-1 - i > 2 && file->array_content[i + 1][j + 1] == 'M' && file->array_content[i + 2][j + 2] == 'A' && file->array_content[i + 3][j + 3] == 'S')
		count++;
	if (file->lines-1 - i > 2 && file->array_content[i + 1][j] == 'M' && file->array_content[i + 2][j] == 'A' && file->array_content[i + 3][j] == 'S')
		count++;
	if (file->lines-1 - i > 2 && j > 2 && file->array_content[i + 1][j - 1] == 'M' && file->array_content[i + 2][j - 2] == 'A' && file->array_content[i + 3][j - 3] == 'S')
		count++;
	if (j > 2 && file->array_content[i][j - 1] == 'M' && file->array_content[i][j - 2] == 'A' && file->array_content[i][j - 3] == 'S')
		count++;
	if (i > 2 && j > 2 && file->array_content[i - 1][j - 1] == 'M' && file->array_content[i - 2][j - 2] == 'A' && file->array_content[i - 3][j - 3] == 'S')
		count++;
	if (count)
		ft_printf("X found at line %d, column %d, result +%d\n", i + 1, j + 1, count);
	return (count);
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
			if (file->array_content[i][j] == 'X')
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
