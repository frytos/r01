/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrouss <argrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:15:08 by argrouss          #+#    #+#             */
/*   Updated: 2024/02/18 22:16:52 by argrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_atoi.h"
#include "utils1.h"
#include "utils2.h"
#define X 4
#define Y 4
#define Z 2

void	init_grid(char *argv[], int grid[X][Y]);
void	fill_easy_values(int value_observed, int arg, int grid[X][Y]);
void	zero_grid(int grid[X][Y]);

int	main(int argc, char *argv[])
{
	int	grid[X][Y];

	zero_grid(grid);
	check_input(argc, argv);
	init_grid(argv, grid);
	print_grid(grid);
}

void	zero_grid(int grid[X][Y])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < X)
	{
		while (j < Y)
		{
			grid[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
}

void	init_grid(char *argv[], int grid[X][Y])
{
	int	arg;

	arg = 0;
	while (arg < 32)
	{
		fill_easy_values(ft_atoi(&argv[1][arg]), arg, grid);
		arg += 2;
	}
}

void	fill_easy_values(int value_observed, int arg, int grid[X][Y])
{
	int	j;

	j = 0;
	if (value_observed == 4)
	{
		while (j < 4)
		{
			set_height (arg, j, j + 1, grid);
			j++;
		}
	}
	else if (value_observed == 1)
	{
		set_height (arg, 0, 4, grid);
	}
}
