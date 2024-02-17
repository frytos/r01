/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrouss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:15:08 by argrouss          #+#    #+#             */
/*   Updated: 2024/02/17 13:24:13 by argrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	*grid[4][4][1];  // 2-dimensions array (4x4 matrix), with flags (like locked)
	
	if(!acceptable_input) // checks the formatting of the input only
	{
		ft_putchar("Error\n");
		return (-1);
	}
	init_grid(argv); //checks with the 4 & 1 values that the matrix is possible, returns it if exists, or returns an error code


}

int	init_grid(char *argv[],int grid)
{
	int	index;
	while (index < 17)
	{
		if (argv[index]
	}
}

int	acceptable_input(char *argv[])
{
	
}
