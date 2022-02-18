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

	char	**map;

	void	

}	complete;

int		exit_game(complete *game);
void	check_errors(complete *game);
int		map_reading(complete *game);
int		controls_working(int command, complete *game);


#endif
