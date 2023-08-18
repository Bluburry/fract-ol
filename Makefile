# shortcuts
NAME		= fractol
LIBFT_FLDR 	= lib
LIBFT		= $(addprefix $(LIBFT_FLDR)/, libft.a)
MLX_FLDR	= minilibx-linux
MLX			= $(addprefix $(MLX_FLDR)/, libmlx_Linux.a)
DEPS		= includes/


# flags
CC			= cc
CFLAGS 		= -Wall -Werror -Wextra -g
NODIRS		= --no-print-directory
RM 			= rm -rf
AR 			= ar -rcs
MLX_FLAGS	= -L ./$(MLX_FLDR) -lmlx -Ilmlx -lXext -lX11 -lm 


# folders
OUTPUT			= out
SRCS			= src
MAIN			= $(addprefix $(SRCS)/, main.c)
_SRC_FLDRS		= $(addprefix $(SRCS)/, fractals) $(addprefix $(SRCS)/, hooks) \
	$(addprefix $(SRCS)/, utils) $(addprefix $(SRCS)/, color)
_FRACTALS		= julia mandelbrot
_FOLDERS		= $(SRC) $(_SRC_FLDRS)

VPATH	= $(_FOLDERS)


# files
_HOOKS		= key_hooks mouse_hooks close_window
_FRACTAL	= mandels mandel_vars julia
_UTILS		= scale_nums change_params respond_launch_params default_params
_COLOR		= color_change color_handle

_FILES		= $(_HOOKS) $(_FRACTAL)	$(_UTILS) $(_COLOR)
OBJS		= $(_FILES:%=%.o)
TARGET		= $(addprefix $(OUTPUT)/, $(OBJS))


all : $(NAME)

$(NAME) : $(OUTPUT) $(TARGET)
	$(MAKE) $(NODIRS) -C $(LIBFT_FLDR)
	$(MAKE) $(NODIRS) -C $(MLX_FLDR)
	$(CC) $(CFLAGS) -lm $(MAIN) $(TARGET) $(LIBFT) $(MLX_FLAGS) -o $(NAME) -I $(DEPS)

$(OUTPUT)/%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OUTPUT) : 
	mkdir -p $(OUTPUT)


clean :
	$(MAKE) clean $(NODIRS) -C $(LIBFT_FLDR)
	$(MAKE) clean $(NODIRS) -C $(MLX_FLDR)
	$(RM) $(OUTPUT)

fclean :
	$(MAKE) fclean $(NODIRS) -C ./lib
	$(MAKE) clean $(NODIRS) -C $(MLX_FLDR)
	$(RM) $(NAME) $(OUTPUT)

re : fclean all

# extra makefile rules

.SILENT:

.PHONY : all, clean, fclean, re
