CC	= gcc

FLAGS	= -Wall -Wextra -Werror

NAME	= libftprintf.a

LIBFT	= libft/libft.a

SRCS	= ft_printf.c ft_printf_char.c ft_printf_int.c ft_printf_length.c ft_printf_pointer.c ft_printf_reculsive.c\

OBJS	= $(SRCS:.c=.o)

all	: $(NAME)

$(NAME)	:	$(OBJS) compiler
	    	ar -rcs $(NAME) $(OBJS)

$(OBJS) :	$(SRCS)
			$(CC) $(CFLAGS) -c $^

bonus	:	all

compiler:
		make all -C libft
		@cp $(LIBFT) $(NAME)

clean	:
	rm -f $(OBJS)
	@make clean -C libft

fclean	: clean
	rm -f $(NAME)
	@make fclean -C libft

re	: fclean all

.PHONY	: all clean fclean re bonus
