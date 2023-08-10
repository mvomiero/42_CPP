# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/07 12:31:25 by mvomiero          #+#    #+#              #
#    Updated: 2023/08/10 13:07:28 by mvomiero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
YELLOW		=	\x1b[33m
RESET		=	\x1b[0m

# Program file name
NAME	= maggots_advanced

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
			Bureaucrat.cpp \
			AForm.cpp \
			ShrubberyCreationForm.cpp
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

verbose:
	@make re INC="-DVERBOSE=1" 

.PHONY: all re clean fclean