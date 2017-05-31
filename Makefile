#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apissier <apissier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/07 10:36:13 by apissier          #+#    #+#              #
#    Updated: 2017/05/31 11:59:39 by apissier         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

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

NAME = libft_ls.a
FLAGS = -Wall -Werror -Wextra
LIB = ./libft/libft.a
SRCS_NAME = ft_sort.c \
			ft_get_info.c

SRCS_PATH		=		srcs/
SRCS			=		$(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJ_NAME		=		$(SRCS_NAME:.c=.o)
OBJ_PATH		=		obj/
OBJ				=		$(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC				=		./includes/

SUCCESS			=	SUCCESS$(LOG_NOCOLOR)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(LOG_CLEAR)$(LOG_BLUE)Make Libft in progress...$(LOG_NOCOLOR)$(LOG_UP)"
	@make -C ./libft/
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(LOG_CLEAR)$(LOG_GREEN)  $@ [compilation success]$(LOG_NOCOLOR)"

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p obj
	@echo "$(LOG_CLEAR)$(LOG_BLUE)$@ compilation in progress...$(LOG_NOCOLOR)$(LOG_UP)"
	@gcc -c $(FLAGS) -I $(INC) $< -o $@
	@echo "$(LOG_CLEAR)$(LOG_GREEN)  $@ [compilation success]$(LOG_NOCOLOR)$(LOG_UP)"

exe:
		@make -C ./libft/
		@cc $(SRCS) ./srcs/ft_ls.c $(LIB) -o ft_ls
		@echo "$(LOG_CLEAR)$(LOG_GREEN)"Compiling" [ ft_ls ] $(SUCCESS)"
		@./ft_ls

clean:	
	@make -C ./libft/ fclean
	@/bin/rm -rf $(OBJ_PATH)
	@echo "$(LOG_CLEAR)ft_ls : $(LOG_RED)Clean -> $(LOG_GREEN)[done]$(LOG_NOCOLOR)"

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo "$(LOG_CLEAR)$(LOG_CLEAR)ft_ls : $(LOG_RED)Fclean -> $(LOG_GREEN)[done]$(LOG_NOCOLOR)"

re: fclean all

.PHONY: all clean fclean re
