# ifndef CUB3D_H
# define CUB3D_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <sys/time.h>

# define BUFFER_SIZE 10
# define TILE_SIZE 64
# define PROJ_DIST 1108.512516844081016
# define WINDOW_H 800
# define WINDOW_W 1280
# define ANGLE_DIFF 0.046875
typedef struct s_map	t_map;

typedef struct s_intersection
{
	float	wall_hitx;
	float	wall_hity;
	float	delta_x;
	float	delta_y;
}	t_intersection;

typedef struct s_wall
{
	float	heigth;
	float	wall_top;
	int		color;
	int		direction;
}	t_wall;

typedef struct s_vector
{
	int	    x;
	int	    y;
    float	angle;
    t_map   *map;
} t_vector;

typedef struct
{
    char    rgb[9];
} RGBhex;

typedef struct s_winpoint
{
    void	*win;
    void	*mlx;
    void    *canvas_ptr;
    int     *addr_canva;
    int     bpp;
    int     size_line;
    int     endian;
}   t_winp;

typedef struct  s_texture
{
    char    *extract;
    char    *path;
    void    *img_ptr;
    int     *addr_img;
    int     height;
    int     width;
    int     img_height;
    int     img_width;
    int     bpp;
    int     size_line;
    int     endian;
    t_winp  winp;
} t_texture;

typedef struct	s_data {
    void	*img;
    char	*addr;
    int		bits_per_pixel;
    int		line_length;
    int		endian;
}				t_data;


typedef struct s_map
{
	t_vector	size;
	t_vector	player;
	int			start_y;
	int			max_x;
	int			max_y;
	t_texture 		*NO;
	t_texture		*SO;
	t_texture 		*WE;
	t_texture 		*EA;
	char		*F;
	char		*C;
	char		orientation;
	char		**map;
	char		**play_map;
    int         *tab_F;
    int         *tab_C;
    RGBhex      F_RGBhex;
    RGBhex      C_RGBhex;
    t_winp      winp;
}	t_map;

//double    find_first_hor(t_map map, int i);
//double    find_first_vert(t_map map);
//double    find_close_wall(char **map, int x, int y, double angle, double i);
//t_test    find_close_wall(t_map map, double i, t_test test);
double  tan_degrees(double angle);
void	img_put(t_winp *winp, int x, t_wall *wall, t_texture *img);
void	my_mlx_pixel_put(t_texture *data, int x, int y, int color);
t_wall  find_wall_distance(t_map map, float cos);
void	window_manager(t_map *map);
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
void	draw_map(t_winp *win, t_map *map);
int     ft_extract(t_map *map);
int     ft_check_map(t_map *struc_map);
void    ft_print_player_map(char **map);
int     ft_valid_data(t_map *map);
int     ft_extract_F_data(t_map *map);
int     ft_extract_C_data(t_map *map);
int     ft_extract_data(t_map *map);
int     ft_check_rgb(int *tab);
int	    ft_isnum(int c);
int     ft_extract_rgb(int i, char *tmp, char *rgb, char t, t_map *map, int count);
int     ft_check_valid_num(char *f, int i);
int     get_max_value(char **map, t_map *s_map);
char	**ft_malloc_play_map(t_map *s_map);
void	  init_map(t_map *map);
int	    ft_match(char *c, t_map *map);
double  cos_degrees(double angle);
int     convert_hexa(t_map *map);
int	    ft_close(void);
int     ft_input(int key, void *param);
int     init_all_text(t_map *map);
int     ft_texture_data(t_map *map);
void    print_texture(t_winp *winp, t_texture *text, t_wall *wall);

#endif