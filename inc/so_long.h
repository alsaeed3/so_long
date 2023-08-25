#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/inc/libft.h"
// # include <mlx.h>                                         
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>



typedef struct s_game
{
	int		x;
	int		y;
	int		fd;
	int		map_width;
	int		map_height;
	int		map_collect;
	int		map_exit;
	int		map_player;
	int		map_floor;
	int		img_width;
	int		img_height;
	int		player_exist;
	int		player_locx;
	int		player_locy;
	int		player_moves;
	int		player_collect;
	int		player_exit;
	int		valid_collect;
	int		valid_exit;
	void	*image;
	void	*mlx;
	void	*mlx_window;
	char	*map_read;
	char	**map_2d;
	char	**vp_map;
}			t_game;



#endif