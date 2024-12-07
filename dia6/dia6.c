/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dia6.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:30:03 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/12/06 17:04:42 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../42_Libft/libft.h"

void	patrolling(t_file *file, int *guard_xy, int *map_size_xy)
{
	while (0 == 0)
	{
		if (file->array_content[guard_xy[1]][guard_xy[0]] == '^')
		{
			if (guard_xy[1] - 1 >= 0)
			{
				if (file->array_content[guard_xy[1] - 1][guard_xy[0]] != '#')
				{
					file->array_content[guard_xy[1]][guard_xy[0]] = 'X';
					file->array_content[guard_xy[1] - 1][guard_xy[0]] = '^';
					guard_xy[1]--;
				}
				else
					file->array_content[guard_xy[1]][guard_xy[0]] = '>';
			}
			else
			{
				file->array_content[guard_xy[1]][guard_xy[0]] = 'X';
				break;
			}
		}
		else if (file->array_content[guard_xy[1]][guard_xy[0]] == 'v')
		{
			if (guard_xy[1] + 1 < map_size_xy[1])
			{
				if (file->array_content[guard_xy[1] + 1][guard_xy[0]] != '#')
				{
					file->array_content[guard_xy[1]][guard_xy[0]] = 'X';
					file->array_content[guard_xy[1] + 1][guard_xy[0]] = 'v';
					guard_xy[1]++;
				}
				else
					file->array_content[guard_xy[1]][guard_xy[0]] = '<';
			}
			else
			{
				file->array_content[guard_xy[1]][guard_xy[0]] = 'X';
				break;
			}
		}
		else if (file->array_content[guard_xy[1]][guard_xy[0]] == '<')
		{
			if (guard_xy[0] - 1 >= 0)
			{
				if (file->array_content[guard_xy[1]][guard_xy[0] - 1] != '#')
				{
					file->array_content[guard_xy[1]][guard_xy[0]] = 'X';
					file->array_content[guard_xy[1]][guard_xy[0] - 1] = '<';
					guard_xy[0]--;
				}
				else
					file->array_content[guard_xy[1]][guard_xy[0]] = '^';
			}
			else
			{
				file->array_content[guard_xy[1]][guard_xy[0]] = 'X';
				break;
			}
		}
		else if (file->array_content[guard_xy[1]][guard_xy[0]] == '>')
		{
			if (guard_xy[0] + 1 < map_size_xy[0])
			{
				if (file->array_content[guard_xy[1]][guard_xy[0] + 1] != '#')
				{
					file->array_content[guard_xy[1]][guard_xy[0]] = 'X';
					file->array_content[guard_xy[1]][guard_xy[0] + 1] = '>';
					guard_xy[0]++;
				}
				else
					file->array_content[guard_xy[1]][guard_xy[0]] = 'v';
			}
			else
			{
				file->array_content[guard_xy[1]][guard_xy[0]] = 'X';
				break;
			}
		}
	}
}

void	localice_guard(t_file *file, int *guard_xy, int *map_size_xy)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < map_size_xy[1])
	{
		while (x < map_size_xy[0])
		{
			if (file->array_content[y][x] == '^' || file->array_content[y][x] == 'v' ||
				file->array_content[y][x] == '<' || file->array_content[y][x] == '>')
			{
				guard_xy[0] = x;
				guard_xy[1] = y;
				return ;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

int count_X(t_file *file)
{
	int		x;
	int		y;
	int		result;

	y = 0;
	result = 0;
	while (file->array_content[y] != NULL)
	{
		x = 0;
		while (file->array_content[y][x] != '\0')
		{
			if (file->array_content[y][x] == 'X')
				result++;
			x++;
		}
		y++;
	}
	return (result);
}

int	main(int argc, char **argv)
{
	t_file	*file;
	int		guard_xy[2];
	int		map_size_xy[2];
	int		result;

	if (argc != 2)
	{
		ft_printf("Usage: %s file_name\n", argv[0]);
		return (0);
	}
	file = ft_create_file_from_filename(argv[1]);
	ft_file_print(file);
	ft_printf("\n\n");
	map_size_xy[0] = file->list_content->len - 1;
	map_size_xy[1] = file->lines;
	localice_guard(file, guard_xy, map_size_xy);
	ft_printf("Guard position: %d, %d\n", guard_xy[0], guard_xy[1]);
	patrolling(file, guard_xy, map_size_xy);
	ft_file_print(file);
	ft_printf("\n\n");
	result = count_X(file);
	ft_printf("Result: %d\n", result);
	ft_file_clear(&file);
	return (0);
}