/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dia4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:17:07 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/12/04 11:22:35 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../42_Libft/libft.h"

int main(int argc, char **argv)
{
	t_file	*file;
	char	**rectengle_array;
	
	if (argc != 2)
	{
		ft_printf("Usage: %s file_name\n", argv[0]);
		return (0);
	}
	file = ft_create_file_from_filename(argv[1]);
	rectengle_array = ft_create_str_rectangular_array(file)
}