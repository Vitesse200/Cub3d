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
# define TILE_SIZE 64
# define PROJ_DIST 1662
# define WINDOW_H 1200
# define WINDOW_W 1920
# define ANGLE_DIFF 0.03125
typedef struct s_map	t_map;

typedef struct s_test
{
	double height;
	int color;
}	t_test;

typedef struct s_vector
{
	int	    x;
	int	    y;
    double     angle;
    t_map   *map;
} t_vector;

//typedef struct
//{
//    int R;
//    int G;
//    int B;
//} RGBdec;

typedef struct
{
    char    rgb[9];
} RGBhex;

typedef struct s_image
{
	void	*wall;
	void	*empty;
	void	*celling;
}	t_image;

typedef struct s_check
{
    t_vector    top_left;
    t_vector    top_right;
    t_vector    btm_left;
    t_vector    btm_right;
}	t_check;

typedef struct s_winpoint
{
    void	*win;
    void	*mlx;
    //char	*map;
}   t_winp;

typedef struct s_map
{
	t_vector	size;
	t_vector	player;
    t_check     map_checker;
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
    int         *tab_F;
    int         *tab_C;
    RGBhex      F_RGBhex;
    RGBhex      C_RGBhex;
    t_winp      winp;
}	t_map;


double find_first_hor(t_map map);
double tan_degrees(double angle);
double find_first_vert(t_map map);
//double find_close_wall(char **map, int x, int y, double angle, double i);
t_test find_close_wall(t_map map, double i);

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
int		draw_map(t_winp winp, t_map *map);
int     ft_extract(t_map *map);
int		  ft_check_map(t_map *struc_map);
void	  ft_print_player_map(char **map);
int     ft_valid_data(t_map *map);
int     ft_extract_F_data(t_map *map);
int     ft_extract_C_data(t_map *map);
int     ft_extract_data(t_map *map);
int     ft_check_rgb(int *tab);
int	    ft_isnum(int c);
int     ft_extract_rgb(int i, char *tmp, char *rgb, char t, t_map *map, int count);
int     ft_check_valid_num(char *f, int i);
int     get_max_value(char **map, t_map *s_map);
char	  **ft_malloc_play_map(t_map *s_map);
void	  init_map(t_map *map);
int	    ft_match(char *c, t_map *map);
double cos_degrees(double angle);
int     convert_hexa(t_map *map);
int	    ft_close(void);
int     ft_input(int key, void *param);

#endif