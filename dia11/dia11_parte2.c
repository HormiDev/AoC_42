/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dia11_parte2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:31:59 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/12/11 16:34:17 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../42_Libft/libft.h"

void	blinking(t_list_dbl *lst)
{
	t_list_dbl	*tmp = lst;
	char	*str;
	
	
	while (tmp != NULL)
	{
		str = (char *)tmp->content;
		if (ft_atol(str) == 0)
		{
			free(str);
			tmp->content = ft_strdup("1");
		}
		else if (ft_strlen_p(str) % 2 == 0)
		{
			ft_list_dbl_add_prev(tmp, ft_list_dbl_new(ft_substr_p(str, 0, ft_strlen_p(str) / 2)));
			tmp->content = ft_substr_p(str, ft_strlen_p(str) / 2, ft_strlen_p(str) / 2);
			free(str);
			str = (char *)tmp->content;
			tmp->content = ft_ltoa(ft_atol(str));
		}
		else
		{
			tmp->content = ft_ltoa(ft_atol(str) * 2024);
			free(str);
		}
			
		tmp = tmp->next;
	}
}

void print_list(t_list_dbl *lst)
{
	t_list_dbl *tmp = lst;
	int i = 0;
	while (tmp != NULL)
	{
		ft_printf("[%s]", (char *)tmp->content);
		tmp = tmp->next;
		i++;
	}
	ft_printf("\n");
}

int main()
{
	char	*str = "9759 0 256219 60 1175776 113 6 92833";
	char	**split = ft_split(str, ' ');
	t_list_dbl	*lst_stones = NULL;
	int		i = 0;

	while (split[i] != NULL)
	{
		ft_list_dbl_addnew_back(&lst_stones, split[i]);
		i++;
	}
	i = 0;
	ft_printf("blinking %d stones: %d\n", i, ft_list_dbl_size(lst_stones));
	print_list(lst_stones);
	while (i < 75)
	{
		
		blinking(lst_stones);
		lst_stones = ft_list_dbl_get_first(lst_stones);
		i++;
		ft_printf("blinking %d stones: %d\n", i, ft_list_dbl_size(lst_stones));
	}
	free(split);
	ft_printf("result: %d\n", ft_list_dbl_size(lst_stones));
	ft_list_dbl_clear(&lst_stones, free);
	return (0);
}