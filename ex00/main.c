/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrouss <argrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:15:08 by argrouss          #+#    #+#             */
/*   Updated: 2024/02/17 13:24:13 by argrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "ft_atoi.h"
#define SIZE 4

int	init_grid(char *argv[],int grid[SIZE][SIZE][2]);
int	assign_and_check(int matrix[SIZE][SIZE][2], int row,int col,int value);
int	acceptable_input(int argc, char *argv[]);

int	main(int argc, char *argv[])
{
	int	grid[SIZE][SIZE][2];  // static matrix 2-dimensions array (4x4 matrix), with flags (like locked)
	
	if(!acceptable_input) // checks the formatting of the input only
	{
		ft_putchar("Error\n");
		return (-1);
	}
	init_grid(argv, grid); //checks with the 4 & 1 values that the matrix is possible, returns it if exists, or returns an error code
}

int	init_grid(char *argv[],int grid[SIZE][SIZE][2])
{
	int	index_argv;
	int index_write; // we'll use this index to fill the "4" lines

	index_argv = 1 ;
	while (index_argv < 17) // this while loop browses the arguments passed to the main()
	{
		int fill_easy_values(char *argv[], int index_argv, int grid[SIZE][SIZE][2]);
		index_argv++;
	}
}

int assign_and_check(int grid[SIZE][SIZE][2], int row,int col,int value) // don't overwrite a sure block
{
	if (grid[row][col][0] && grid[row][col][0] - value) // if already set, compare that it is the same height
	{
		ft_putchar("Error\n");
		exit (-2);
	}
	else
		grid[row][col][0] == value;  // if empty, assign value
}

int	acceptable_input(int argc, char *argv[]) // check param passed to main()
{
	int index;

	if (argc != 2) 	// No more than 1 argument passed ()
	{
		ft_putchar("Error\n");
		exit (-3);
	}						
	index = 0;
	while (index < 32 || index != 0)
	{
		if (!(argv[1][index] - 32 && (argv[1][index] - 49)/4)) // Checks that is a string of [1-4] char sepparated by a space
			return (-4);
		index++;
	}
	if (index != 31) // Checks the length of the string passed
		return (-5);
}

int fill_easy_values(char *argv[], int index_argv, int grid[SIZE][SIZE][2])
{
	int part;
	int index_write;

	part = (index_argv - 1) / 4;
	if ((1 + 4 * part) <= index_argv && index_argv <= 4 * (part + 1))
	{
		index_write = 0;
		if (ft_atoi(argv[index_argv]) == 4) // Set answer for special case for 4 towers observable
		{
			while (index_write < 4)
			{
				if (part == 0)
					assign_and_check(grid[SIZE][SIZE][2], index_write, index_argv - 1, index_write + 1);
				else if (part == 1)
					assign_and_check(grid[SIZE][SIZE][2], 3 - index_write, index_argv - 5, index_write + 1);
                else if (part == 2)
					assign_and_check(grid[SIZE][SIZE][2], index_argv - 9, index_write, index_write + 1);
				else
					assign_and_check(grid[SIZE][SIZE][2], index_argv - 13, 3 - index_write, index_write + 1);
				index_write++;
			}
		}
		else if (ft_atoi(argv[index_argv]) == 1)   // Set answer for special case for 1 tower observable
			grid[0][index_argv - 1][0] = 4;
	}
}

int print_error_and_exit(int error_code)
{
	if (!error_code)
	{
		ft_putstr("Error\n");
		exit(error_code);
	}
}
