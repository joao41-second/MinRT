# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 06:17:31 by jperpect          #+#    #+#              #
#    Updated: 2025/06/18 14:37:20 by rerodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler flags
 #WFLGS = -Wall -Wextra -Werror

#READ_FLG = -g -pg
 READ_FLG =  -O3 -march=native -flto -funroll-loops  -g

MINILIB_FLG = -Llibft/minilibx-linux -lmlx_Linux -lX11 -lXext -lm -Llibft/ft_get_next_line -Llibft/ft_free -Llibft/ft_libft \
	      -Llibft/ft_list
FLGS = $(WFLGS) $(READ_FLG) $(MINILIB_FLG)

VAL = valgrind --leak-check=full  

# Make flags
MAKEFLAGS += -s

# Source files
# SRCS = $(shell find src -name '*.c')
SRCS = src/camara_m/camara_m.c \
       src/camara_m/camara_m_utils.c \
       src/camera/axis_navigator.c \
       src/camera/axis_navigator_lines.c \
       src/camera/axis_navigator_utils.c \
       src/camera/camera.c \
       src/camera/camera_transform.c \
       src/camera/camera_utils.c \
       src/canvas/canvas.c \
       src/canvas/canvas_utils.c \
       src/canvas/colors.c \
       src/canvas/colors_check.c \
       src/canvas/menu/menu.c \
       src/canvas/menu/menu_utils.c \
       src/canvas/menu/menu_utils_helper.c \
       src/light/light.c \
       src/light/light_comp.c \
       src/light/light_lighting.c \
       src/light/lig_norm_obj.c \
       src/light/lig_view_transform.c \
       src/loop/key_loop.c \
       src/loop/key_loop_utils.c \
       src/loop/loop.c \
       src/loop/muose.c \
       src/main.c \
       src/matrix/matrix.c \
       src/matrix/matrix_det.c \
       src/matrix/matrix_func_param.c \
       src/matrix/matrix_invert.c \
       src/matrix/matrix_not_memory/matrix_type_gener.c \
       src/matrix/matrix_not_memory/matrix_type_gener_utils.c \
       src/matrix/matrix_operacion.c \
       src/matrix/matrix_rotation.c \
       src/matrix/matrix_shearing.c \
       src/matrix/matrix_translation.c \
       src/matrix/matrix_updated.c \
       src/matrix/matrix_utils.c \
       src/objects/cylinder.c \
       src/objects/light.c \
       src/objects/matirial.c \
       src/objects/objects.c \
       src/objects/obj_mat_calule.c \
       src/objects/obj_mat_init.c \
       src/objects/plane.c \
       src/objects/sphere.c \
       src/objects/triangle.c \
       src/objects/word_start.c \
       src/parser/parser.c \
       src/parser/parser_elements.c \
       src/parser/parser_utils.c \
       src/ray/rat_loop.c \
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


SRCS_BONUS = src_bonus/camara_m/camara_m.c \
       src_bonus/camara_m/camara_m_utilis.c \
       src_bonus/canvas/canvas.c \
       src_bonus/canvas/canvas_utils.c \
       src_bonus/canvas/colors.c \
       src_bonus/canvas/colors_check.c \
       src_bonus/light/light.c \
       src_bonus/light/light_comp.c \
       src_bonus/light/light_lighting.c \
       src_bonus/light/lig_norm_obj.c \
       src_bonus/light/lig_view_transform.c \
       src_bonus/loop/key_loop.c \
       src_bonus/loop/loop.c \
       src_bonus/loop/muose.c \
       src_bonus/main.c \
       src_bonus/matrix/matrix.c \
       src_bonus/matrix/matrix_det.c \
       src_bonus/matrix/matrix_func_param.c \
       src_bonus/matrix/matrix_invert.c \
       src_bonus/matrix/matrix_not_memory/matrix_type_extra.c \
       src_bonus/matrix/matrix_not_memory/matrix_type_gener.c \
       src_bonus/matrix/matrix_not_memory/matrix_type_utilits.c \
       src_bonus/matrix/matrix_not_memory/mat_set_det.c \
       src_bonus/matrix/matrix_operacion.c \
       src_bonus/matrix/matrix_rotation.c \
       src_bonus/matrix/matrix_shearing.c \
       src_bonus/matrix/matrix_translation.c \
       src_bonus/matrix/matrix_updated.c \
       src_bonus/matrix/matrix_utils.c \
       src_bonus/objects/3d_obj/obj_open_uv_point.c \
       src_bonus/objects/3d_obj/open_obj.c \
       src_bonus/objects/3d_obj/open_obj_extra.c \
       src_bonus/objects/3d_obj/open_obj_utils.c \
       src_bonus/objects/matirial.c \
       src_bonus/objects/obj_calcule/cylinder.c \
       src_bonus/objects/obj_calcule/light.c \
       src_bonus/objects/obj_calcule/plane.c \
       src_bonus/objects/obj_calcule/sphere.c \
       src_bonus/objects/obj_calcule/square.c \
       src_bonus/objects/obj_calcule/triangle.c \
       src_bonus/objects/objects.c \
       src_bonus/objects/obj_mat_calule.c \
       src_bonus/objects/obj_mat_init.c \
       src_bonus/objects/word_start.c \
       src_bonus/parser/parser.c \
       src_bonus/parser/parser_elements.c \
       src_bonus/parser/parser_elements_utils.c \
       src_bonus/parser/parser_sphere_texture.c \
       src_bonus/parser/parser_elements_extra.c\
       src_bonus/parser/parser_utils.c \
       src_bonus/Pattern/stripe.c \
       src_bonus/Pattern/textuers.c \
       src_bonus/Pattern/uv_utilits.c \
       src_bonus/ray/ray.c \
       src_bonus/ray/ray_in_shadow.c \
       src_bonus/ray/ray_limit.c \
       src_bonus/ray/ray_objects_int_cylinder.c \
       src_bonus/ray/ray_objects_int_triangle.c \
       src_bonus/ray/ray_objects_int_word.c \
       src_bonus/ray/ray_objects_logic.c \
       src_bonus/ray/ray_tranform.c \
       src_bonus/tuples/tuples.c \
       src_bonus/tuples/tuples_checkers.c \
       src_bonus/tuples/tuples_manipulations.c \
       src_bonus/tuples/tuples_operations.c

