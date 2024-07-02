#	colors	#

BLACK=	$(shell tput -Txterm setaf 0)
RED= 	$(shell tput -Txterm setaf 1)
GREEN= 	$(shell tput -Txterm setaf 2)
WHITE= 	$(shell tput -Txterm setaf 7)
YELLOW=	$(shell tput -Txterm setaf 3)
BLUE=	$(shell tput -Txterm setaf 6)
END= 	$(shell tput -Txterm sgr0)

#			#

NAME = ../checker

CC = cc

FLAGS = -Wall -Werror -Wextra -g3

LIBFT_PATH = ../libft/

LIBFT = libft.a

LIBFT_FILES = $(LIBFT_PATH)*.c

SRC_PATH = .

FILES =		checker.c			\
			finish.c			\
			init.c				\
			parse.c				\
			push.c				\
			reverse_rotate.c	\
			rotate.c			\
			swap.c				\

all	: $(NAME)

$(NAME) : $(LIBFT) $(FILES)
		@$(CC) $(FLAGS) $(FILES) $(LIBFT_PATH)$(LIBFT) -o $(NAME)
		@echo "$(GREEN)checker done ! ✅$(END)"

$(LIBFT) : $(LIBFT_FILES)
		@make -C $(LIBFT_PATH)