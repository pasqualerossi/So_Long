#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "get_next_line.h"
# include "../minilibx/mlx.h"

typedef struct start
{
	int		fd;
	int		heightmap;
	int		widthmap;
	int		playercount;
	int		columncount;
	int		exitcount;
	int		playerfirst;
	int		playersecond;
	int		counter;
	int		collectables;

	char	**map;

	void	*floor;
	void	*barrier;
	void	*player;
	void	*exit;
	void	*collectable;
	void	*mlxpointer;
	void	*winpointer;

}	complete;

int		exit_game(complete *game);
int		map_reading(complete *game);
int		controls_working(int command, complete *game);
void	adding_in_graphics(complete *game);
void	place_images_in_game(complete *game);
void	check_errors(complete *game);

#endif
