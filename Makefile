# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/26 16:25:08 by lpaulo-m          #+#    #+#              #
#    Updated: 2022/02/15 10:32:57 by lpaulo-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc
CC_FLAGS = -Wall -Wextra -Werror
CC_DEBUG_FLAGS = -g -fsanitize=address

SYSTEM_LIBS = -lm -lbsd -lmlx -lXext -lX11

MAKE_EXTERNAL = make -C
SAFE_MAKEDIR = mkdir -p
ARCHIVE_AND_INDEX = ar -rcs
COPY = cp

REMOVE = /bin/rm -f
REMOVE_RECURSIVE = /bin/rm -rf

OBJECTS_PATH = ./objects
SOURCES_PATH = ./sources
INCLUDES_PATH = ./includes
LIBS_PATH = ./libs
ARCHIVES_PATH = ./archives
EXAMPLES_PATH = ./examples

HEADER_FILE = fractol.h
HEADER = $(addprefix $(INCLUDES_PATH)/,$(HEADER_FILE))

SOURCE_FILES = \
	complex.c complex_meta.c complex_operations.c mandelbrot.c \
	\
	mlx_init.c mlx_input.c mlx_utils.c \
	\
	errors.c
SOURCES = $(addprefix $(SOURCES_PATH)/,$(SOURCE_FILES))

OBJECTS = $(addprefix $(OBJECTS_PATH)/,$(subst .c,.o,$(SOURCE_FILES)))

FRACTOL_ARCHIVE = $(ARCHIVES_PATH)/fractol.a

REQUIRED_MAIN = $(SOURCES_PATH)/main.c
BONUS_MAIN = $(SOURCES_PATH)/main_bonus.c

################################################################################
# REQUIRED
################################################################################

all: $(NAME)

$(NAME): $(FRACTOL_ARCHIVE)
	$(CC) $(CC_DEBUG_FLAGS) \
		-I $(INCLUDES_PATH) \
		$(REQUIRED_MAIN) $(FRACTOL_ARCHIVE) \
		$(FT_LIBBMP_ARCHIVE) $(LIBFT_ARCHIVE) \
		$(SYSTEM_LIBS) \
		-o $(NAME)

$(FRACTOL_ARCHIVE): build_libft build_ft_libbmp $(OBJECTS) $(HEADER)
	$(ARCHIVE_AND_INDEX) $(FRACTOL_ARCHIVE) $(OBJECTS)

$(OBJECTS_PATH)/%.o: $(SOURCES_PATH)/%.c $(HEADER)
	$(SAFE_MAKEDIR) $(OBJECTS_PATH)
	$(CC) $(CC_FLAGS) -I $(INCLUDES_PATH) -o $@ -c $< $(SYSTEM_LIBS)

required: $(NAME)
	./$(NAME)

clean:
	$(REMOVE) $(OBJECTS)
	$(REMOVE) $(FRACTOL_ARCHIVE)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

################################################################################
# BONUS
################################################################################

################################################################################
# LIBS
################################################################################

LIBFT = libft.a
LIBFT_PATH = $(LIBS_PATH)/libft
LIBFT_ARCHIVE = $(ARCHIVES_PATH)/$(LIBFT)

build_libft:
	$(MAKE_EXTERNAL) $(LIBFT_PATH)
	$(SAFE_MAKEDIR) $(ARCHIVES_PATH)
	$(COPY) $(LIBFT_PATH)/$(LIBFT) $(LIBFT_ARCHIVE)

libft_clean:
	$(MAKE_EXTERNAL) $(LIBFT_PATH) fclean
	$(REMOVE) $(LIBFT_ARCHIVE)

FT_LIBBMP = ft_libbmp.a
FT_LIBBMP_PATH = $(LIBS_PATH)/ft_libbmp
FT_LIBBMP_ARCHIVE = $(ARCHIVES_PATH)/$(FT_LIBBMP)

build_ft_libbmp:
	$(MAKE_EXTERNAL) $(FT_LIBBMP_PATH)
	$(SAFE_MAKEDIR) $(ARCHIVES_PATH)
	$(COPY) $(FT_LIBBMP_PATH)/$(FT_LIBBMP) $(FT_LIBBMP_ARCHIVE)

ft_libbmp_clean:
	$(MAKE_EXTERNAL) $(FT_LIBBMP_PATH) fclean
	$(REMOVE) $(FT_LIBBMP_ARCHIVE)

################################################################################
# EXAMPLE
################################################################################

EXAMPLE_MAIN = $(EXAMPLES_PATH)/example.c
EXECUTE_EXAMPLE = ./a.out
EXAMPLE_GARBAGE = a.out a.out.dSYM

example: build_example
	$(EXECUTE_EXAMPLE)

build_example: $(FRACTOL_ARCHIVE)
	$(CC) $(CC_DEBUG_FLAGS) \
		-I $(INCLUDES_PATH) \
		$(EXAMPLE_MAIN) $(FRACTOL_ARCHIVE) \
		$(FT_LIBBMP_ARCHIVE) $(LIBFT_ARCHIVE) \
		$(SYSTEM_LIBS)

example_clean: fclean
	$(REMOVE_RECURSIVE) $(EXAMPLE_GARBAGE)

################################################################################
# VALGRIND
################################################################################

VALGRIND = valgrind
VALGRIND_LOG = valgrind_leaks.log
VALGRIND_LOG_FLAGS = --log-file=$(VALGRIND_LOG) \
	--leak-check=full \
	--show-leak-kinds=all \
	--track-origins=yes \
	--verbose
VALGRIND_TARGET = ./$(NAME)

vg: $(NAME)
	$(VALGRIND) $(VALGRIND_TARGET)

vglog: $(NAME)
	$(VALGRIND) $(VALGRIND_LOG_FLAGS) $(VALGRIND_TARGET)

vglog_clean: fclean
	$(REMOVE) $(VALGRIND_LOG)

################################################################################
# MISC
################################################################################

norm:
	norminette $(LIBS_PATH)
	@printf "\n$(G)=== No norminette errors found in $(LIBS_PATH) ===$(RC)\n\n"
	norminette $(INCLUDES_PATH)
	@printf "\n$(G)=== No norminette errors found in $(INCLUDES_PATH) ===$(RC)\n\n"
	norminette $(SOURCES_PATH)
	@printf "\n$(G)=== No norminette errors found in $(SOURCES_PATH) ===$(RC)\n\n"

git:
	git add -A
	git commit -m "update"
	git push

gitm:
	git add -A
	git commit -m $m
	git push

################################################################################
# PHONY
################################################################################

.PHONY: all required clean fclean re \
		build_libft libft_clean \
		build_ft_libbmp ft_libbmp_clean \
		build_example example example_clean \
		vg vglog vglog_clean \
		norm git gitm

################################################################################
# Colors
################################################################################

# Black, Red, Green, Yellow, Blue, Purple, Cyan, White
Bk = \033[0;30m
R = \033[0;31m
G = \033[0;32m
Y = \033[0;33m
B = \033[0;34m
P = \033[0;35m
C = \033[0;36m
W = \033[0;37m
# Bold
BkB = \033[1;30m
RB = \033[1;31m
GB = \033[1;32m
YB = \033[1;33m
BB = \033[1;34m
PB = \033[1;35m
CB = \033[1;36m
WB = \033[1;37m
# Reset Color
RC	= \033[0m
