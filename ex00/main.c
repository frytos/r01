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
//#define SIZE 4

int	init_grid(char *argv[], int grid[4][4][2]);
int	assign_and_check(int matrix[4][4][2], int row, int col, int value);
int	acceptable_input(int argc, char *argv[]);

int	main(int argc, char *argv[])
{
	print_error_and_exit(!acceptable_input, -1);// checks input 
	int	grid[4][4][2];	//static matrix 2-dimensions array (4x4 matrix)
						//with potential flags (locked, possible values)
	init_grid(argv, grid);	//populates grid based on 1&4 given values,
							//updates it if possible,
							//or returns an error code if not possible
}

int	init_grid(char *argv[], int grid[4][4][2])
{
	int	index_argv;
	int	index_write; 

	index_argv = 1;
	while (index_argv < 17) //this loop browses arguments passed to the main()
	{
		int fill_easy_values(char *argv[], int index_argv, int grid[4][4][2]);
		index_argv++;
	}
}

int assign_and_check(int grid[4][4][2], int row, int col, int value) //overwrite a sure block
{
	//if already set, 
	print_error_and_exit(grid[row][col][0] && grid[row][col][0] - value, -2);		
	grid[row][col][0] == value;  // if empty, assign value
}

int	acceptable_input(int argc, char *argv[]) // check param passed to main()
{
	int index;

	print_error_and_exit(argc != 2, -3);				
	index = 0;
	while (index < 32 || index != 0)
	{	// Checks that is a string of [1-4] char sepparated by a space
		print_error_and_exit(!(argv[1][index] - 32 && (argv[1][index] - 49) / 4), -4);
		index++;
	}
	print_error_and_exit(index != 31, -5); // Checks the length of the string passed
}

int	fill_easy_values(char *argv[], int index_argv, int grid[4][4][2])
{
	int	part;
	int	index_write;	//Uses this index to set the "4" towers

	part = (index_argv - 1) / 4;
	if ((1 + 4 * part) <= index_argv && index_argv <= 4 * (part + 1))
	{
		index_write = 0;
		if (ft_atoi(argv[index_argv]) == 4) //Sets answer for "4" special case
		{
			while (index_write < 4)
			{
				if (part == 0)
					assign_and_check(grid[4][4][2], index_write, index_argv - 1, index_write + 1);
				else if (part == 1)
					assign_and_check(grid[4][4][2], 3 - index_write, index_argv - 5, index_write + 1);
                else if (part == 2)
					assign_and_check(grid[4][4][2], index_argv - 9, index_write, index_write + 1);
				else
					assign_and_check(grid[4][4][2], index_argv - 13, 3 - index_write, index_write + 1);
				index_write++;
			}
		}
		else if (ft_atoi(argv[index_argv]) == 1)   //Sets answer for "1" special case
			grid[0][index_argv - 1][0] = 4;
	}
}

int print_error_and_exit(int trigger, int error_code)
{
	if (!trigger)
	{
		ft_putstr("Error\n");
		exit(error_code);
	}
}
