CHECKER			= checker
PUSH_SWAP		= push_swap

UTIL_FILES		= checker_utils dynamic_move_history push_swap_utils ring_buffer_arr two_stacks move_seqs data_structure_utils push_swap_util_four push_swap_util_three push_swap_util_two ring_buffer_api ring_buffer_helpers split_whitespaces str_arr stupid_sort stupid_sort_utils stupid_sort_utils_two two_stacks_util_one two_stacks_util_two two_stacks_util_three validators


DOTCFILES		= $(addprefix srcs/, $(addsuffix .c, $(UTIL_FILES)))
OBJECT_FILES	= $(addprefix build/, $(addsuffix .o, $(UTIL_FILES)))

CHECKER_C_FILES	= $(addprefix srcs/, $(addsuffix .c, $(CHECKER)))
PUSHSWP_C_FILES	= $(addprefix srcs/, $(addsuffix .c, $(PUSH_SWAP)))

CHECKER_O_FILES	= $(addprefix build/, $(addsuffix .o, $(CHECKER)))
PUSHSWP_O_FILES	= $(addprefix build/, $(addsuffix .o, $(PUSH_SWAP)))

CC				= gcc

CFLAGS			= -Wall -Werror -Wextra

INCLUDES		= -I includes

LIBS			= libs/libft.a

.PHONY: all clean fclean re

all: $(CHECKER) $(PUSH_SWAP) 

clean:
		rm -rf build/
		make -C libft clean

fclean: clean
		rm -rf $(CHECKER) $(PUSH_SWAP)
		rm -rf libs
		make -C libft fclean

re: fclean all

build:
		make -C libft
		mkdir build/
		
build/%.o: srcs/%.c | build
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(CHECKER): $(OBJECT_FILES) $(CHECKER_O_FILES)
		$(CC) $(CFLAGS) $(INCLUDES) -o $(CHECKER) $(DOTCFILES) $(CHECKER_C_FILES) $(LIBS)

$(PUSH_SWAP): $(OBJECT_FILES) $(PUSHSWP_O_FILES)
		$(CC) $(CFLAGS) $(INCLUDES) -o $(PUSH_SWAP) $(DOTCFILES) $(PUSHSWP_C_FILES) $(LIBS)