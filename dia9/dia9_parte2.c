/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dia9_parte2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 02:43:51 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/12/10 04:28:41 by ide-dieg         ###   ########.fr       */
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

int search_first_group_num(int *nums, int len, int num, int group_size)
{
	int i;
	int count;

	i = 0;
	while (i < len)
	{
		if (nums[i] == num)
		{
			count = 0;
			while (i < len && nums[i + count] == num)
			{
				count++;
			}
			if (count >= group_size)
				return (i);
		}
		i++;
	}
	return (-1);
}

int search_last_group_less_than_consecutive(int *nums, int len, int *group_size)
{
	int i;
	int j;
	int count;

	i = len - 1;
	*group_size = 0;
	while (i >= 0)
	{
		if (nums[i] != -1)
		{
			count = 1;
			j = i - 1;
			while (j >= 0 && nums[j] == nums[i])
			{
				count++;
				j--;
			}
			*group_size = count;
			return (i);
		}
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
	ft_printf("\n");
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
	int 		group_size;
	int			nums_len_tmp;

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
	nums_len_tmp = nums_len;
	while (nums_len_tmp > 0)
	{
		j = search_last_group_less_than_consecutive(nums, nums_len_tmp, &group_size);
		if (j == -1)
			break ;
		i = search_first_group_num(nums, j, -1, group_size);
		if (i != -1)
		{
			k = 0;
			while (k < group_size)
			{
				nums[i + k] = nums[j - k];
				nums[j - k] = -1;
				k++;
			}
			nums_len_tmp = j - group_size + 1;
		}
		else
			nums_len_tmp = j - group_size + 1;
		//ft_printf("group_size: %d i: %d j: %d nums_len_tmp: %d\n", group_size, i, j, nums_len_tmp);
		//printnums(nums, nums_len_tmp);
		//printnums(nums, nums_len);
	}
	printnums(nums, nums_len);
	ft_printf("\n\n");
	i = 0;
	result = 0;
	while (i < nums_len)
	{
		if (nums[i] != -1)
		{
			result += nums[i] * i;
		}
		i++;
	}
	printf("Result: %ld\n", result);
	free(nums);
	ft_file_clear(&file);
	return (0);
}