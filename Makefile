# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uolle <uolle@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/14 22:34:57 by uolle             #+#    #+#              #
#    Updated: 2024/01/23 18:36:58 by uolle            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -- Variables
HDRDIR       = includes
BONUSDIR     = bonus
SRCSDIR      = srcs
LIBSDIR      = libs
OBJDIR       = objs

SRC_FILES = $(wildcard $(SRCSDIR)/*.c)
OBJ_FILES = $(patsubst $(SRCSDIR)/%.c,$(OBJDIR)/%.o,$(SRC_FILES))

BONUS_SRC_FILES = $(wildcard $(BONUSDIR)/*.c)
BONUS_OBJ_FILES = $(patsubst $(BONUSDIR)/%.c,$(OBJDIR)/%.o,$(BONUS_SRC_FILES))

CC = cc
C_FLAGS = -Werror -Wall -Wextra
HDR_FLAG = includes/fractol.h
INC_FLAGS = -I $(HDRDIR)
LIBS_FLAG = -L $(LIBSDIR)/libft\
						 -L $(LIBSDIR)/minilibx
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

RM = rm -rf
MKDIR = mkdir -p

NAME = fractol

COLOR_RESET = \033[0m
COLOR_INFO = \033[0;94m
COLOR_SUCCESS = \033[0;92m

.PHONY: all clean fclean re libs bonus

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@echo "$(COLOR_INFO)Linking: $(NAME) $(COLOR_RESET)"
	@$(CC) $(C_FLAGS) $(OBJ_FILES) $(LIBS_FLAG) -lft $(MLX_FLAGS) -o $(NAME)
	@echo "$(COLOR_SUCCESS)$(NAME) has been successfully compiled$(COLOR_RESET)"

$(OBJDIR)/%.o: $(SRCSDIR)/%.c $(HDR_FLAG) | $(OBJDIR) libs
	@echo "$(COLOR_INFO)Compiling: $< $(COLOR_RESET)"
	@$(CC) $(C_FLAGS) $(INC_FLAGS) -c $< -o $@

bonus: $(BONUS_OBJ_FILES)
	@echo "$(COLOR_INFO)Linking: bonus $(COLOR_RESET)"
	@$(CC) $(C_FLAGS) $(BONUS_OBJ_FILES) $(LIBS_FLAG) -lft $(MLX_FLAGS) -o fractol
	@echo "$(COLOR_SUCCESS)bonus has been successfully compiled$(COLOR_RESET)"

$(OBJDIR)/%.o: $(BONUSDIR)/%.c $(HDR_FLAG) | $(OBJDIR) libs
	@echo "$(COLOR_INFO)Compiling: $< $(COLOR_RESET)"
	@$(CC) $(C_FLAGS) $(INC_FLAGS) -c $< -o $@

$(OBJDIR):
	@$(MKDIR) $(OBJDIR)

libs:
	@make -C $(LIBSDIR)/minilibx
	@make -C $(LIBSDIR)/libft

clean:
	@$(RM) $(OBJDIR)
	@make clean -C $(LIBSDIR)/libft
	@make clean -C $(LIBSDIR)/minilibx
	@echo "$(COLOR_INFO)$(NAME) object files cleaned!$(COLOR_RESET)"

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBSDIR)/libft
	@echo "$(COLOR_SUCCESS)$(NAME) executable has been cleaned!$(COLOR_RESET)"

re: fclean all
	@echo "$(COLOR_SUCCESS)Cleaned and rebuilt successfully!$(COLOR_RESET)"

re_bonus: fclean bonus
	@echo "$(COLOR_SUCCESS)Cleaned and rebuilt successfully!$(COLOR_RESET)"
