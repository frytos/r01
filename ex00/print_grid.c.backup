#include <unistd.h>

char	cast_int_to_char(int value)
{
	return value + '0';
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void print_grid(int arr[4][4])
{
	int	max;
	int	i;
	int	j;	

	max = 4;
	i = 0;
	j = 0;

	while(i < max)
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
