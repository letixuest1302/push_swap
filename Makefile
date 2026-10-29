NAME = push_swap.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = adaptative_sort.c error.c is_sorted.c main.c parse_args.c parse.c Push.c ReverseRotate.c Rotate.c simple_sort.c split_utils.c split.c swap.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re