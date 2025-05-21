# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 06:17:31 by jperpect          #+#    #+#              #
#    Updated: 2025/05/21 21:49:55 by jperpct          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler flags
# WFLGS = -Wall -Wextra -Werror
#WFLGS = -Wall -Wextra -Werror

READ_FLG = -g
# READ_FLG =  -O3 -march=native -flto -funroll-loops  -g -pg

MINILIB_FLG = -Llibft/minilibx-linux -lmlx_Linux -lX11 -lXext -lm -Llibft/ft_get_next_line -Llibft/ft_free -Llibft/ft_libft \
	      -Llibft/ft_list
FLGS = $(WFLGS) $(READ_FLG) $(MINILIB_FLG)

VAL = valgrind --leak-check=full  

# Make flags
MAKEFLAGS += -s

# Source files
SRCS = $(shell find src -name '*.c')

# Object files
OBJDIR = Objs
OBJS = $(patsubst src/%.c,$(OBJDIR)/%.o,$(SRCS))

# Libraries
LIB = ./libft/ft_libft/libft.a ./libft/ft_printf/libftprintf.a ./libft/ft_free/ft_free.a ./libft/ft_list/list.a\
./libft/minilibx-linux/libmlx.a ./libft/minilibx-linux/libmlx_Linux.a  ./libft/ft_get_next_line/get_next_line.a\

# Commands
AR = ar rcs
CC = gcc
RM = rm -f
CAT = cat number.txt

# Output
NAME = miniRT

# Create object directory if it doesn't exist
$(shell mkdir -p $(OBJDIR))

# Compile object files
$(OBJDIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	@$(CC) -c $(WFLGS) $(READ_FLG) -o $@ $<

# Compile static libraries before linking the final executable
$(LIB):
	cd libft/ft_free  && make 
	cd libft/ft_libft && make bonus 
	cd libft/ft_printf && make 
	cd libft/ft_get_next_line && make 
	cd libft/ft_list && make 
	cd libft/minilibx-linux && make

# Main target
$(NAME): $(LIB) $(OBJS)
	$(CC) $(OBJS) $(LIB) $(FLGS) -o $(NAME)
	@echo "╔══════════════════════════╗"
	@echo "║ ✅ Compiled Successfully!║"
	@echo "╚══════════════════════════╝"
# New target to rebuild only the source files

renew: $(OBJS)
	$(CC) $(OBJS) $(LIB) $(FLGS) -o $(NAME)
	@echo "╔══════════════════════════╗"
	@echo "║ ✅ Renewed Successfully! ║"
	@echo "╚══════════════════════════╝"

# Phony targets
.PHONY: all clean fclean re exec norm normi

all: $(NAME)

clean:
	$(RM) -r $(OBJDIR)
	cd libft/ft_free  && make clean
	cd libft/ft_libft && make clean
	cd libft/ft_printf && make clean
	cd libft/ft_get_next_line && make clean
	cd libft/minilibx-linux && make clean
	cd libft/ft_list && make clean 

fclean: clean
	$(RM) $(NAME)

re: fclean all

# Test target
test: $(LIB) $(OBJS)
	$(CC) $(OBJS) $(LIB) $(FLGS) -o $(NAME)_test
	@echo "╔══════════════════════════╗"
	@echo "║ ✅ Test Compiled Successfully!║"
	@echo "╚══════════════════════════╝"
	make run -C tests

test_vall: all
	make val -C tests


s:
	clear && make re && ./$(NAME)
n:
	clear && make renew && ./$(NAME)
v:
	clear && make re && $(VAL) ./$(NAME)
e:
	make re && env -i ./$(NAME)
b:
	tmux \; split-window -h \; send-keys 'bash' C-m \; select-pane -t 1 \; send-keys 'make s' C-m \; setw synchronize-panes on
g:
	clear && gdb -tui ./$(NAME)
t:
	make re && cd ./minishell_tester  && ./tester

pro:
	gprof ./miniRT gmon.out > test.out && cat test.out

pdf:
	cd ~/Downloads/ && evince JamisBuck-TheRayTracer.pdf
