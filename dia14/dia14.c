/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dia14.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 03:14:00 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/12/15 04:25:14 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../42_Libft/libft.h"

typedef struct s_guardian
{
	int	position_xy[2];
	int	velocity_xy[2];
}	t_guardian;

void print_map(int map_xy[2], t_guardian *guardians, int lines)
{
	int	i;
	int	j;
	int Guardian;
	int count_guardians;

	i = 0;
	while (i < map_xy[1])
	{
		j = 0;
		while (j < map_xy[0])
		{
			Guardian = 0;
			count_guardians = 0;
			while (Guardian < lines)
			{
				if (guardians[Guardian].position_xy[0] == j && guardians[Guardian].position_xy[1] == i)
					count_guardians++;
				Guardian++;
			}
			if (count_guardians > 0)
				ft_printf("%d", count_guardians);
			else
				ft_printf(".");
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

t_guardian	*parsing_guardians(t_file *file)
{
	t_guardian	*guardians;
	int			i;
	char		**split1;
	char		**split2;

	guardians = (t_guardian *)malloc(sizeof(t_guardian) * file->lines);
	i = 0;
	while (i < file->lines)
	{
		split1 = ft_split(file->array_content[i], ' ');
		split2 = ft_split(split1[0], ',');
		guardians[i].position_xy[0] = ft_atoi(&split2[0][2]);
		guardians[i].position_xy[1] = ft_atoi(split2[1]);
		ft_free_split(split2);
		split2 = ft_split(split1[1], ',');
		guardians[i].velocity_xy[0] = ft_atoi(&split2[0][2]);
		guardians[i].velocity_xy[1] = ft_atoi(split2[1]);
		ft_free_split(split2);
		ft_free_split(split1);
		ft_printf("Guardian %d: %d %d %d %d\n", i, guardians[i].position_xy[0], guardians[i].position_xy[1], guardians[i].velocity_xy[0], guardians[i].velocity_xy[1]);
		i++;
	}
	return (guardians);
}

void	patrolling(int map_xy[2], t_guardian *guardians, int lines, int time)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	while (i < time)
	{
		j = 0;
		while (j < lines)
		{
			x = guardians[j].position_xy[0] + guardians[j].velocity_xy[0];
			y = guardians[j].position_xy[1] + guardians[j].velocity_xy[1];
			if (x < 0)
				x = map_xy[0] + x;
			else if (x >= map_xy[0])
				x = x - map_xy[0];
			if (y < 0)
				y = map_xy[1] + y;
			else if (y >= map_xy[1])
				y = y - map_xy[1];
			guardians[j].position_xy[0] = x;
			guardians[j].position_xy[1] = y;
			//ft_printf("Guardian %d: %d %d\n", j, x, y);
			j++;
		}
		i++;
	}
}

int	*count_guardians_in_cuadrant(int map_xy[2], t_guardian *guardians, int lines)
{
	int	i;
	int	x;
	int	y;
	int	*cuadrant;

	cuadrant = (int *)ft_calloc(4, sizeof(int));
	i = 0;
	while (i < lines)
	{
		x = guardians[i].position_xy[0];
		y = guardians[i].position_xy[1];
		if (x < map_xy[0] / 2 && y < map_xy[1] / 2)
			cuadrant[0]++;
		else if (x > map_xy[0] / 2 && y < map_xy[1] / 2)
			cuadrant[1]++;
		else if (x < map_xy[0] / 2 && y > map_xy[1] / 2)
			cuadrant[2]++;
		else if (x > map_xy[0] / 2 && y > map_xy[1] / 2)
			cuadrant[3]++;
		i++;
	}
	ft_printf("Cuadrant 1: %d\n", cuadrant[0]);
	ft_printf("Cuadrant 2: %d\n", cuadrant[1]);
	ft_printf("Cuadrant 3: %d\n", cuadrant[2]);
	ft_printf("Cuadrant 4: %d\n", cuadrant[3]);
	return (cuadrant);
}

int main(int argc, char **argv)
{
	t_file		*file;
	t_guardian	*guardians;
	int			map_xy[2];
	int			*cuadrant;
	int			result;

	if (argc != 2)
	{
		ft_printf("usage: %s <file>\n", argv[0]);
		return (1);
	}
	map_xy[0] = 101;
	map_xy[1] = 103;
	file = ft_create_file_from_filename(argv[1]);
	ft_file_print(file);
	guardians = parsing_guardians(file);
	//print_map(map_xy, guardians, file->lines);
	patrolling(map_xy, guardians, file->lines, 100);
	cuadrant = count_guardians_in_cuadrant(map_xy, guardians, file->lines);
	result = cuadrant[0] * cuadrant[1] * cuadrant[2] * cuadrant[3];
	print_map(map_xy, guardians, file->lines);
	ft_printf("Result: %d\n", result);
	free(guardians);
	ft_file_clear(&file);
}