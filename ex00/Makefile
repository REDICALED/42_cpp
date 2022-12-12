NAME	=	megaphone
CC		=	c++
CXXFLAGS	=	-std=c++98 -Wall -Wextra -Werror

SRC		=	megaphone.cpp
OBJ		=	$(SRC:.cpp=.o)

all		:	$(NAME)

%.o	: 	%.cpp
	$(CC) $(CXXFLAGS) -c $<

$(NAME)	:	$(OBJ)
	$(CC) $(CXXFLAGS) $(OBJ) -o megaphone

clean	:
	rm -rf $(OBJ)

fclean 	:	clean
	rm -rf $(NAME)

re 		: 	fclean all

.PHONY	:	all clean fclean re