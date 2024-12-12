/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dia12_parte2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:43:36 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/12/12 23:18:55 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../42_Libft/libft.h"

int	count_perimeter(t_file *file)
{
	int 	perimeter;
	int 	x;
	int 	y;
	int 	tmp1;
	int 	tmp2;

	perimeter = 0;
	x = 0;
	tmp1 = 0;
	tmp2 = 0;
	while (x < file->list_content->len)
	{
		y = 0;
		while (y < file->lines)
		{
			if (file->array_content[y][x] == '1')
			{
				if (x == 0 || (file->array_content[y][x - 1] != '1'))
				{
					if (tmp1 == 0)
						perimeter++;
					tmp1 = 1;
				}
				else
					tmp1 = 0;
			}
			else
				tmp1 = 0;
			if (file->array_content[y][x] == '1')
			{
				if (x == file->list_content->len - 1 || (file->array_content[y][x + 1] != '1'))
				{
					if (tmp2 == 0)
						perimeter++;
					tmp2 = 1;
				}
				else
					tmp2 = 0;
			}
			else
				tmp2 = 0;
			y++;
		}
		x++;
	}
	y = 0;
	tmp1 = 0;
	tmp2 = 0;
	while (y < file->lines)
	{
		x = 0;
		while (x < file->list_content->len)
		{
			if (file->array_content[y][x] == '1')
			{
				if (y == 0 || (file->array_content[y - 1][x] != '1'))
				{
					if (tmp1 == 0)
						perimeter++;
					tmp1 = 1;
				}
				else
					tmp1 = 0;
			}
			else
				tmp1 = 0;
			if (file->array_content[y][x] == '1')
			{
				if (y == file->lines - 1 || (file->array_content[y + 1][x] != '1'))
				{
					if (tmp2 == 0)
						perimeter++;
					tmp2 = 1;
				}
				else
					tmp2 = 0;
			}
			else
				tmp2 = 0;
			x++;
		}
		y++;
	}

	return (perimeter);
}

int	select_new_area(t_file *file, int x, int y, char new_char)
{
	char	char_selected;
	int 	area;

	area = 1;
	char_selected = file->array_content[y][x];
	file->array_content[y][x] = new_char;
	if (x > 0 && file->array_content[y][x - 1] == char_selected)
		area += select_new_area(file, x - 1, y, new_char);
	if (x < file->list_content->len - 1 && file->array_content[y][x + 1] == char_selected)
		area += select_new_area(file, x + 1, y, new_char);
	if (y > 0 && file->array_content[y - 1][x] == char_selected)
		area += select_new_area(file, x, y - 1, new_char);
	if (y < file->lines - 1 && file->array_content[y + 1][x] == char_selected)
		area += select_new_area(file, x, y + 1, new_char);
	return (area);
}

int	main(int argc, char **argv)
{
	t_file	*file;
	int		xy[2];
	int		area;
	int		perimeter;
	int 	result;
	
	if (argc != 2)
	{
		ft_printf("usage: %s <file>\n", argv[0]);
		return (1);
	}
	file = ft_create_file_from_filename(argv[1]);
	ft_file_print(file);
	ft_printf("\n\n");
	xy[1] = 0;
	result = 0;
	while (xy[1] < file->lines)
	{
		xy[0] = 0;
		while (xy[0] < file->list_content->len - 1)
		{
			if (file->array_content[xy[1]][xy[0]] != '0')
			{
				ft_printf("Area %c ", file->array_content[xy[1]][xy[0]]);
				area = select_new_area(file, xy[0], xy[1], '1');
				ft_printf("%d ", area);
				perimeter = count_perimeter(file);
				ft_printf("* %d ", perimeter);
				result += area * perimeter;
				ft_printf("= %d\n", (area * perimeter));
				select_new_area(file, xy[0], xy[1], '0');
			}
			xy[0]++;
		}
		xy[1]++;
	}
	ft_printf("Result: %d\n", result);
	ft_file_clear(&file);
	return (0);
}