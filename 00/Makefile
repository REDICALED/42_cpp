NAME	=	megaphone
CC		=	c++
CFLAGS	=	-std=c++98 -Wall -Wextra -Werror

SRCS	=	megaphone.cpp

all		:	$(NAME)

$(NAME)	:	$(SRCS)
				$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean	:
			@ rm -f $(NAME)

fclean 	:	clean

re 		: 	fclean all

.PHONY	:	all clean fclean re