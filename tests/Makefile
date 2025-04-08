NAME	= tests

HEADER	= $(shell ls . unity | grep .h$)
SRCS	= $(shell ls . unity | grep .c$)

MINIRT_OBJS		= $(shell find ../Objs -type f | grep .o$ | grep -v main)
MINIRT_PATH = ../
MINIRT = $(MINIRT_PATH)/miniRT.a

LIBFT_PATH	= ../libft/ft_libft
LIBFT 	= $(LIBFT_PATH)/libft.a

PRINTF_PATH	= ../libft/ft_printf
PRINTF 	= $(PRINTF_PATH)/libftprintf.a

GNL_PATH	= ../libft/ft_get_next_line
GNL 	= $(GNL_PATH)/get_next_line.a

LIST_PATH	= ../libft/ft_list
LIST 	= $(LIST_PATH)/list.a

FREE_PATH	= ../libft/ft_free
FREE 	= $(FREE_PATH)/ft_free.a

MINILIBX_PATH	= ../libft/minilibx-linux
MINILIBX		= $(MINILIBX_PATH)/libmlx.a

OBJ_DIR	= ./obj
OBJS	= $(SRCS:%.c=$(OBJ_DIR)/%.o) $(MINIRT_OBJS)

CFLAGS	= -Wall -Wextra -Werror -DUNITY_INCLUDE_DOUBLE -g3 -fPIE
IFLAGS	= -I. -Iunity -I../inc
LDFLAGS	= -L$(LIBFT_PATH) -lft -L$(GNL_PATH) -L$(MINILIBX_PATH) -L$(FREE_PATH) -L$(PRINTF_PATH) -L$(LIST_PATH) -lmlx -lXext -lX11 -lm

VPATH	= unity

all: $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re:  fclean all

$(MINIRT):
	make -C $(MINIRT_PATH)

$(NAME): $(MINIRT) $(OBJS) $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS) $(LIBFT) $(GNL) $(MINILIBX) $(FREE) $(FREE) $(LIST) $(PRINTF)

$(OBJ_DIR)/%.o: %.c $(HEADER) Makefile | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

run: all
	./$(NAME)

val: all
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY:	all clean fclean re run
