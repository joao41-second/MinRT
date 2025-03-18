NAME	= tests

HEADER	= $(shell ls . unity | grep .h$)
SRCS	= $(shell ls . unity | grep .c$)

MINIRT_OBJS		= $(shell find ../Objs -type f | grep .o$ | grep -v main)

LIBFT_PATH	= ../libft/ft_libft
LIBFT 	= $(LIBFT_PATH)/libft.a

MINILIBX_PATH	= ../libft/minilibx-linux
MINILIBX		= $(MINILIBX_PATH)/libmlx.a

OBJ_DIR	= ./obj
OBJS	= $(SRCS:%.c=$(OBJ_DIR)/%.o) $(MINIRT_OBJS)

CFLAGS	= -Wall -Wextra -Werror -DUNITY_INCLUDE_DOUBLE -g3 
IFLAGS	= -I. -Iunity -I../inc
LDFLAGS	= -L$(LIBFT_PATH) -lft -L$(MINILIBX_PATH) -lmlx -lXext -lX11 -lm

VPATH	= unity

all: $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re:  fclean all

$(NAME): $(OBJS) $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS)

$(OBJ_DIR)/%.o: %.c $(HEADER) Makefile | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

run: all
	./$(NAME)

val: all
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY:	all clean fclean re run
