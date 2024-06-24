# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: elenavoronin <elnvoronin@gmail.com>          +#+                      #
#                                                    +#+                       #
#    Created: 2023/02/03 11:47:21 by evoronin      #+#    #+#                  #
#    Updated: 2024/06/24 13:04:30 by elenavoroni   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = weapon
SRCS = main.cpp Weapon.hpp Weapon.cpp HumanA.hpp HumanB.hpp HumanA.cpp HumanB.cpp
OBJS = $(SRCS:.cpp=.o)
INCLUDE = Weapon.hpp HumanA.hpp HumanB.hpp
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
