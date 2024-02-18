/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrouss <argrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:15:08 by argrouss          #+#    #+#             */
/*   Updated: 2024/02/18 02:38:18 by argrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include "ft_atoi.h"
#include "utils.h"

#define X 4
#define Y 4
#define Z 2

void	init_grid(char *argv[], int grid[X][Y]);
void	check_n_set(int grid[X][Y], int row, int col, int value);
void	acceptable_input(int argc, char *argv[]);
void	fill_easy_values(char *argv[], int arg, int grid[X][Y]);

int	main(int argc, char *argv[])
{
	int	grid[X][Y];	//static matrix 2-dimensions array (4x4 matrix)
						//with potential flags (locked, possible values)
	acceptable_input(argc, argv);// checks input 
	init_grid(argv, grid);//populates grid based on 1&4 given values,
							//updates it if possible,
							//or returns an error code if not possible
}

void	init_grid(char *argv[], int grid[X][Y])
{
	int	arg;

	arg = 1;
	while (arg < 17) //this loop browses arguments passed to the main()
	{
		fill_easy_values(argv, arg, grid);
		arg++;
	}
}

void	check_n_set(int grid[X][Y], int row, int col, int value)
{
//prevents overwriting a tower, checks that rules result match
	print_error_and_exit(grid[row][col] && grid[row][col] - value, -2);
	grid[row][col] = value; //if empty, assign value
}

void	acceptable_input(int argc, char *argv[]) // check param passed to main()
{
	int	i;

	print_error_and_exit(argc != 2, -3);
	i = 0;
	while (i < 32 || argv[1][i] != 0)
	{
		// Checks that is a string of [1-4] char sepparated by a space
		print_error_and_exit(!(argv[1][i] - 32 && (argv[1][i] - 49) / 4), -4);
		i++;
	}
	print_error_and_exit(i != 31, -5); // Checks the length of the string passed
}

void	fill_easy_values(char *argv[], int arg, int grid[X][Y])
{
	int	input_section;
	int	j;	//Uses this i to set the "4" towers
	input_section = (arg - 1) / 4;
	if ((1 + 4 * input_section) <= arg && arg <= 4 * (input_section + 1))
	{
		j = 0;
		while (j < 4 && ft_atoi(argv[arg]) == 4)
		{
			if (input_section == 0)
				check_n_set(grid, j, arg - 1, j + 1);
			else if (input_section == 1)
				check_n_set(grid, 3 - j, arg - 5, j + 1);
			else if (input_section == 2)
				check_n_set(grid, arg - 9, j, j + 1);
			else
				check_n_set(grid, arg - 13, 3 - j, j + 1);
			j++;
		}
		if (ft_atoi(argv[arg]) == 1) //Sets answer for "1" special case
			grid[0][arg - 1] = 4;
	}
}


