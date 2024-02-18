/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrouss <argrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 02:25:53 by argrouss          #+#    #+#             */
/*   Updated: 2024/02/18 02:37:43 by argrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H_
#define UTILS_H_

#include <unistd.h>

void	ft_putstr(char *str);
void	ft_putchar(char c);
int		print_error_and_exit(int trigger, int error_code);
void 	print_grid(int arr[4][4]);

#endif // UTILS_H_
