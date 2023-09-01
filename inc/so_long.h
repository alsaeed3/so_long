#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/inc/libft.h"
# include <mlx.h>                                         
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>

# define WALL "../textures/wall.xpm"
# define PLAYER "../textures/player.xpm"
# define FLOOR "../textures/floor.xpm"
# define COLLECTABLE "../textures/coin.xpm"
# define EXIT "../textures/exit.xpm"

typedef struct s_game
{
	int		x;
	int		y;
	int		fd;
	size_t	map_width;
	size_t	map_height;
	int		map_collect;
	int		map_exit;
	int		map_player;
	int		map_floor;
	int		img_width;
	int		img_height;
	int		player_exist;
	int		player_coins;
	int		player_moves;
	int		p_locx;
	int		p_locy;
	int		e_locx;
	int		e_locy;
	int		valid_collect;
	int		valid_exit;
	int		exit_mark;
	void	*mlx_img;
	void	*mlx_ptr;
	void	*mlx_win;
	char	*map_read;
	char	**map_2d;
	char	**vp_map;
}			t_game;

void	free_2d_array(t_game *game, char **array);
void	free_and_exit(t_game *game);
void	victory(t_game *game);
void	exit_mark(t_game *game, int x, int y);
void	map_parsing(t_game *game, char *map_file);
void	open_window(t_game *game);
int		mouse_hook(t_game *game);
void	print_2d_map(t_game *game, char *map_file);
int		check_walls(t_game *game, size_t y, size_t x);
void	check_map_errors(t_game *game, int y, int x);
char	*line_nonl(char *line, size_t width);
void	check_argc_and_ber(int argc, char *argv);
void	parse_fd(int fd);
void	init_game(t_game *game);
void	malloc_map_2d(t_game *game);
int		check_map_characters(t_game *game, int y, int x);
void	locate_p_e(t_game *game, int y, int x, char p_e);
int		move_player(t_game *game, int x, int y);
int		keyboard_hook(int key_num, t_game *game);
void	moves_counter(t_game *game, int y, int x);
void	backup_map(t_game *game);
void	validate_path(t_game *game, int y, int x);
void	draw_img(t_game *game, char *path, int x, int y);
void	exit_window(t_game *game);
void	exit_mark(t_game *game, int x, int y);
void	init_mlx(t_game *game);
void 	draw_map(t_game *game);
void	pick_img(t_game *game, char c, int x, int y);
char	*ft_strdup_nonl(char *s1);
void	check_pec_count(t_game *game);

#endif