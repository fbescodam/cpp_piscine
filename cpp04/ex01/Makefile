# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fbes <fbes@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/05/20 07:53:36 by fbes          #+#    #+#                  #
#    Updated: 2022/05/23 17:05:54 by fbes          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =		animals

HEADERS =	Animal.hpp Brain.hpp Cat.hpp Dog.hpp

SRCS =		Animal.cpp Brain.cpp Cat.cpp Dog.cpp main.cpp

INCLUDES =

OBJS =		$(SRCS:.cpp=.o)

CFLAGS =	-std=c++98 -Wall -Werror -Wextra


all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	clang++ $(CFLAGS) $(INCLUDES) $(SRCS) -o $(NAME)

%.o: %.cpp
	clang++ $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus:
	@echo I did not do the bonus

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
