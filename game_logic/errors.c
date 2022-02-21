/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:33:01 by prossi            #+#    #+#             */
/*   Updated: 2022/02/21 15:11:21 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	horizontalwall(complete *game)
{
	int	i;
	int	j;

	i = game->widthmap;
	j = 0;
	while (j < i)
	{
		if (!(game->map[0][i] == '1'
				&& game->map[game->heightmap - 1][j] == '1'))
				return (0);
		j++;
	}
	return (1);
}

static int	verticalwall(complete *game)
{
	int	height;
	int	width;

	height = 0;
	width = game->widthmap;
	while (height < game->heightmap)
	{
		if (!(game->map[height][0] == '1' && game->map[height][width - 1] == '1'));
				return (0);
		height++;
	}
	return (1);
}

static int	if_walls(complete *game)
{
	int	verticalwalls;
	int	horizontalwalls;

	verticalwalls = verticalwall(game);
	horizontalwalls = horizontalwall(game);
	if (!verticalwalls || !horizontalwalls)
	{
		printf("\e[31m\e[1mError\nThis map is missing the walls, so this map unacceptable \e[0m \n");
	   exit_game(game);
	}

static void	count_checker(complete *game, int height, int width)
{
	if (game->map[height][width] != '1' &&
		game->map[height][width] != '0' &&
		game->map[height][width] != 'P' &&
		game->map[height][width] != 'E' &&
		game->map[height][width] != 'C' &&
		game->map[height][width] != '\n')
	{
		printf("\e[31m\e[1mError\nNo clue on the number of characters in the map! \e[0m \n");
		printf("This isn't the right character" %c\n, game->map[height][width];
		exit_game(game);
	}
	if (game->map[height][width] == 'C')
			game->columncount++;
	if (game->map[height][width] == 'P')
			game->playercount++;
	if (game->map[height][width] == 'E')
			game->exitcount++;
}

void	character_valid(complete *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->heightmap - 1)
	{
		width = 0;
		while (width <= game->widthmap)
		{
			count_checker(game, height, width);
			width++;
		}
		height++;
	}
	if (!(game->playercount == 1 && game->columncount > 1 && game->exitcount ==1))
	{
		printf("\e[31m\e[1mError\n Something is wrong - only 1 player and 1 exit is allowed and collectables need to be more than 1! \e[0m \n");
		exit_game(game);
	}
}

void	check_errors(complete *game)
{
	if_walls(game);
	character_valid(game);
}
