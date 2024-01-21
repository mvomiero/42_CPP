# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/07 12:31:25 by mvomiero          #+#    #+#              #
#    Updated: 2023/06/07 12:49:04 by mvomiero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
#YELLOW		=	\e[93;5;226m
BLUE		=	\e[34;49;3;1m
RESET		=	\e[0m

# Program file name
NAME	= fixed

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
			Fixed.cpp 
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
	@echo "$(BLUE)\n\tExecutable ready\n$(RESET)"

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

.PHONY: all re clean fclean