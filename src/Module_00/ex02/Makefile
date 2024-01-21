# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/25 11:36:39 by mvomiero          #+#    #+#              #
#    Updated: 2023/05/26 17:12:29 by mvomiero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 15:58:15 by mvomiero          #+#    #+#              #
#    Updated: 2023/05/25 11:36:54 by mvomiero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
#YELLOW		=	\e[93;5;226m
BLUE		=	\e[34;49;3;1m
RESET		=	\e[0m

# Program file name
NAME	= bank

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
SRC		= 	tests.cpp \
			Account.cpp 
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
#	@rm -f 19920104_091532.log

fclean: clean
	@echo "removing executable"
	rm -f $(NAME)
	rm -f bank.log

re: fclean all

test:
	@echo "$(BLUE)\tdiff check:$(RESET)"
	./$(NAME) > $(NAME).log
# you cut until the space and select the field 2 to erase the timestamp
	< $(NAME).log cut -d " " -f2 > $(NAME)_no_time.log
	< 19920104_091532.log cut -d " " -f2 > ref_no_time.log
	diff -s ref_no_time.log $(NAME)_no_time.log
	@rm -f ref_no_time.log $(NAME)_no_time.log

.PHONY: all re clean fclean