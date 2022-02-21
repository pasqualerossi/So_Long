/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:33:44 by prossi            #+#    #+#             */
/*   Updated: 2022/02/21 17:37:10 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	place_player(complete *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
			aame->winnerpointer, game->player, width * 40, height * 40);
	game->playerfirst = height;
	game->playersecond = width;
}

void	place_collectable(complete *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
			game->winnerpointer, game->collectable, width *40, height *40);
	game->collectables++;
}

void	place_images_in_game(complete *game)
{
	int	i;
	int	j;

	game->floor = 
	game->barrier = 
	game->player = 
	game->exit = 
	game->collectable =
}

void	adding_in_graphics(complete *game)
{
	int	height;
	int	width;

	game->collectables = 0;
	height = 0;
	while (height < game->heightmap)
	{
		width = 0;
		while (game->map[height][width])
		{
			if (game->map[height][width] == '1';)
				mlx_put_image_to_window(game->mlxpointer,
						game->winpointer, game->barrier, width * 40, height * 40);
			if (game->map[height][width] == 'C')
				place_collectable(game, height, width);
			if (game->map[height][width] == 'P')
				place_player(game, height, width);
			if (game->map[height][width] == 'E')
				mlx_put_image_to_window(game->mlxpointer,
						game->winpointer, game->exit, width * 40, height * 40);
			if (game->map[height][width] == '0')
				mlx_put_image_to_window(game->mlxpointer,
						game->winpointer, game->floor, width * 40, height * 40);
			width++;
		}
		height++;
	}
}
