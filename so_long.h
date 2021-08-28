#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_sprite {
	char	*wall;
	char	*ground;
	char	*hero;
	char	*colect;
	char	*door;
}				t_sprite;

typedef struct s_hero {
	char	*path;
	int		i;
	int		j;
}				t_hero;

typedef struct s_map {
	int		i;
	int		j;
}				t_map;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	char		**arr;
	int			count;
	t_hero		hero;
	t_map		map;
	t_sprite	sprite;

}				t_vars;

int		ft_go_right(t_vars *vars, char **arr, t_hero *hero, t_map map);
int		ft_go_left(t_vars *vars, char **arr, t_hero *hero, t_map map);
int		ft_go_up(t_vars *vars, char **arr, t_hero *hero, t_map map);
int		ft_go_down(t_vars *vars, char **arr, t_hero *hero, t_map map);

void	init_sprite(t_vars *vars);
void	init_hero(t_vars *vars, char **arr);
int		ft_close_all(t_vars *vars);
void	ft_vars_win(t_vars *v, char *sp, int j, int i);
int		ft_error_msg(char *str);

int		ft_cell (char *ch);
int		ft_move_cell (char **arr, t_hero *hero, int i, int j);
int		ft_search(char **arr, char ch);
char	*ft_ch_nm_file(char *name);

int		get_next_line(int fd, char **line);

char	**ft_get_map(char *file);
int		ft_check_map(char **arr);
int		ft_arrlen(char **arr);
void	ft_clear_arr(char **arr);
#endif