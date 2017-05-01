LIBFT_FILES		= ft_sqrt ft_ceil ft_memalloc ft_strcontains ft_strclen ft_strndup ft_strsplice \
					ft_strnew ft_strlen ft_atoi ft_strdup ft_strcpy ft_strncpy ft_strcat ft_strncat \
					ft_strlcat ft_strchr ft_strrchr ft_strstr ft_strcmp ft_strnstr ft_strncmp ft_isalpha \
					ft_isdigit ft_isalnum ft_isascii ft_toupper ft_tolower ft_isprint ft_memset ft_bzero \
					ft_memcpy ft_memccpy ft_memmove ft_memchr ft_memcmp ft_memdel ft_strdel ft_strclr \
					ft_striter ft_striteri ft_strmap ft_strmapi ft_strequ ft_strnequ ft_strsub ft_strjoin \
					ft_strtrim ft_strsplit ft_putchar ft_putstr ft_putnbr ft_strsplit ft_itoa ft_putendl \
					ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_lstadd ft_lstdel ft_lstdelone \
					ft_lstiter ft_lstmap ft_lstnew ft_memjoin ft_llutoa_base ft_strupcase ft_isnumeric ft_realloc

PRINTF_FILES	= string_utils ft_printf parse_conversion convert_char convert_hexa_octa_int convert_string

GET_NEXT_LINE	= get_next_line

DOTCFILES		= $(addprefix srcs/get_next_line/, $(addsuffix .c, $(GET_NEXT_LINE))) $(addprefix srcs/libft/, $(addsuffix .c, $(LIBFT_FILES))) $(addprefix srcs/printf/, $(addsuffix .c, $(PRINTF_FILES)))
OBJECT_FILES	= $(addprefix build/, $(addsuffix .o, $(GET_NEXT_LINE))) $(addprefix build/, $(addsuffix .o, $(LIBFT_FILES))) $(addprefix build/, $(addsuffix .o, $(PRINTF_FILES)))

NAME			= ../libs/libft.a

CC				= gcc

CFLAGS			= -Wall -Werror -Wextra

AR				= ar rc

RANLIB			= ranlib

INCLUDES		= -I ../includes

.PHONY: all clean fclean re

all: $(NAME)

clean:
		rm -rf build/

fclean: clean
		rm -rf $(NAME)

re: fclean all

build:
		mkdir build/
		mkdir ../libs/
		
build/%.o: srcs/*/%.c | build
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJECT_FILES)
		$(AR) $(NAME) $(OBJECT_FILES)
		$(RANLIB) $(NAME)
