/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrouss <argrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 02:17:02 by argrouss          #+#    #+#             */
/*   Updated: 2024/02/18 22:38:09 by argrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "utils1.h"
#define X 4
#define Y 4
#define Z 2

void	check_input(int argc, char *argv[]);
void	set_height (int arg, int j, int height, int grid[X][Y]);
void	check_n_set(int grid[X][Y], int row, int col, int value);

void	check_input(int argc, char *argv[])
{
	int	i;
	int	t;

	print_error_and_exit((argc != 2), -3);
	i = 0;
	while (i < 31 || argv[1][i] != 0)
	{
		t = 1;
		if (argv[1][i] == ' ')
			t = 0;
		else if (argv[1][i] >= '1' && argv[1][i] <= '4')
			t = 0;
		print_error_and_exit(t, -4);
		i++;
	}
	print_error_and_exit(i != 31, -5);
}


void	set_height (int arg, int j, int height, int grid[X][Y])
{
	int	input_section;

	input_section = arg / 8;
	if (input_section == 0)
		check_n_set(grid, j, arg / 2, height);
	else if (input_section == 1)
		check_n_set(grid, 3 - j, arg / 2 - 4, height);
	else if (input_section == 2)
		check_n_set(grid, arg / 2 - 8, j, height);
	else
		check_n_set(grid, arg / 2 - 12, 3 - j, height);
}

void	check_n_set(int grid[X][Y], int row, int col, int value)
{
	print_error_and_exit(grid[row][col] && grid[row][col] - value, -2);
	grid[row][col] = value;
}