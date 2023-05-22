# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvomiero <mvomiero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 13:34:20 by mvomiero          #+#    #+#              #
#    Updated: 2023/05/22 13:35:33 by mvomiero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= megaphone

CC		= g++
CFLAGS	= -Werror -Wextra -Wall -std=c++98

SRC		= megaphone.cpp
OBJ		= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean