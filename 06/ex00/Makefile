NAME	= xx
CXX		=	c++
CXXFLAGS	=	-std=c++98 -Wall -Wextra -Werror

SRC		=	main.cpp \
			Scala.cpp \


OBJ		=	$(SRC:.cpp=.o)

all		:	$(NAME)

%.o	: 	%.cpp
	$(CXX) $(CXXFLAGS) -c $<

$(NAME)	:	$(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean	:
	rm -rf $(OBJ)

fclean 	:	clean
	rm -rf $(NAME)

re 		: 	fclean all

.PHONY	:	all clean fclean re

# 1. strtod(input, end_ptr)로 double로 형변환 후 생각.
# 1-1. 하기 전에, 단일 char 값인지 고려.
# 1-0. 하기 전에,... 생성자에선 end_ptr을 이용해서 이것의 원본 타입이 무엇인지만 저장해둠.
# 2. end_ptr 검사하면서 예외처리함. (길이가 1이면서 f냐? and end_ptr이 비어있냐?)
# 	ㄴ throw BAD_INPUT
# 3. 충족되면, char / int / float / double 로 static_cast 이용해서 형변환

# 4. 형변환 시에 예외처리 해줌. 각 케이스마다 좀 다르게 작용될거로 예상.

# 5. 공통적인 부분, 생각한 예외처리는 - 
# 1) 오버플로우 (float.h, limits.h 사용)
# 2) isnan, isinf 사용
