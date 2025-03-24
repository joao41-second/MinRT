NAME	= tests

HEADER	= $(shell ls . unity | grep .h$)
SRCS	= $(shell ls . unity | grep .c$)

MINIRT_OBJS		= $(shell find ../Objs -type f | grep .o$ | grep -v main)

LIBFT_PATH	= ../libft/ft_libft
LIBFT 	= $(LIBFT_PATH)/libft.a

GNL_PATH	= ../libft/ft_get_next_line
GNL 	= $(GNL_PATH)/get_next_line.a

# LIST_PATH	= ../libft/ft_list
# LIST 	= $(LIST_PATH)/list.a

FREE_PATH	= ../libft/ft_free
FREE 	= $(FREE_PATH)/ft_free.a

MINILIBX_PATH	= ../libft/minilibx-linux
MINILIBX		= $(MINILIBX_PATH)/libmlx.a

OBJ_DIR	= ./obj
OBJS	= $(SRCS:%.c=$(OBJ_DIR)/%.o) $(MINIRT_OBJS)

CFLAGS	= -Wall -Wextra -Werror -DUNITY_INCLUDE_DOUBLE -g3 
IFLAGS	= -I. -Iunity -I../inc
LDFLAGS	= -L$(LIBFT_PATH) -lft -L$(GNL_PATH) -L$(MINILIBX_PATH) -lmlx -lXext -lX11 -lm

VPATH	= unity

all: $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re:  fclean all

$(NAME): $(OBJS) $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS) $(LIBFT) $(GNL) $(MINILIBX) $(FREE)

$(OBJ_DIR)/%.o: %.c $(HEADER) Makefile | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

run: all
	./$(NAME)

val: all
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY:	all clean fclean re run
