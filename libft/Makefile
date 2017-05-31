# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apissier <apissier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/23 17:55:27 by apissier          #+#    #+#              #
#    Updated: 2017/05/23 10:23:54 by apissier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LOG_CLEAR       = \033[2K
LOG_UP          = \033[A
LOG_NOCOLOR     = \033[0m
LOG_BOLD        = \033[1m
LOG_UNDERLINE   = \033[4m
LOG_BLINKING    = \033[5m
LOG_BLACK       = \033[1;30m
LOG_RED         = \033[1;31m
LOG_GREEN       = \033[1;32m
LOG_YELLOW      = \033[1;33m
LOG_BLUE        = \033[1;34m
LOG_VIOLET      = \033[1;35m
LOG_CYAN        = \033[1;36m
LOG_WHITE       = \033[1;37m

NAME = libft.a
CFLAGS += -Wall -Wextra -Werror
CC = @cc
SRC_NAME = ft_atoi.c \
	ft_bzero.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_lstadd.c \
	ft_lstdel.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lstaddend.c \
	ft_memalloc.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memdel.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar.c \
	ft_putchar_fd.c \
	ft_putendl.c \
	ft_putendl_fd.c \
	ft_putnbr.c \
	ft_putnbr_fd.c \
	ft_putstr.c \
	ft_putstr_fd.c \
	ft_sort_ascii.c \
	ft_sort_r_ascii.c \
	ft_strcat.c \
	ft_strchr.c \
	ft_strclr.c \
	ft_strcmp.c \
	ft_strcpy.c \
	ft_strdel.c \
	ft_strdup.c \
	ft_strequ.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strnjoin.c \
	ft_strjoinffre.c \
	ft_strjoinfree.c \
	ft_strlcat.c \
	ft_strlen.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strncat.c \
	ft_strncmp.c \
	ft_strncpy.c \
	ft_strnequ.c \
	ft_strnew.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strsplit.c \
	ft_strstr.c \
	ft_strsub.c \
	ft_strtrim.c \
	ft_tolower.c \
	ft_write_null.c \
	ft_toupper.c \
	ft_printf.c \
    ft_check.c \
    ft_check2.c \
    ft_length_modifier.c \
    ft_check_if_flags_int.c \
    ft_size_lenght_int.c \
    ft_size_lenght_str.c \
    ft_size_prec_int.c \
    ft_size_prec_str.c \
    ft_size_prec_uni.c \
    ft_join_lenght_int.c \
    ft_join_flags_int.c \
    ftf_join_flags.c \
    ft_is_blank.c \
    ft_is_plus.c \
    ft_strchar.c \
    ft_printf_char.c \
    ft_printf_hexa.c \
    ft_printf_octal.c \
    ft_printf_unsigned.c \
    ft_printf_percent.c \
    ft_printf_unicode.c \
    ft_check_flags_str.c \
    ft_printf_pointer.c \
    ft_printf_string.c \
    ft_free_return.c \
    ft_printf_di.c \
	get_next_line.c

SRCS_PATH       =       srcs/
SRCS            =       $(addprefix $(SRCS_PATH), $(SRC_NAME))
OBJ_NAME        =       $(SRC_NAME:.c=.o)
OBJ_PATH        =       obj/
OBJ             =       $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC             =       ./includes/

all: $(NAME)

$(NAME): $(OBJ)
		@echo "$(LOG_CLEAR)$(LOG_BLUE)Make Libft in progress...$(LOG_NOCOLOR)$(LOG_UP)"
	    @ar rcs $(NAME) $(OBJ)
		@ranlib $(NAME)
		@echo "$(LOG_CLEAR)$(LOG_GREEN)  $@ [compilation success]$(LOG_NOCOLOR)"

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
		@mkdir -p obj
		@echo "$(LOG_CLEAR)$(LOG_BLUE)$@ compilation in progress...$(LOG_NOCOLOR)$(LOG_UP)"
		@gcc -c $(FLAGS) -I $(INC) $< -o $@
		@echo "$(LOG_CLEAR)$(LOG_GREEN)  $@ [compilation success]$(LOG_NOCOLOR)$(LOG_UP)"

clean:
		@/bin/rm -rf $(OBJ_PATH)
		@echo "$(LOG_CLEAR)Libft : $(LOG_RED)Clean -> $(LOG_GREEN)[done]$(LOG_NOCOLOR)"

fclean: clean
		@/bin/rm -rf $(NAME)
		@echo "$(LOG_CLEAR)$(LOG_CLEAR)Libft : $(LOG_RED)Fclean -> $(LOG_GREEN)[done]$(LOG_NOCOLOR)"

re: fclean all

.PHONY: all clean fclean re