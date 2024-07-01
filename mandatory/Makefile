#	colors	#

BLACK=	$(shell tput -Txterm setaf 0)
RED= 	$(shell tput -Txterm setaf 1)
GREEN= 	$(shell tput -Txterm setaf 2)
WHITE= 	$(shell tput -Txterm setaf 7)
YELLOW=	$(shell tput -Txterm setaf 3)
BLUE=	$(shell tput -Txterm setaf 6)
END= 	$(shell tput -Txterm sgr0)

#			#

NAME = ../push_swap

CC = cc

FLAGS = -Wall -Werror -Wextra -g3

LIBFT_PATH = ../libft/

LIBFT = libft.a

LIBFT_FILES = $(LIBFT_PATH)*.c

SRC_PATH = .

FILES = 	cost.c	\
			finish.c	\
			init.c	\
			insert.c	\
			little_sort.c	\
			push_swap.c	\
			parse.c	\
			push.c	\
			reverse_rotate.c	\
			rotate.c	\
			sort_tab.c	\
			sort_utils.c	\
			sort.c	\
			swap.c	\

all : $(NAME)

$(NAME) : $(LIBFT) $(FILES)
		@$(CC) $(FLAGS) $(FILES) $(LIBFT_PATH)$(LIBFT) -o $(NAME)
		@echo "$(GREEN)push_swap done ! ✅$(END)"

$(LIBFT) : $(LIBFT_FILES)
		@make -C $(LIBFT_PATH)