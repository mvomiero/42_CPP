# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/07 12:31:25 by mvomiero          #+#    #+#              #
#    Updated: 2023/10/17 12:01:06 by mvomiero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
YELLOW		=	\e[33;1m
RESET		=	\e[0m

# Program file name
NAME	= PmergeMe

# Compiler and flags
CC		= c++
CFLAGS	= -Werror -Wextra -Wall -std=c++98

# Includes
INC_PATH 	= ./
#INC_PATH 	= ./includes/
INC			= -I $(INC_PATH)

# Sources
SRC_PATH = ./
#SRC_PATH = ./sources/
SRC		=	main.cpp \
			PmergeMe.cpp
SRCS	= $(addprefix $(SRC_PATH), $(SRC))

# Objects
OBJ_PATH = ./objects/
OBJ		= $(SRC:.cpp=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))

# Main rule
all: $(OBJ_PATH) $(NAME)

# Objects compilation
$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

# Project compilation
$(NAME): $(OBJS)
	@echo "compiling Project"
	@$(CC) $(CFLAGS) $(OBJS) -o $@ $(INC)
	@echo "$(YELLOW)\n\tExecutable ready\n$(RESET)"

# Objects directory rule
$(OBJ_PATH):
	@echo "Generating obj folder"
	mkdir $(OBJ_PATH)

# Clean up - Reset
clean:
	@echo "removing object files"
	@rm -rf $(OBJ_PATH)

fclean: clean
	@echo "removing executable"
	rm -f $(NAME)

re: fclean all

test:

	@echo "-----------------------------"
	./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
	@echo "$(YELLOW)\nExpected: 42$(RESET)"
	@echo "-----------------------------"
	./RPN "7 7 * 7 -"
	@echo "$(YELLOW)\nExpected: 42$(RESET)"
	@echo "-----------------------------"
	./RPN "1 2 * 2 / 2 * 2 4 - +"
	@echo "$(YELLOW)\nExpected: 0$(RESET)"
	@echo "-----------------------------"
	./RPN "(1 + 1)"
	@echo "$(YELLOW)\nExpected: Error$(RESET)"
	@echo "-----------------------------"
	./RPN "1 2 * 2 / 2 **** 2 4 - +"
	@echo "$(YELLOW)\nExpected: 0$(RESET)"
	@echo "-----------------------------"
	./RPN "1 2 *5465465"
	@echo "$(YELLOW)\nExpected: 0$(RESET)"
	@echo "-----------------------------"


.PHONY: all re clean fclean