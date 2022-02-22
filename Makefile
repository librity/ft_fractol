# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/26 16:25:08 by lpaulo-m          #+#    #+#              #
#    Updated: 2022/02/22 13:37:36 by lpaulo-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
FRACTOL_ARCHIVE = $(ARCHIVES_PATH)/fractol.a

CC = gcc
CC_STRICT = $(CC) $(CCF_STRICT) $(CCF_OPTIMIZATION)

CCF_STRICT = -Wall -Wextra -Werror
CCF_OPTIMIZATION = -O3
CCF_DEBUG = -g -fsanitize=address

CCF_LIBS = -lm -lbsd -lmlx -lXext -lX11

MAKE_EXTERNAL = make -C
SAFE_MAKEDIR = mkdir -p
ARCHIVE_AND_INDEX = ar -rcs
COPY = cp

REMOVE = /bin/rm -f
REMOVE_RECURSIVE = /bin/rm -rf

OBJECTS_PATH = ./objects
SOURCES_PATH = ./sources
INCLUDES_PATH = ./includes
ARCHIVES_PATH = ./archives
BITMAPS_PATH = ./bitmaps

FRACTOL_HEADER = $(INCLUDES_PATH)/fractol.h

SOURCES = $(wildcard $(SOURCES_PATH)/**/*.c) $(wildcard $(SOURCES_PATH)/*.c)

OBJECTS = $(patsubst $(SOURCES_PATH)/%.c, $(OBJECTS_PATH)/%.o, $(SOURCES))
OBJECT_DIRECTORIES = $(sort $(dir $(OBJECTS)))

################################################################################
# REQUIRED
################################################################################

REQUIRED_MAIN = ./main.c

all: $(NAME)

$(NAME): $(FRACTOL_ARCHIVE)
	$(CC_STRICT) $(CCF_DEBUG) \
		-I $(INCLUDES_PATH) \
		$(REQUIRED_MAIN) \
		$(FRACTOL_ARCHIVE) $(FT_LIBBMP_ARCHIVE) $(LIBFT_ARCHIVE) \
		$(CCF_LIBS) \
		-o $(NAME)

$(FRACTOL_ARCHIVE): initialize build_libft build_ft_libbmp $(FRACTOL_HEADER) $(OBJECTS)
	$(ARCHIVE_AND_INDEX) $(FRACTOL_ARCHIVE) $(OBJECTS)

$(OBJECTS_PATH)/%.o: $(SOURCES_PATH)/%.c
	$(CC_STRICT) -I $(INCLUDES_PATH) -c -o $@ $<

clean:
	$(REMOVE) $(OBJECTS)
	$(REMOVE) $(FRACTOL_ARCHIVE)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

initialize: $(ARCHIVES_PATH) $(OBJECTS_PATH) $(OBJECT_DIRECTORIES) $(BITMAPS_PATH)

$(ARCHIVES_PATH):
	$(SAFE_MAKEDIR) $@

$(OBJECTS_PATH):
	$(SAFE_MAKEDIR) $@

$(OBJECT_DIRECTORIES):
	$(SAFE_MAKEDIR) $@

$(BITMAPS_PATH):
	$(SAFE_MAKEDIR) $@

################################################################################
# FRACTALS
################################################################################

mbt: re
	./$(NAME) mandelbrot

julia: re
#	 ./$(NAME) julia  0.3       0.4
#	 ./$(NAME) julia  -2.0      0.0
#	 ./$(NAME) julia  -1.0      0.0
#	 ./$(NAME) julia  0.0       0.0
#	 ./$(NAME) julia  1.0       0.0
#	 ./$(NAME) julia  2.0       0.0
#	 ./$(NAME) julia  3.0       0.0
#	 ./$(NAME) julia  1.0       1.0

#	 ./$(NAME) julia  -0.4      0.6
#	 ./$(NAME) julia  0.285     0.0
#	 ./$(NAME) julia  0.285     0.01
#	 ./$(NAME) julia  0.45      0.1428
	 ./$(NAME) julia  -0.70176  -0.3842
#	 ./$(NAME) julia  -0.835    -0.2321
#	 ./$(NAME) julia  -0.8      0.156
#	 ./$(NAME) julia  -0.7269   0.1889
#	 ./$(NAME) julia  0.0       -0.8

############# Dendrite fractal ##############
#	 ./$(NAME) julia  0.0       1.0
########## Douady's rabbit fractal ##########
#	 ./$(NAME) julia  -0.123    0.745
############# San Marco fractal #############
#	 ./$(NAME) julia  -0.75     0.0
############ Siegel disk fractal ############
#	./$(NAME) julia   -0.391    -0.587

newton: re
	./$(NAME) newton

################################################################################
# LIBS
################################################################################

LIBS_PATH = ./libs

LIBFT = libft.a
LIBFT_PATH = $(LIBS_PATH)/libft
LIBFT_ARCHIVE = $(ARCHIVES_PATH)/$(LIBFT)
LIBFT_HEADER = $(LIBFT_PATH)/includes/libft.h

build_libft:
	$(MAKE_EXTERNAL) $(LIBFT_PATH) all
	$(COPY) $(LIBFT_PATH)/$(LIBFT) $(LIBFT_ARCHIVE)
	$(COPY) $(LIBFT_HEADER) $(INCLUDES_PATH)

libft_clean:
	$(MAKE_EXTERNAL) $(LIBFT_PATH) fclean
	$(REMOVE) $(LIBFT_ARCHIVE)

FT_LIBBMP = ft_libbmp.a
FT_LIBBMP_PATH = $(LIBS_PATH)/ft_libbmp
FT_LIBBMP_ARCHIVE = $(ARCHIVES_PATH)/$(FT_LIBBMP)
FT_LIBBMP_HEADER = $(FT_LIBBMP_PATH)/includes/ft_libbmp.h

build_ft_libbmp:
	$(MAKE_EXTERNAL) $(FT_LIBBMP_PATH) all
	$(COPY) $(FT_LIBBMP_PATH)/$(FT_LIBBMP) $(FT_LIBBMP_ARCHIVE)
	$(COPY) $(FT_LIBBMP_HEADER) $(INCLUDES_PATH)

ft_libbmp_clean:
	$(MAKE_EXTERNAL) $(FT_LIBBMP_PATH) fclean
	$(REMOVE) $(FT_LIBBMP_ARCHIVE)

################################################################################
# TESTS
################################################################################

TESTS_PATH = ./tests

TEST_SOURCES = $(wildcard $(TESTS_PATH)/*.c)
CCF_TEST_LIBS = -lrt -lm
EXECUTE_TESTS = ./test

build_tests: re
	$(CC) $(CCF_DEBUG) \
		-I $(INCLUDES_PATH) \
		$(TEST_SOURCES) \
		$(FRACTOL_ARCHIVE) $(FT_LIBBMP_ARCHIVE) $(LIBFT_ARCHIVE) \
		$(CCF_LIBS) $(CCF_TEST_LIBS) \
		-o $(EXECUTE_TESTS)

test: build_tests
	$(EXECUTE_TESTS)

tests_clean:
	$(REMOVE_RECURSIVE) $(EXECUTE_TESTS)

################################################################################
# EXAMPLE
################################################################################

EXAMPLES_PATH = ./examples

EXAMPLE_MAIN = $(EXAMPLES_PATH)/example.c
EXECUTE_EXAMPLE = ./a.out
EXAMPLE_GARBAGE = a.out a.out.dSYM

example: build_example
	$(EXECUTE_EXAMPLE)

build_example: $(FRACTOL_ARCHIVE)
	$(CC) $(CCF_DEBUG) \
		-I $(INCLUDES_PATH) \
		$(EXAMPLE_MAIN) $(FRACTOL_ARCHIVE) \
		$(FT_LIBBMP_ARCHIVE) $(LIBFT_ARCHIVE) \
		$(CCF_LIBS)

example_clean: fclean
	$(REMOVE_RECURSIVE) $(EXAMPLE_GARBAGE)

################################################################################
# VALGRIND
################################################################################

VALGRIND = valgrind
VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all
VALGRIND_LOG = valgrind_leaks.log
VALGRIND_LOG_FLAGS = --log-file=$(VALGRIND_LOG) \
	--leak-check=full \
	--show-leak-kinds=all \
	--track-origins=yes \
	--verbose
VALGRIND_TARGET = ./$(NAME) julia   -0.391    -0.587

vg: vg_build
	$(VALGRIND) $(VALGRIND_FLAGS) $(VALGRIND_TARGET)

vglog: vg_build
	$(VALGRIND) $(VALGRIND_LOG_FLAGS) $(VALGRIND_TARGET)

vg_build: $(FRACTOL_ARCHIVE)
	$(CC_STRICT) \
		-I $(INCLUDES_PATH) \
		$(REQUIRED_MAIN) \
		$(FRACTOL_ARCHIVE) $(FT_LIBBMP_ARCHIVE) $(LIBFT_ARCHIVE) \
		$(CCF_LIBS) \
		-o $(NAME)

vglog_clean: fclean
	$(REMOVE) $(VALGRIND_LOG)

################################################################################
# CLEAN
################################################################################

tclean: clean_libs fclean tests_clean example_clean vglog_clean

clean_libs: libft_clean ft_libbmp_clean

################################################################################
# MISC
################################################################################

norm:
	# norminette $(LIBS_PATH)
	# @printf "\n$(G)=== No norminette errors found in $(LIBS_PATH) ===$(RC)\n\n"
	norminette $(INCLUDES_PATH)
	@printf "\n$(G)=== No norminette errors found in $(INCLUDES_PATH) ===$(RC)\n\n"
	norminette $(SOURCES_PATH)
	@printf "\n$(G)=== No norminette errors found in $(SOURCES_PATH) ===$(RC)\n\n"
	norminette $(REQUIRED_MAIN)
	@printf "\n$(G)=== No norminette errors found in $(REQUIRED_MAIN) ===$(RC)\n\n"

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

.PHONY: all required clean fclean re initialize \
	build_libft libft_clean \
	build_ft_libbmp ft_libbmp_clean \
	build_tests test tests_clean \
	build_example example example_clean \
	vg vglog vg_build vglog_clean \
	tclean clean_libs \
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
