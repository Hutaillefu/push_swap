PROG1 = checker
PROG2 = push_swap

LIBFT = ./libft
INCLUDES = ./includes

FLAGS = -Wall -Werror -Wextra

CHECKER_FILES = ./srcs/checker.c \
				./srcs/move.c
#PUSH_FILES = ./srcs/push_swap.c

CHECKER_OBJS = $(CHECKER_FILES:.c=.o)

all : $(PROG1)

$(PROG1): 	$(CHECKER_OBJS)
	make -C $(LIBFT)
	gcc $(FLAGS) -o $(PROG1) -I $(INCLUDES) $(CHECKER_OBJS) $(LIBFT)/libft.a

%.o : %.c
	gcc $(FLAGS) -o $@ -c $< -I $(INCLUDES)

clean:
	make -C $(LIBFT) clean
	rm -rf $(CHECKER_OBJS)

fclean: clean
	make -C $(LIBFT) fclean
	rm -rf $(PROG1)

re: fclean all