# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rui <rui@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 06:17:31 by jperpect          #+#    #+#              #
#    Updated: 2025/03/19 10:38:54 by jperpct          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler flags
#WFLGS = -Wall -Wextra -Werror
READ_FLG = -g 
MINILIB_FLG = -lX11 -lXext 
FLGS = $(WFLGS) $(READ_FLG) $(MINILIB_FLG)

VAL = valgrind --leak-check=full  
# Make flags
MAKEFLAGS += -s

# Source files
SRCS = $(shell find src -name '*.c')

# Object files
OBJS = $(patsubst src/%.c,$(OBJDIR)/%.o,$(SRCS))

# Libraries
LIB = ./libft/ft_libft/libft.a ./libft/ft_printf/libftprintf.a ./libft/ft_free/ft_free.a \
./libft/minilibx-linux/libmlx.a ./libft/minilibx-linux/libmlx_Linux.a  ./libft/ft_get_next_line/get_next_line.a\

# Commands
AR = ar rcs
CC = cc
RM = rm -f
CAT = cat number.txt

# Output
NAME = miniRT
OBJDIR = Objs

# Create object directory if it doesn't exist
$(shell mkdir -p $(OBJDIR))

$(OBJDIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	@$(CC) -c $(FLGS) -o $@ $<


# Main target
$(NAME): $(OBJS)
	cd libft/ft_free  && make 
	cd libft/ft_libft && make bonus 
	cd libft/ft_printf && make 
	cd libft/ft_get_next_line && make 
	cd libft/minilibx-linux && make
	$(CC) $(FLGS) $(OBJS) $(LIB)  -o $(NAME)
	@echo "╔══════════════════════════╗"
	@echo "║ ✅ Compiled Successfully!║"
	@echo "╚══════════════════════════╝"

# Compile all source files
$(OBJDIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	@$(CC) -c $(FLGS) -o $@ $<

# Phony targets
.PHONY: all clean fclean re exec norm normi

all: $(NAME)

clean:
	$(RM) -r $(OBJDIR)
	cd libft/ft_free  && make clean
	cd libft/ft_libft && make clean
	cd libft/ft_printf && make clean
	cd libft/ft_get_next_line && make clean

fclean: clean
	$(RM) $(NAME)

re: fclean all

s:
	clear && make re && ./$(NAME)
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
