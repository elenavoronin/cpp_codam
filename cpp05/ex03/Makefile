# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: elenavoronin <elnvoronin@gmail.com>          +#+                      #
#                                                    +#+                       #
#    Created: 2023/02/03 11:47:21 by evoronin      #+#    #+#                  #
#    Updated: 2024/09/29 16:43:30 by evoronin      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = intern
SRCS = main.cpp ./src/Bureaucrat.cpp ./src/AForm.cpp ./src/PresidentialPardonForm.cpp \
	./src/RobotomyRequestForm.cpp ./src/ShrubberyCreationForm.cpp ./src/Intern.cpp
OBJS = $(SRCS:.cpp=.o)
INCLUDE = ./include/AForm.hpp ./include/Bureaucrat.hpp ./include/PresidentialPardonForm.hpp \
	./include/RobotomyRequestForm.hpp ./include/ShrubberyCreationForm.hpp ./include/Intern.hpp
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
