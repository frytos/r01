/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrouss <argrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 02:17:02 by argrouss          #+#    #+#             */
/*   Updated: 2024/02/18 02:20:38 by argrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		print_error_and_exit(int trigger, int error_code);
void 	print_grid(int arr[4][4]);

void 	print_grid(int arr[4][4])
{
	int	max;
	int	i;
	int	j;	

	max = 4;
	i = 0;
	j = 0;
	while (i < max)
	{
		while (j < max)
		{
			ft_putchar(cast_int_to_char(arr[i][j]));
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}	
}

int	print_error_and_exit(int trigger, int error_code)
{
	if (!trigger)
	{
		ft_putstr("Error\n");
		exit (error_code);
	}
}

char	cast_int_to_char(int value)
{
	return value + '0';
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
