/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dia8_parte2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:52:02 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/12/08 17:56:00 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../42_Libft/libft.h"

typedef struct s_antena
{
	int x;
	int y;
} t_antena;

void	create_antinodes(char **antinodes, t_file *file, char antenna)
{
	int 		max_x;
	int 		max_y;
	int 		x;
	int 		y;
	int 		num_antenna;
	t_antena	*antenas;
	int 		i;
	int 		j;

	max_x = file->list_content->len - 1;
	max_y = file->lines;
	y = 0;
	num_antenna = 0;
	while (y < max_y)
	{
		x = 0;
		while (x < max_x)
		{
			if (file->array_content[y][x] == antenna)
				num_antenna++;
			x++;
		}
		y++;
	}
	ft_printf("Antenna: %c, num_antenna: %d\n", antenna, num_antenna);
	antenas = (t_antena *)malloc(sizeof(t_antena) * num_antenna);
	num_antenna = 0;
	y = 0;
	while (y < max_y)
	{
		x = 0;
		while (x < max_x)
		{
			if (file->array_content[y][x] == antenna)
			{
				antenas[num_antenna].x = x;
				antenas[num_antenna].y = y;
				num_antenna++;
			}
			x++;
		}
		y++;
	}
	i = 0;
	while (i < num_antenna)
	{
		j = i + 1;
		while (j < num_antenna)
		{
			antinodes[antenas[i].y][antenas[i].x]++;
			antinodes[antenas[j].y][antenas[j].x]++;
			x = (antenas[i].x - antenas[j].x) + antenas[i].x;
			y = (antenas[i].y - antenas[j].y) + antenas[i].y;
			while (x >= 0 && x < max_x && y >= 0 && y < max_y)
			{
				antinodes[y][x]++;
				x += (antenas[i].x - antenas[j].x);
				y += (antenas[i].y - antenas[j].y); 
			}
			x = (antenas[j].x - antenas[i].x) + antenas[j].x;
			y = (antenas[j].y - antenas[i].y) + antenas[j].y;
			while (x >= 0 && x < max_x && y >= 0 && y < max_y)
			{
				antinodes[y][x]++;
				x += (antenas[j].x - antenas[i].x);
				y += (antenas[j].y - antenas[i].y);
			}
			j++;
		}
		i++;
	}
	free(antenas);
}

void	init_antinodes(char **antinodes, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			antinodes[i][j] = '0';
			j++;
		}
		i++;
	}
}

void print_antinode(char **antinodes, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			ft_printf("%c", antinodes[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

int	iter_antenna(char *antenna)
{
	if (*antenna == '9')
		(*antenna) = 'A';
	else if (*antenna == 'Z')
		(*antenna) = 'a';
	else if (*antenna == 'z')
		return (0);
	else
		(*antenna)++;
	return (1);
}

int count_antinodes(char **antinodes, int x, int y)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if (antinodes[i][j] != '0')
				count++;
			j++;
		}
		i++;
	}
	ft_printf("Antinodes: %d\n", count);
	return (count);
}

int	main(int argc, char **argv)
{
	t_file		*file;
	char 		**antinodes;
	char 		antenna;
	int 		result;
	
	if (argc != 2)
	{
		ft_printf("Usage: ./dia8 <infile.txt>\n");
		return (1);
	}
	file = ft_create_file_from_filename(argv[1]);
	ft_file_print(file);
	ft_printf("\n\n");
	antinodes = ft_create_str_rectangular_array(file->list_content->len - 1, file->lines);
	init_antinodes(antinodes, file->list_content->len - 1, file->lines);
	print_antinode(antinodes, file->list_content->len - 1, file->lines);
	antenna = '0';
	antenna--;
	while (iter_antenna(&antenna))
	{
		create_antinodes(antinodes, file, antenna);
	}
	print_antinode(antinodes, file->list_content->len - 1, file->lines);
	result = count_antinodes(antinodes, file->list_content->len - 1, file->lines);
	ft_printf("Result: %d\n", result);
	ft_free_str_rectangular_array(antinodes, file->list_content->len - 1);
	ft_file_clear(&file);
	return (0);
}