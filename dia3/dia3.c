/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dia3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:32:32 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/12/03 18:23:39 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../42_Libft/libft.h"

int check_and_mult(char *check_point)
{
	int 	i;
	int 	n1;
	int 	n2;

	i = 3;
	if (check_point[i] != '(')
		return (0);
	i++;
	if (!ft_isdigit(check_point[i]))
		return (0);
	n1 = i;
	i++;
	while (ft_isdigit(check_point[i]))
		i++;
	if (check_point[i] != ',')
		return (0);
	i++;
	if (!ft_isdigit(check_point[i]))
		return (0);
	n2 = i;
	i++;
	while (ft_isdigit(check_point[i]))
		i++;
	if (check_point[i] != ')')
		return (0);
	return (ft_atoi(&check_point[n1]) * ft_atoi(&check_point[n2]));
}

int parsing_and_mult(t_file *file)
{
	char	*check_point;
	int 	line;
	int 	result;

	line = 0;
	result = 0;
	while (line < file->lines)
	{
		check_point = ft_strnstr(file->array_content[line], "mul", ft_strlen_p(file->array_content[line]));
		while (check_point != NULL)
		{
			result = result + check_and_mult(check_point);
			ft_printf("line: %d, result: %d ", line, result);
			write(1, check_point, 15);
			ft_putchar('\n');
			check_point++;
			check_point = ft_strnstr(check_point, "mul", ft_strlen_p(check_point));
		}
		line++;
	}
	return (result);
}

int main(int argc, char **argv)
{
	t_file	*file;
	int		result;

	if (argc != 2)
	{
		ft_putstr("Error: use ./dia3 <datos.txt>\n");
		return (1);
	}
	file = ft_create_file_from_filename(argv[1]);
	if (file == NULL)
	{
		ft_putstr("Error: file not found\n");
		return (1);
	}
	result = parsing_and_mult(file);
	ft_printf("Result: %d\n", result);
	ft_file_clear(&file);
	return (0);
}