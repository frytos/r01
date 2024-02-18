/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrouss <argrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 02:25:53 by argrouss          #+#    #+#             */
/*   Updated: 2024/02/18 22:52:03 by argrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS2_H_
#define UTILS2_H_
#define X 4
#define Y 4
#define Z 2

#include <unistd.h>

void	check_input(int argc, char *argv[]);
void	set_height (int arg, int j, int height, int grid[X][Y]);

#endif // UTILS2_H_
