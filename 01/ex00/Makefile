NAME	=	MAP
CC		=	c++
CXXFLAGS	=	-std=c++98 -Wall -Wextra -Werror

SRC		=	main.cpp \
			Zombie.cpp \
			newZombie.cpp \
			randomChump.cpp \


OBJ		=	$(SRC:.cpp=.o)

all		:	$(NAME)

%.o	: 	%.cpp
	$(CC) $(CXXFLAGS) -c $<

$(NAME)	:	$(OBJ)
	$(CC) $(CXXFLAGS) $(OBJ) -o zomvoid

clean	:
	rm -rf $(OBJ)

fclean 	:	clean
	rm -rf $(NAME)

re 		: 	fclean all

.PHONY	:	all clean fclean re