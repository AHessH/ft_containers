NAME		:= a.out
SRCS		:= tests/main.cpp
HDRS		:= Vector.hpp List.hpp
OBJS		:= $(SRCS:.cpp=.o)

CXX			:= clang++
CXXFLAGS	:= -std=c++11 -Iincludes/
CXXFLAGS	+= -Wall -Werror -Wextra

all: $(NAME)

%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -o $< -c $@

$(NAME):  $(OBJS) #$(HDRS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
