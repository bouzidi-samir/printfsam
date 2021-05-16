NAME = libftprintf.a

SRCS = ft_printf.c ft_parsing.c ft_convert.c utile.c ft_convert2.c \
	ft_convert3.c print_flags.c	

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBFT = cd libft/ && make

all: $(NAME)

$(NAME): libft $(OBJS) 
		ar -rcs $(NAME) $(OBJS)

.c.o: 
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
		rm -f $(OBJS)
		$(LIBFT) clean

fclean: clean
		rm $(NAME)
		$(LIBFT) fclean

re: fclean all

libft: 
	$(LIBFT) 
	cp libft/libft.a $(NAME)

.PHONY:	$(NAME) all clean fclean re libft
