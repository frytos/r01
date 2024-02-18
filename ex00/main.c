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
#include "ft_atoi.h"

//#define SIZE 4

int	init_grid(char *argv[], int grid[4][4][2]);
int	check_n_set(int matrix[4][4][2], int row, int col, int value);
int	acceptable_input(int argc, char *argv[]);
int	fill_easy_values(char *argv[], int arg, int grid[4][4][2]);
int	print_error_and_exit(int trigger, int error_code);

int	main(int argc, char *argv[])
{
	int	grid[4][4][2];	//static matrix 2-dimensions array (4x4 matrix)
						//with potential flags (locked, possible values)
	print_error_and_exit(!acceptable_input, -1);// checks input 
	init_grid(argv, grid);//populates grid based on 1&4 given values,
							//updates it if possible,
							//or returns an error code if not possible
}

int	init_grid(char *argv[], int grid[4][4][2])
{
	int	arg;
	int	j;

	arg = 1;
	while (arg < 17) //this loop browses arguments passed to the main()
	{
		fill_easy_values(argv, arg, grid[4][4][2]);
		arg++;
	}
}

int	check_n_set(int grid[4][4][2], int row, int col, int value)
{
//prevents overwriting a tower, checks that rules result match
	print_error_and_exit(grid[row][col][0] && grid[row][col][0] - value, -2);
	grid[row][col][0] == value; //if empty, assign value
}

int	acceptable_input(int argc, char *argv[]) // check param passed to main()
{
	int	i;

	print_error_and_exit(argc != 2, -3);
	i = 0;
	while (i < 32 || i != 0)
	{
		// Checks that is a string of [1-4] char sepparated by a space
		print_error_and_exit(!(argv[1][i] - 32 && (argv[1][i] - 49) / 4), -4);
		i++;
	}
	print_error_and_exit(i != 31, -5); // Checks the length of the string passed
}

int	fill_easy_values(char *argv[], int arg, int grid[4][4][2])
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
				check_n_set(grid[4][4][2], j, arg - 1, j + 1);
			else if (input_section == 1)
				check_n_set(grid[4][4][2], 3 - j, arg - 5, j + 1);
			else if (input_section == 2)
				check_n_set(grid[4][4][2], arg - 9, j, j + 1);
			else
				check_n_set(grid[4][4][2], arg - 13, 3 - j, j + 1);
			j++;
		}
		if (ft_atoi(argv[arg]) == 1) //Sets answer for "1" special case
			grid[0][arg - 1][0] = 4;
	}
}
