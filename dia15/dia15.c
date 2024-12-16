/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dia15.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 00:12:31 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/12/16 03:00:14 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../42_Libft/libft.h"

void localize_submarine(t_file *file, int *submarine_xy)
{
	int x;
	int y;

	y = 0;
	while (y < file->lines)
	{
		x = 0;
		while (x < file->list_content->len)
		{
			if (file->array_content[y][x] == '@')
			{
				submarine_xy[0] = x;
				submarine_xy[1] = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

int localice_first_line_instructions(t_file *file)
{
	int i;

	i = 0;
	while (i < file->lines)
	{
		if (file->array_content[i][0] == '\n')
			break;
		i++;
	}
	return (++i);
}

void up(t_file *file, int *xy)
{
	char tmp;

	tmp = file->array_content[xy[1]][xy[0]];
	if (file->array_content[xy[1] - 1][xy[0]] == 'O')
	{
		up(file, (int[2]){xy[0], xy[1] - 1});
	}
	if (file->array_content[xy[1] - 1][xy[0]] == '.')
	{
		file->array_content[xy[1]][xy[0]] = '.';
		file->array_content[xy[1] - 1][xy[0]] = tmp;
	}
}

void right(t_file *file, int *xy)
{
	char tmp;

	tmp = file->array_content[xy[1]][xy[0]];
	if (file->array_content[xy[1]][xy[0] + 1] == 'O')
	{
		right(file, (int[2]){xy[0] + 1, xy[1]});
	}
	if (file->array_content[xy[1]][xy[0] + 1] == '.')
	{
		file->array_content[xy[1]][xy[0]] = '.';
		file->array_content[xy[1]][xy[0] + 1] = tmp;
	}
}

void down(t_file *file, int *xy)
{
	char tmp;

	tmp = file->array_content[xy[1]][xy[0]];
	if (file->array_content[xy[1] + 1][xy[0]] == 'O')
	{
		down(file, (int[2]){xy[0], xy[1] + 1});
	}
	if (file->array_content[xy[1] + 1][xy[0]] == '.')
	{
		file->array_content[xy[1]][xy[0]] = '.';
		file->array_content[xy[1] + 1][xy[0]] = tmp;
	}
}

void left(t_file *file, int *xy)
{
	char tmp;

	tmp = file->array_content[xy[1]][xy[0]];
	if (file->array_content[xy[1]][xy[0] - 1] == 'O')
	{
		left(file, (int[2]){xy[0] - 1, xy[1]});
	}
	if (file->array_content[xy[1]][xy[0] - 1] == '.')
	{
		file->array_content[xy[1]][xy[0]] = '.';
		file->array_content[xy[1]][xy[0] - 1] = tmp;
	}
}

void printmap(t_file *file)
{
	int i;

	i = 0;
	while (file->array_content[i][0] != '\n')
	{
		ft_printf("%s", file->array_content[i]);
		i++;
	}
	ft_printf("\n");
}

int calculateresult(t_file *file)
{
	int i;
	int j;
	int result;

	i = 0;
	result = 0;
	while (file->array_content[i][0] != '\n')
	{
		j = 0;
		while (file->array_content[i][j] != '\0')
		{
			if (file->array_content[i][j] == 'O')
				result += 100 * i + j;
			j++;
		}
		i++;
	}
	return (result);
}

int main(int argc, char **argv)
{
	t_file		*file;
	int			submarine_xy[2];
	int 		i;
	int 		j;
	int			result;

	if (argc != 2)
	{
		ft_printf("usage: %s <file>\n", argv[0]);
		return (1);
	}
	file = ft_create_file_from_filename(argv[1]);
	//ft_file_print(file);
	i = 0;
	j = localice_first_line_instructions(file);
	while (file->array_content[j][i] != '\0')
	{
		localize_submarine(file, submarine_xy);
		//printmap(file);
		//sleep(1);
		if (file->array_content[j][i] == '\n')
		{
			j++;
			i = 0;
		}
		if (file->array_content[j][i] == '^')
		{
			up(file, submarine_xy);
		}
		else if (file->array_content[j][i] == '>')
		{
			right(file, submarine_xy);
		}
		else if (file->array_content[j][i] == 'v')
		{
			down(file, submarine_xy);
		}
		else if (file->array_content[j][i] == '<')
		{
			left(file, submarine_xy);
		}
		i++;
	}
	printmap(file);
	result = calculateresult(file);
	ft_printf("Result: %d\n", result);
	ft_file_clear(&file);
	return (0);
}