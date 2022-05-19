# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fbes <fbes@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/05/19 21:48:23 by fbes          #+#    #+#                  #
#    Updated: 2022/05/19 22:18:12 by fbes          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =		zombies

HEADERS =	Zombie.hpp

SRCS =		Zombie.cpp main.cpp

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
