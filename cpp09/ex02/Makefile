
NAME = PmergeMe
SRCS = main.cpp ./src/PmergeMe.cpp ./src/PmergeMeVector.cpp ./src/PmergeMeDeque.cpp
OBJS = $(SRCS:.cpp=.o)
INCLUDE = ./include/PmergeMe.hpp
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++11
INCLUDE_FLAGS = -Iinclude
FLAGS += ${INCLUDE_FLAGS}

all: $(NAME)

%.o: %.cpp $(INCLUDE)
	@echo "Compiling $<"
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: fclean clean re all
