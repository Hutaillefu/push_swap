PROG1 = checker
PROG2 = push_swap

LIBFT = ./libft
INCLUDES = ./includes

FLAGS = -Wall -Werror -Wextra

TOOLS_FILES = 	./srcs/move.c	\
				./srcs/tools.c \
				./srcs/int_list_tools.c

PUSH_FILE = ./srcs/push_swap.c
CHECK_FILE = ./srcs/checker.c


TOOLS_OBJS = $(TOOLS_FILES:.c=.o)
PUSH_OBJ = $(PUSH_FILE:.c=.o)
CHECK_OBJ = $(CHECK_FILE:.c=.o)

all : $(PROG1)

$(PROG1): $(TOOLS_OBJS) $(CHECK_OBJ) $(PUSH_OBJ)
	make -C $(LIBFT)
	gcc $(FLAGS) -o $(PROG1) -I $(INCLUDES) $(TOOLS_OBJS) $(CHECK_OBJ) $(LIBFT)/libft.a
	gcc $(FLAGS) -o $(PROG2) -I $(INCLUDES) $(TOOLS_OBJS) $(PUSH_OBJ) $(LIBFT)/libft.a

%.o : %.c
	gcc $(FLAGS) -o $@ -c $< -I $(INCLUDES)

clean:
	make -C $(LIBFT) clean
	rm -rf $(TOOLS_OBJS)
	rm -rf $(PUSH_OBJ)
	rm -rf $(CHECK_OBJ)

fclean: clean
	make -C $(LIBFT) fclean
	rm -rf $(PROG1)
	rm -rf $(PROG2)

re: fclean all
