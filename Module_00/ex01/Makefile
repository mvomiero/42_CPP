# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 15:58:15 by mvomiero          #+#    #+#              #
#    Updated: 2023/05/23 17:30:33 by mvomiero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
YELLOW		=	\e[93;5;226m
GRAY		=	\e[33;2;37m
RESET		=	\e[0m

# Program file name
NAME	= MAPB

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
SRC		= 	main.cpp \
			PhoneBook.cpp \
			Contact.cpp 
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
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(INC)
	@echo "$(YELLOW)\n\tExecutable ready\n$(RESET)"

# Objects directory rule
$(OBJ_PATH):
	@echo "Generating obj folder"
	mkdir $(OBJ_PATH)

# Clean up - Reset
clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean