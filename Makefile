# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 06:17:31 by jperpect          #+#    #+#              #
#    Updated: 2025/06/18 08:50:18 by rerodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler flags
 WFLGS = -Wall -Wextra -Werror
#WFLGS = -Wall -Wextra -Werror

#READ_FLG = -g -pg
 READ_FLG =  -O3 -march=native -flto -funroll-loops  -g -pg

MINILIB_FLG = -Llibft/minilibx-linux -lmlx_Linux -lX11 -lXext -lm -Llibft/ft_get_next_line -Llibft/ft_free -Llibft/ft_libft \
	      -Llibft/ft_list
FLGS = $(WFLGS) $(READ_FLG) $(MINILIB_FLG)

VAL = valgrind --leak-check=full  

# Make flags
MAKEFLAGS += -s

# Source files
# SRCS = $(shell find src -name '*.c')

SRCS = src/camara_m/camara_m.c \
       src/camara_m/camara_m_utilis.c \
       src/canvas/canvas.c \
       src/canvas/canvas_utils.c \
       src/canvas/colors.c \
       src/canvas/colors_check.c \
       src/light/light.c \
       src/light/light_comp.c \
       src/light/light_lighting.c \
       src/light/lig_norm_obj.c \
       src/light/lig_view_transform.c \
       src/loop/key_loop.c \
       src/loop/loop.c \
       src/loop/muose.c \
       src/main.c \
       src/matrix/matrix.c \
       src/matrix/matrix_det.c \
       src/matrix/matrix_func_param.c \
       src/matrix/matrix_invert.c \
       src/matrix/matrix_not_memory/matrix_type_extra.c \
       src/matrix/matrix_not_memory/matrix_type_gener.c \
       src/matrix/matrix_not_memory/matrix_type_utilits.c \
       src/matrix/matrix_not_memory/mat_set_det.c \
       src/matrix/matrix_operacion.c \
       src/matrix/matrix_rotation.c \
       src/matrix/matrix_shearing.c \
       src/matrix/matrix_translation.c \
       src/matrix/matrix_updated.c \
       src/matrix/matrix_utils.c \
       src/objects/3d_obj/obj_open_uv_point.c \
       src/objects/3d_obj/open_obj.c \
       src/objects/3d_obj/open_obj_extra.c \
       src/objects/3d_obj/open_obj_utils.c \
       src/objects/matirial.c \
       src/objects/obj_calcule/cylinder.c \
       src/objects/obj_calcule/light.c \
       src/objects/obj_calcule/plane.c \
       src/objects/obj_calcule/sphere.c \
       src/objects/obj_calcule/square.c \
       src/objects/obj_calcule/triangle.c \
       src/objects/objects.c \
       src/objects/obj_mat_calule.c \
       src/objects/obj_mat_init.c \
       src/objects/word_start.c \
       src/parser/parser.c \
       src/parser/parser_elements.c \
       src/parser/parser_elements_utils.c \
       src/parser/parser_sphere_texture.c \
       src/parser/parser_utils.c \
       src/Pattern/stripe.c \
       src/Pattern/textuers.c \
       src/Pattern/uv_utilits.c \
       src/ray/ray.c \
       src/ray/ray_in_shadow.c \
       src/ray/ray_limit.c \
       src/ray/ray_objects_int_cylinder.c \
       src/ray/ray_objects_int_triangle.c \
       src/ray/ray_objects_int_word.c \
       src/ray/ray_objects_logic.c \
       src/ray/ray_tranform.c \
       src/tuples/tuples.c \
       src/tuples/tuples_checkers.c \
       src/tuples/tuples_manipulations.c \
       src/tuples/tuples_operations.c

# Object files
OBJDIR = Objs
OBJS = $(patsubst src/%.c,$(OBJDIR)/%.o,$(SRCS))

# Libraries
LIB = ./libft/ft_libft/libft.a ./libft/ft_printf/libftprintf.a ./libft/ft_free/ft_free.a ./libft/ft_list/list.a\
./libft/minilibx-linux/libmlx.a ./libft/minilibx-linux/libmlx_Linux.a  ./libft/ft_get_next_line/get_next_line.a\

# Commands
AR = ar rcs
CC = cc
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


SCENE = ./scenes/obj.rt
s:
	clear && make re && ./$(NAME) $(SCENE)
n:
	clear && make renew && ./$(NAME) $(SCENE)
v:
	clear && make re && $(VAL) ./$(NAME)  $(SCENE)
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
