# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: elenavoronin <elnvoronin@gmail.com>          +#+                      #
#                                                    +#+                       #
#    Created: 2023/02/03 11:47:21 by evoronin      #+#    #+#                  #
#    Updated: 2024/08/18 14:58:49 by evoronin      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = FragTrap
SRCS = main.cpp ClapTrap.cpp FragTrap.cpp
OBJS = $(SRCS:.cpp=.o)
INCLUDE = ClapTrap.hpp FragTrap.hpp
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
