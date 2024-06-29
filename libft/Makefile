#	colors	#

BLACK=	$(shell tput -Txterm setaf 0)
RED= 	$(shell tput -Txterm setaf 1)
GREEN= 	$(shell tput -Txterm setaf 2)
WHITE= 	$(shell tput -Txterm setaf 7)
YELLOW=	$(shell tput -Txterm setaf 3)
BLUE=	$(shell tput -Txterm setaf 6)
END= 	$(shell tput -Txterm sgr0)

#			#


SRCS =	$(wildcard *.c)			\

NAME = libft.a
LIBS = libft.h ft_printf.h get_next_line.h
OBJS_DIR = objs/
OBJS = $(SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

CC = cc

CC_FLAGS = -Wall -Wextra -Werror -fPIE -g3

all: $(NAME)

$(OBJS_DIR)%.o : %.c $(LIBS)
	@mkdir -p $(OBJS_DIR)
	@echo "$(BLUE)Compiling: $<$(END)"
	@$(CC) $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJECTS_PREFIXED) $(SRCS)
	@ar r $(NAME) $(OBJECTS_PREFIXED)
	@echo "$(GREEN)Libft Done ! ✅$(END)"

clean:
	@rm -rf $(OBJS_DIR)
	@echo "$(RED)remove objects$(END)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)remove $(NAME)$(END)"

re: fclean all