# Object files
OBJDIR = Objs
OBJS = $(patsubst src/%.c,$(OBJDIR)/%.o,$(SRCS))
# Object files
OBJDIR_BONUS = Objs_bonus
OBJS_BONUS = $(patsubst src_bonus/%.c,$(OBJDIR_BONUS)/%.o,$(SRCS_BONUS))

# Libraries
LIB = ./libft/ft_libft/libft.a ./libft/ft_printf/libftprintf.a ./libft/ft_free/ft_free.a ./libft/ft_list/list.a\
./libft/minilibx-linux/libmlx.a ./libft/minilibx-linux/libmlx_Linux.a  ./libft/ft_get_next_line/get_next_line.a\

# Commands
AR = ar rcs
CC = cc
RM = rm -f
CAT = cat number.txt


.DEFAULT_GOAL := all

# Output
NAME = miniRT

# Create object directory if it doesn't exist
$(shell mkdir -p $(OBJDIR))
# Output
NAME_BONUS = miniRT_bonus

# Create object directory if it doesn't exist
$(shell mkdir -p $(OBJDIR_BONUS))

# Compile object files
$(OBJDIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	@$(CC) -c $(WFLGS) $(READ_FLG) -o $@ $<
       
# Compile object bonus files
$(OBJDIR_BONUS)/%.o: src_bonus/%.c
	@mkdir -p $(dir $@)
	@$(CC) -c $(WFLGS) $(READ_FLG) -o $@ $<

# Compile static libraries before linking the final executable
$(LIB):
	git submodule init | git submodule update --init --recursive
	cd libft/ft_free  && make 
	cd libft/ft_libft && make bonus 
	cd libft/ft_printf && make 
	cd libft/ft_get_next_line && make 
	cd libft/ft_list && make 
	cd libft/minilibx-linux && make all

# Main target
$(NAME): $(LIB) $(OBJS)
	$(CC) $(OBJS) $(LIB) $(FLGS) -o $(NAME)
	@echo "╔══════════════════════════╗"
	@echo "║ ✅ Compiled Successfully!║"
	@echo "╚══════════════════════════╝"
# New target to rebuild only the source files

# Main target
$(NAME_BONUS): $(LIB) $(OBJS_BONUS)
	$(CC) $(OBJS_BONUS) $(LIB) $(FLGS) -o $(NAME_BONUS)
	@echo "╔══════════════════════════╗"
	@echo "║ ✅ Compiled bonus Successfully!║"
	@echo "╚══════════════════════════╝"
# New target to rebuild only the source files

all: $(NAME)

renew: $(OBJS)
	$(CC) $(OBJS) $(LIB) $(FLGS) -o $(NAME)
	@echo "╔══════════════════════════╗"
	@echo "║ ✅ Renewed Successfully! ║"
	@echo "╚══════════════════════════╝"


bonus: $(NAME_BONUS)

clean:
	$(RM) -r $(OBJDIR)
	$(RM) -r $(OBJDIR_BONUS)
	cd libft/ft_free  && make fclean
	cd libft/ft_libft && make fclean
	cd libft/ft_printf && make fclean
	cd libft/ft_get_next_line && make fclean
	cd libft/ft_list && make fclean 

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

re: fclean all

re_bonus: fclean bonus

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
	clear && make re && valgrind --leak-check=full --show-leak-kinds=definite ./$(NAME) $(SCENE)
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
# Phony targets
.PHONY: all clean fclean re exec norm normi re_bonus bonus test test_vall s n v e b g t pro pdf
