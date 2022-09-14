NAME = push_swap

CFILES = 	main.c\
			ft_free_all.c\
			ft_input.c\
			ft_lst_functions.c\
			ft_sort.c\
			other_functions_1.c\
			push.c\
			radix.c\
			reverse_rotate.c\
			rotate.c\
			swap.c\

OBJECTS = $(CFILES:.c=.o)

LIB_PATH = libft/

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: subsystem $(NAME)

subsystem:
	make -C $(LIB_PATH) all

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIB_PATH)libft.a -o $(NAME)

clean:
	make -C $(LIB_PATH) clean
	rm -f $(OBJECTS)

fclean: clean
	make -C $(LIB_PATH) fclean
	rm -f $(NAME)

re: fclean all

call: all clean
	make -C $(LIB_PATH) fclean

test: all
	./push_swap $(v) | ./checker $(v)
	./push_swap $(v) | wc -l

testv: all
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all --show-reachable=yes  ./push_swap $(v) | ./checker $(v)
	./push_swap $(v) | wc -l