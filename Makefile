# Compiler flags
#WFLGS = -Wall -Wextra -Werror

#READ_FLG = -g -pg
READ_FLG =  -O3 -march=native -flto -funroll-loops  -g -fopenmp

MINILIB_FLG = -Llibft/minilibx-linux -lmlx_Linux -lX11 -lXext -lm -Llibft/ft_get_next_line -Llibft/ft_free -Llibft/ft_libft \ 
	      -Llibft/ft_list
FLGS = $(WFLGS) $(READ_FLG) $(MINILIB_FLG) -fopenmp
... (rest of the Makefile content)