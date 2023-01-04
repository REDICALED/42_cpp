NAME	=	zomvoid
CXX		=	c++
CXXFLAGS	=	-std=c++98 -Wall -Wextra -Werror

SRC		=	main.cpp \
			Zombie.cpp \
			newZombie.cpp \
			randomChump.cpp \


OBJ		=	$(SRC:.cpp=.o)

all		:	$(NAME)

%.o	: 	%.cpp
	$(CXX) $(CXXFLAGS) -c $<

$(NAME)	:	$(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o zomvoid

clean	:
	rm -rf $(OBJ)

fclean 	:	clean
	rm -rf $(NAME)

re 		: 	fclean all

.PHONY	:	all clean fclean re