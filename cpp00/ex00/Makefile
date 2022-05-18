# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fbes <fbes@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/05/18 19:09:49 by fbes          #+#    #+#                  #
#    Updated: 2022/05/18 22:05:51 by fbes          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =		megaphone

HEADERS =

SRCS =		megaphone.cpp

INCLUDES =

OBJS =		$(SRCS:.cpp=.o)

CFLAGS =	-g -std=c++98 -Wall -Werror -Wextra


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
