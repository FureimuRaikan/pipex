# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 13:55:10 by fureimu           #+#    #+#              #
#    Updated: 2025/01/28 16:29:21 by fureimu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= pipex
ARGS = test \"ls -l\" \"wc\" test2

SRC_DIR= srcs/
INC_DIR= includes/
OBJ_DIR= obj/
LIBFT_DIR= libft/

FILES= main.c checks.c init.c 

OBJ= $(addprefix $(OBJ_DIR), $(FILES:.c=.o))

CC = cc
CFLAGS = -Werror -Wextra -Wall -g3
INC = -I $(INC_DIR) -I $(addprefix $(LIBFT_DIR), $(INC_DIR))

DEFAULT = \033[0m
DEF_COLOR = \033[0;90m
WHITE = \033[1;37m
GREEN = \033[0;92m
YELLOW = \033[0;93m
CYAN = \033[0;96m

all : $(NAME)

$(NAME) : $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(INC) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled !$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "$(CYAN)$(NAME) objects files cleaned !$(DEF_COLOR)"

fclean : clean
	@make -C $(LIBFT_DIR) fclean
	@rm -rf $(NAME)
	@echo "$(CYAN)$(NAME) and its objects files cleaned !$(DEF_COLOR)"

re: fclean all
	@echo "$(GREEN)$(NAME) succesfully rebuilt !$(DEF_COLOR)"

go: all
	@echo "$(CYAN) ./$(NAME) $(ARGS)$(WHITE)"
	@./$(NAME) $(ARGS)

debug: all
	@echo "$(CYAN) lldb ./$(NAME) $(WHITE)"
	@ lldb ./$(NAME) $(ARGS)

gov: all
	@echo "$(CYAN) valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(ARGS)$(WHITE)"
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(ARGS)

.PHONY : all clean fclean re go gov debug