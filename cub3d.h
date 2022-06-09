#ifndef CUB3D_H
# define CUB3D_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif 

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

typedef struct s_check
{
    t_vector    top_left;
    t_vector    top_right;
    t_vector    btm_left;
    t_vector    btm_right;
}	t_check;

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
} t_map;

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
int		ft_check_map(t_map *struc_map);
void	ft_print_player_map(char **map);
int     check_4_sides_holes(char **map, t_map *s_map);

#endif