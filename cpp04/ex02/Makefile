# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: elenavoronin <elnvoronin@gmail.com>          +#+                      #
#                                                    +#+                       #
#    Created: 2023/02/03 11:47:21 by evoronin      #+#    #+#                  #
#    Updated: 2024/09/04 17:32:06 by evoronin      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = abstract
SRCS = main.cpp ./src/AAnimal.cpp ./src/Cat.cpp ./src/Dog.cpp	\
		./src/WrongAnimal.cpp ./src/WrongCat.cpp ./src/Brain.cpp 
OBJS = $(SRCS:.cpp=.o)
INCLUDE = ./include/AAnimal.hpp ./include/Cat.hpp ./include/Dog.hpp	\
		./include/WrongAnimal.hpp ./include/WrongCat.hpp ./include/Brain.hpp
CC = c++
FLAGS = -Wall -Wextra -Werror 

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
