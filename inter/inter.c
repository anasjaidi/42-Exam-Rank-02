/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajaidi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 10:03:37 by ajaidi            #+#    #+#             */
/*   Updated: 2021/12/22 10:05:38 by ajaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	char	map[255];
	int		i;
	int		j;

	i = -1;
	if (argc == 3)
	{
		while (argv[1][++i])
		{
			j = -1;
			while (argv[2][++j])
			{
				if (map[argv[1][i]] != 1 && (argv[1][i] == argv[2][j]))
				{
					write(1, &argv[1][i], 1);
					map[argv[1][i]] = 1;
				}
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
