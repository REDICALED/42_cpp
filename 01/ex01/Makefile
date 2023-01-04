NAME	=	for_the_horde
CXX		=	c++
CXXFLAGS	=	-std=c++98 -Wall -Wextra -Werror

SRC		=	main.cpp \
			Zombie.cpp \
			zombieHorde.cpp \


OBJ		=	$(SRC:.cpp=.o)

all		:	$(NAME)

%.o	: 	%.cpp
	$(CXX) $(CXXFLAGS) -c $<

$(NAME)	:	$(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o for_the_horde

clean	:
	rm -rf $(OBJ)

fclean 	:	clean
	rm -rf $(NAME)

re 		: 	fclean all

.PHONY	:	all clean fclean re