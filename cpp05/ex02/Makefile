# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fbes <fbes@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/05/23 17:47:21 by fbes          #+#    #+#                  #
#    Updated: 2022/09/01 18:47:41 by fbes          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =		formfillers

HEADERS =	Form.hpp Bureaucrat.hpp ShrubberyCreationForm.hpp \
			RobotomyRequestForm.hpp PresidentialPardonForm.hpp

SRCS =		Form.cpp Bureaucrat.cpp ShrubberyCreationForm.cpp \
			RobotomyRequestForm.cpp PresidentialPardonForm.cpp main.cpp

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
	rm -f *_shrubbery

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
