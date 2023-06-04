NAME = push_swap
BONUS_NAME = checker

SRCS = ./src/main.c \
	./src/operations/push_stack.c ./src/operations/reverse_rotate_s.c ./src/operations/rotate_stack.c \
	./src/operations/swap_stack.c ./src/sorting/sort_small.c ./src/sorting/sort.c \
	./src/utils/stack_comp.c ./src/utils/cost.c ./src/utils/errors.c ./src/utils/init.c \
	./src/utils/input.c ./src/utils/movements.c ./src/utils/pos.c ./src/utils/utils.c \
	./src/utils/utils1.c ./src/utils/split.c ./bonus/get_next_line/get_next_line.c \
	./bonus/get_next_line/get_next_line_utils.c

SRC_B = ./bonus/checker.c ./bonus/checker_utils.c

RM = rm -f

INCS	= -I ./includes/

CC = gcc

FLAGS = -g -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

OBJ_B = $(SRC_B:.c=.o)

$(NAME):	$(OBJS)
		@${CC} $(FLAGS) $(SRCS) -o push_swap

all: $(NAME)

clean:
		@$(RM) $(OBJS) $(BONUSOBJS)

fclean: clean
		$(RM) $(NAME) $(BONUS_NAME) ./bonus/$(BONUS_NAME) ./push_swap

re: fclean all

bonus: $(OBJ_B)
		@${CC} $(FLAGS) $(SRCS) $(SRC_B) -o checker

.PHONY : all clean fclean re
