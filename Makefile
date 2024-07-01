#	colors	#

BLACK=	$(shell tput -Txterm setaf 0)
RED= 	$(shell tput -Txterm setaf 1)
GREEN= 	$(shell tput -Txterm setaf 2)
WHITE= 	$(shell tput -Txterm setaf 7)
YELLOW=	$(shell tput -Txterm setaf 3)
BLUE=	$(shell tput -Txterm setaf 6)
END= 	$(shell tput -Txterm sgr0)

#			#

MANDATORY = push_swap

MANDATORY_PATH = ./mandatory

MANDATORY_FILE = mandatory/cost.c mandatory/commands.h mandatory/finish.c mandatory/init.c mandatory/insert.c mandatory/little_sort.c mandatory/Makefile mandatory/parse.c mandatory/push_swap.c mandatory/push_swap.h mandatory/push.c mandatory/reverse_rotate.c mandatory/sort_tab.c mandatory/rotate.c mandatory/sort_utils.c mandatory/sort.c mandatory/swap.c	\

BONUS = checker

BONUS_PATH = ./bonus

BONUS_FILE = Makefile bonus/swap.c bonus/rotate.c bonus/reverse_rotate.c bonus/push.c bonus/parse.c bonus/Makefile bonus/init.c bonus/finish.c bonus/commands.h bonus/checker.h bonus/checker.c	\

LIBFT_PATH = ./libft/

LIBFT = libft.a

all : $(MANDATORY)

bonus : $(BONUS)

$(MANDATORY) : $(MANDATORY_FILE)
		@make -C $(MANDATORY_PATH)

$(BONUS) : $(BONUS_FILE)
		@make -C $(BONUS_PATH)

clean :
		@make clean -C $(LIBFT_PATH)

fclean : clean
		@make fclean -C $(LIBFT_PATH)
		@rm -f $(MANDATORY)
		@rm -f $(BONUS)
		@echo "$(GREEN)cleaned ! ✅$(END)"

re : fclean all	