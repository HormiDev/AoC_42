/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dia3_parte2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:43:19 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/12/03 23:50:36 by ide-dieg         ###   ########.fr       */
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

void clean_file(t_file *file)
{
	char	*check_point_do;
	char	*check_point_dont;
	int		line;
	int 	do_dont;

	line = 0;
	do_dont = 0;
	check_point_dont = file->array_content[line];
	ft_file_print(file);
	ft_printf("\n\n\n");
	while (line < file->lines)
	{
		if (do_dont == 0)
		{
			ft_printf("a\n");
			check_point_dont = ft_strnstr(check_point_dont, "don't()", ft_strlen_p(check_point_dont));
			if (check_point_dont == NULL)
			{
				ft_printf("c\n");
				line++;
				check_point_dont = file->array_content[line];
			}
			else
			{
				ft_printf("d\n");
				do_dont = 1;
			}
		}
		else
		{
			ft_printf("b\n");
			check_point_do = ft_strnstr(check_point_dont, "do()", ft_strlen_p(check_point_dont));
			if (check_point_do == NULL)
			{
				ft_printf("E\n");
				*check_point_dont = 0;
				line++;
				check_point_dont = file->array_content[line];
			}
			else
			{
				ft_printf("F\n");
				while (check_point_dont < check_point_do)
				{
					*check_point_dont = ' ';
					check_point_dont++;
				}
				check_point_dont = check_point_do;
				check_point_do = 0;
				do_dont = 0;
			}
		}
	}
	ft_file_print(file);
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
	clean_file(file);
	result = parsing_and_mult(file);
	ft_printf("Result: %d\n", result);
	ft_file_clear(&file);
	return (0);
}