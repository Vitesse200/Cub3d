# ifndef CUB3D_H
# define CUB3D_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define BUFFER_SIZE 10
# define TILE_SIZE 320
# define PROJ_DIST 1662
# define WINDOW_H 1200
# define WINDOW_W 1920
# define ANGLE_DIFF 0.1875
# define TILE_SIZE 320

typedef struct s_vector
{
	int	x;
	int	y;
} t_vector;

typedef struct s_image
{
	void	*wall;
	void	*empty;
	void	*celling;
}	t_image;

typedef struct s_map
{
	t_vector	size;
	t_vector	player;
	int			y_1_1;
	int			x_1_1;
	int			y_2_1;
	int			x_2_1;
	int			end_conf;
	int			start_x;
	int			start_y;
	int			max_x;
	int			max_y;
	char		*NO;
	char		*SO;
	char		*WE;
	char		*EA;
	char		*F;
	char		*C;
	char		orientation;
	char		**map;
	char		**play_map;
	char		**check_map;
	void		*mlx;
	void		*window;
	int			moves;
}	t_map;

typedef struct s_winpoint
{
	void	*win;
	void	*mlx;
	//char	*map;
}			t_winp;

double find_first_hor(char **map, int posx, int posy, double angle);
double tan_degrees(double angle);
double find_first_vert(char **map, int posx, int posy, double angle);
char **init_map();
double find_close_wall(char **map, double angle);
//double 	find_first_horizontal_wall(char **map, int posx, int posy, double angle);
//double	find_first_vertical_wall(char **map, int posx, int posy, double angle);
void	window_manager(char **map);
void	*null_error(char *message);
int		error(char *message);
char	*ft_save(char *save);
char	*ft_get_line(char *save);
char	*ft_read_and_save(int fd, char *save);
char	*get_next_line(int fd);
void	ft_get_map(t_map *map, char *file);
int		ft_valid_file(char *file);
char	**ft_alloc_lines(char *file, t_map *game);
int		ft_file_linecount(char *file);
int		ft_file_type(char *s, char *end);
int		ft_extract(t_map *map);
int		ft_check_map(t_map *struct_map);
void	ft_print_player_map(t_map *map);
int	draw_map(t_winp winp, char **map);
int	closest_wall(char **map, double angle);

#endif