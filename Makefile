# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rui <rui@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 06:17:31 by jperpect          #+#    #+#              #
#    Updated: 2025/03/12 13:48:52 by jperpct          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler flags
#WFLGS = -Wall -Wextra -Werror
READ_FLG = -g 
MINILIB_FLG = -Lminilibx-linux -lmlx_Linux -lX11 -lXext 
FLGS = $(WFLGS) $(READ_FLG) $(MINILIB_FLG)

VAL = valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --trace-children=yes --suppressions=readline.supp 

# Make flags
MAKEFLAGS += -s

# Source files
SRCS = $(shell find src -name '*.c')

# Object files
OBJS = $(patsubst src/%.c,$(OBJDIR)/%.o,$(SRCS))

# Libraries
LIB = ./libft/libft.a ./libft/libftprintf.a ./libft/get_next_line.a 

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
	cd libft && make compile && make	
	rm -fr minilibx-linux
	git clone https://github.com/42paris/minilibx-linux.git	&& cd minilibx-linux  && make 
	$(CC) $(FLGS) $(OBJS) $(LIB) -lreadline -o $(NAME)
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
	cd ./libft && make clean

fclean: clean
	$(RM) $(NAME)

re: fclean all

s:
	clear && make re && ./minishell
v:
	clear && make re && $(VAL) ./minishell
e:
	make re && env -i ./minishell
b:
	tmux \; split-window -h \; send-keys 'bash' C-m \; select-pane -t 1 \; send-keys 'make s' C-m \; setw synchronize-panes on
g:
	clear && gdb -tui ./minishell
t:
	make re && cd ./minishell_tester  && ./tester
