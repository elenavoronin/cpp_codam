
NAME = span
SRCS = main.cpp ./src/Span.cpp
OBJS = $(SRCS:.cpp=.o)
INCLUDE = ./include/Span.hpp
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++17
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
