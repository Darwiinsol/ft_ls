#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apissier <apissier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/07 10:36:13 by apissier          #+#    #+#              #
#    Updated: 2017/05/15 16:10:47 by apissier         ###   ########.fr        #
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

NAME = libftls.a
FLAGS = -Wall -Werror -Wextra
LIB = ./libft/libft.a
SRCS_NAME = testfunc.c

SRCS_PATH		=		srcs/
SRCS			=		$(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJ_NAME		=		$(SRCS_NAME:.c=.o)
OBJ_PATH		=		obj/
OBJ				=		$(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC				=		./includes/

#COLORS
C_GREEN			=	"\033[33m"
C_END			= 	"\033[0m"

#MESSAGE
SUCCESS			=	SUCCESS$(C_END)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(LOG_CLEAR)$(LOG_BLUE)Make Libft in progress...$(LOG_NOCOLOR)$(LOG_UP)"
	@make -C ./libft/
	@cp libft/libft.a ./$(NAME)
	@echo "$(LOG_CLEAR)$(LOG_GREEN)Make Libft done$(LOG_NOCOLOR)"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(LOG_CLEAR)$(LOG_GREEN)  $@ compilation done$(LOG_NOCOLOR)"

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p obj
	@echo "$(LOG_CLEAR)$(LOG_BLUE)$@ compilation in progress...$(LOG_NOCOLOR)$(LOG_UP)"
	@gcc -c $(FLAGS) -I $(INC) $< -o $@
	@echo "$(LOG_CLEAR)$(LOG_GREEN)  $@ compilation done$(LOG_NOCOLOR)$(LOG_UP)"

exe:
		@make -C ./libft/
		@cc $(SRCS) ./srcs/testfunc.c $(LIB) -o ft_ls
		@echo "$(LOG_CLEAR)$(C_GREEN)"Compiling" [ ft_ls ] $(SUCCESS)"
		@./ft_ls

clean:	
	@make -C ./libft/ fclean
	@/bin/rm -rf $(OBJ_PATH)
	@echo "$(LOG_CLEAR)$(LOG_RED)Clean done$(LOG_NOCOLOR)"

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo "$(LOG_CLEAR)$(LOG_CLEAR)$(LOG_RED)Fclean done$(LOG_NOCOLOR)"

re: fclean all

.PHONY: all clean fclean re
