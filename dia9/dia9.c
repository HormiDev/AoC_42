/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dia9.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:04:04 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/12/09 20:06:27 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../42_Libft/libft.h"
# include <stdio.h>

int search_first_num(int *nums, int len, int num)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (nums[i] == num)
			return (i);
		i++;
	}
	return (-1);
}

int search_last_positive_num(int *nums, int len)
{
	int i;

	i = len - 1;
	while (i >= 0)
	{
		if (nums[i] != -1)
			return (i);
		i--;
	}
	return (-1);
}

int	char_to_int(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	return (-1);
}

void	printnums(int *nums, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (nums[i] == -1)
			ft_printf(".");
		else
			ft_printf("[%d]", nums[i]);
		i++;
	}
}
int main(int argc, char **argv)
{
	t_file		*file;
	int			*nums;
	int			nums_len;
	int 		i;
	int			j;
	int			k;
	long		result;

	if (argc != 2)
	{
		ft_printf("Usage: %s <file>\n", argv[0]);
		return (1);
	}
	file = ft_create_file_from_filename(argv[1]);
	i = 0;
	nums_len = 0;
	while (i < file->list_content->len)
	{
		nums_len += char_to_int(file->array_content[0][i]);
		i++;
	}
	ft_printf("nums_len: %d\n", nums_len);
	nums = malloc(sizeof(int) * nums_len + 1);
	if (!nums)
	{
		ft_printf("Error: malloc failed\n");
		ft_file_clear(&file);
		return (1);
	}
	ft_printf("Malloc ok\n");
	i = 0;
	j = 0;
	while (i < nums_len)
	{
		k = 0;
		while (k < char_to_int(file->array_content[0][j]))
		{
			nums[i] = j / 2;
			i++;
			k++;
		}
		j++;
		k = 0;
		while (k < char_to_int(file->array_content[0][j]))
		{
			nums[i] = -1;
			i++;
			k++;
		}
		j++;
	}
	printnums(nums, nums_len);
	ft_printf("\n\n");
	i = search_first_num(nums, nums_len, -1);
	j = search_last_positive_num(nums, nums_len);
	while (i < j)
	{
		nums[i] = nums[j];
		nums[j] = -1;
		i = search_first_num(nums, nums_len, -1);
		j = search_last_positive_num(nums, nums_len);
	}
	printnums(nums, nums_len);
	ft_printf("\n\n");
	i = 0;
	result = 0;
	while (nums[i] != -1)
	{
		result += nums[i] * i;
		i++;
	}
	printf("Result: %ld\n", result);
	free(nums);
	ft_file_clear(&file);
	return (0);
}