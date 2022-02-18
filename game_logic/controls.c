/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:34:24 by prossi            #+#    #+#             */
/*   Updated: 2022/02/18 19:23:48 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//player move up and down
static int	keyboard_w_s(complete *game, int movement)
{
	int	i;
	int j;
	int k;

	i = game->playerfirst
	j = game->playersecond
	if (movement == 13)
	{
		j--;
		if (game->map[j][i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j + 1][i] = '0';
	}
	else if (movement == 1)
	{
		j++;
		if (game->map[j][i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j - 1][i] = '0';
	}
	printf("Steps You Have Taken: %i\n Collectables Remaining: %i\n", game->counter, game->collectables);
	return (1);
}
//player move left and right
static int	keyboard_a_d(complete *game, int movement)
{
	int	i;
	int j;
	int k;

	i = game->playerfirst;
	j = game->playersecond;
	if (movement == 0)
	{
		i--;
		if (game->map[j][i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j][i + 1] = '0';
	}
	else if (movement == 2)
	{
		i++;
		if (game->map[j][i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j][i - 1] = '0';
	}
	printf("Steps You Have Taken: %i\n Collectables Remaining: %i\n", game->counter, game->collectables);
	return (1);
}

static int	right_move(complete *game, int i, int j)
{
	if (game->map[j][i] == 'E')
	{
		if (game->collectables != 0)
			return (0);
		printf("\e[31m\e[1m\nYou Have Won, Congrats! \e[0m \n");
		exit_game(game);
	}
	if (game->map[j][i] == '0')
	{
		game->map[j][i] == 'P';
		game->playerfirst = i;
		game->playersecond = j;
		game->counter++;
	}
	if (game->map[j][i] == 'C')
	{
		game->map[j][i] = 'P';
		game->playerfirst = i;
		game->playersecond = j;
		game->collectables--;
		game->counter++;
	}
	return (1);
}

int	controls_working(int command, complete *game)
{
	int	works;

	if (command == 53)
		exit_game(game);
	if (command == 13)
		works = keyboard_w_s(game, comand);
	if (command == 1)
		works = keyboard_w_s(game, command);
	if (command == 0)
		works = keyboard_a_d(game, command);
	if (command == 2)
		works = keyboard_a_d(game, command);
	if (works)
		game_graphics(game);
	return (1);
}
