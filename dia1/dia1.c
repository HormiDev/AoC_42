/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:56:00 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/12/01 17:41:39 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int sum_distance(int *list1, int *list2, int size)
{
	int i = 0;
	int sum = 0;

	while (i < size)
	{
		sum += abs(list1[i] - list2[i]);
		i++;
	}
	return (sum);
}

int the_array_is_ordered(int *array, int size)
{
	int i = 0;
	int j = 1;
	int ordered = 1;

	while (j < size)
	{
		if (array[i] > array[j])
		{
			ordered = 0;
			break;
		}
		i++;
		j++;
	}
	return (ordered);
}

void	ordered_array(int *array, int size)
{
	int i;
	int j;
	int temp;

	while (the_array_is_ordered(array, size) == 0)
	{
		i = 0;
		j = 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
			i++;
			j++;
		}
	}
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
	ordered_array(lists[0], j);
	ordered_array(lists[1], j);
	i = 0;
	printf("\nLists order\n");
	while (i < j)
	{
		printf("%d %d\n", lists[0][i], lists[1][i]);
		i++;
	}
	sum = sum_distance(lists[0], lists[1], j);
	printf("Sum of distances: %d\n", sum);
	free(lists[0]);
	free(lists[1]);
	free(lists);
	return (0);
}