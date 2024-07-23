# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: elenavoronin <elnvoronin@gmail.com>          +#+                      #
#                                                    +#+                       #
#    Created: 2023/02/03 11:47:21 by evoronin      #+#    #+#                  #
#    Updated: 2024/07/08 13:34:57 by evoronin      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = phonebook
SRCS = main.cpp Phonebook.cpp Contact.cpp
OBJS = $(SRCS:.cpp=.o)
INCLUDE = Phonebook.hpp Contact.hpp
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
