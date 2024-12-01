/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:58:21 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/12/01 18:03:25 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int count_mun_in_array(int *list, int size, int num)
{
	int i = 0;
	int count = 0;

	while (i < size)
	{
		if (list[i] == num)
			count++;
		i++;
	}
	return (count);
}

int **two_list(int argc, char **argv)
{
	int half_size = argc / 2;
	int i;
	int j;
	int list;
	int **lists;
	
	lists = malloc(2 * sizeof(int *));
	lists[0] = malloc(half_size * sizeof(int));
	lists[1] = malloc(half_size * sizeof(int));
	i = 1;
	j = 0;
	list = 0;
	while (i < argc)
	{
		if (list == 0)
		{
			lists[0][j] = atoi(argv[i]);
			list++;
		}
		else
		{
			lists[1][j] = atoi(argv[i]);
			list = 0;
			j++;
		}
		i++;
	}
	return (lists);
}


int	main(int argc, char **argv)
{
	int i;
	int j = argc / 2;
	int **lists;
	int sum;

	i = 0;
	lists = two_list(argc, argv);
	printf("Lists desorder\n");
	while (i < j)
	{
		printf("%d %d\n", lists[0][i], lists[1][i]);
		i++;
	}
	i = 0;
	sum = 0;
	while (i < j)
	{
		sum += count_mun_in_array(lists[1], j, lists[0][i]) * lists[0][i];
		i++;
	}
	printf("Sum: %d\n", sum);
	free(lists[0]);
	free(lists[1]);
	free(lists);
	return (0);
}