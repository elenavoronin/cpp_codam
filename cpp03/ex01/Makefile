# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: elenavoronin <elnvoronin@gmail.com>          +#+                      #
#                                                    +#+                       #
#    Created: 2023/02/03 11:47:21 by evoronin      #+#    #+#                  #
#    Updated: 2024/08/18 14:52:59 by evoronin      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = ScavTrap
SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp
OBJS = $(SRCS:.cpp=.o)
INCLUDE = ClapTrap.hpp ScavTrap.hpp
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
