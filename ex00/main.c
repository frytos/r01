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
#include <stdio.h>

#include "ft_atoi.h"
#include "utils.h"

#define X 4
#define Y 4
#define Z 2

void	init_grid(char *argv[], int grid[X][Y]);
void	check_n_set(int grid[X][Y], int row, int col, int value);

void	check_input(int argc, char *argv[]);
void	fill_easy_values(int value_observed, int arg, int grid[X][Y]);
void    zero_grid(int grid[X][Y]);

int	main(int argc, char *argv[])
{
	printf("Begin printing\n");
	printf("argv[1] :\n       [i] 0 1 2 3 4 5 6 7 8 9 A B C D E F\nargv[1][i] %s\n",argv[1]);
	int	grid[X][Y];	//static matrix 2-dimensions array (4x4 matrix)
	printf("Post Matrix\n");
	ft_putchar(10); print_grid(grid); ft_putchar(10);
	zero_grid(grid);
    ft_putchar(10); print_grid(grid); ft_putchar(10);
					//with potential flags (locked, possible values)
	printf("before test argc : %d\n", argc);
	check_input(argc, argv);// checks input 
	printf("before init\n");
	init_grid(argv, grid);//populates grid based on 1&4 given values,
	printf("after init\n");
						//updates it if possible,
							//or returns an error code if not possible
	ft_putchar(10); print_grid(grid); ft_putchar(10);
}

void    zero_grid(int grid[X][Y])
{
    int i;
    int j;
    i = 0;
    j = 0;
    
    while (i < X)
    {
        while(j < Y)
        {
            grid[i][j] = 0;
            j++;
        }
        j = 0;
        i++;
        
    }
    printf("\ngrid zeroed out !\n");
}

void	init_grid(char *argv[], int grid[X][Y])
{
	int	arg;

	arg = 0;
	while (arg < 32) //this loop browses arguments passed to the main()
	{
		printf("init_grid: argv[1][%d] \t= %c\n", arg, argv[1][arg]);
		fill_easy_values(ft_atoi(&argv[1][arg]), arg, grid);
		arg+=2;
	}
}

void	check_n_set(int grid[X][Y], int row, int col, int value)
{
//prevents overwriting a tower, checks that rules result match
	print_error_and_exit(grid[row][col] && grid[row][col] - value, -2);
	grid[row][col] = value; //if empty, assign value
}

void	check_input(int argc, char *argv[]) // check param passed to main()
{
	int	i;
	printf("before test argc : %d\n", argc);
	print_error_and_exit((argc != 2), -3);
	printf("after test argc\n");
	i = 0;
	while (i < 32 || argv[1][i] != 0)
	{
		printf("%c\n", argv[1][i]);
		// Checks that is a string of [1-4] char sepparated by a space
		print_error_and_exit((argv[1][i] >= '1' && argv[1][i] <= '4'), -4);
		i+=2;
	}
	print_error_and_exit(i != 31, -5); // Checks the length of the string passed
}

void	fill_easy_values(int value_observed, int arg, int grid[X][Y])
{
	int	input_section;
	int	j;	//Uses this i to set the "4" towers
	
	//printf("%d\n",grid[0][0]);
	//printf("%d", arg);
    //return;
	//return;

	input_section = arg / 8;
	
    printf("arg = %d\tvalue_observed = %d\tinput_section : %d\n", arg, value_observed, input_section);
    
	j = 0;
	if (value_observed == 4)
	{
	    printf("special case 4\n");
		while (j < 4)
		{
			if (input_section == 0)
				check_n_set(grid, j, arg/2, j + 1);
			else if (input_section == 1)
				check_n_set(grid, 3 - j, arg/2 - 4, j + 1);
			else if (input_section == 2)
				check_n_set(grid, arg/2 - 8, j, j + 1);
			else
				check_n_set(grid, arg/2 - 12, 3 - j, j + 1);
			j++;
		}
		ft_putchar(10); print_grid(grid); ft_putchar(10);
	}
	else if (value_observed == 1)
	{//Sets answer for "1" special case
		printf("special case 1\n");
		if (input_section == 0)
			check_n_set(grid, 0, arg/2, 4);
		else if (input_section == 1)
			check_n_set(grid, 3, arg/2 - 4, 4);
		else if (input_section == 2)
			check_n_set(grid, arg/2 - 8, 0, 4);
		else
			check_n_set(grid, arg/2 - 12, 3, 4);
		ft_putchar(10); print_grid(grid); ft_putchar(10);
	}
	else
	    printf("No easy file for arg = %d, with value_observed = %d\n", arg, value_observed);
}


