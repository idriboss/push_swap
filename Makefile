#	colors	#

BLACK=	$(shell tput -Txterm setaf 0)
RED= 	$(shell tput -Txterm setaf 1)
GREEN= 	$(shell tput -Txterm setaf 2)
WHITE= 	$(shell tput -Txterm setaf 7)
YELLOW=	$(shell tput -Txterm setaf 3)
BLUE=	$(shell tput -Txterm setaf 6)
END= 	$(shell tput -Txterm sgr0)

#			#

NAME = push_swap

CC = cc

FLAGS = -Wall -Werror -Wextra -g3

LIBFT_PATH = ./libft/

LIBFT = libft.a

LIBFT_FILES = $(LIBFT_PATH)*.c

SRC_PATH = .

FILES = 	$(wildcard $(SRC_PATH)/*.c)	\

all : $(NAME)

$(NAME) : $(LIBFT) $(FILES)
		@$(CC) $(FLAGS) $(FILES) $(LIBFT_PATH)$(LIBFT) -o $(NAME)
		@echo "$(GREEN)$(NAME) done ✅$(END)"

$(LIBFT) : $(LIBFT_FILES)
		@make -C $(LIBFT_PATH)

clean :
		@make clean -C $(LIBFT_PATH)

fclean : clean
		@make fclean -C $(LIBFT_PATH)
		@rm $(NAME)
		@echo "$(RED)$(NAME) deleted$(END)"

re : fclean all	