
NAME = container

CC = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

SOURCES = 	./src/webserv.cpp \


OBJECTS = $(SOURCES:%.cpp=%.o)

all :		$(NAME)

$(NAME):	$(OBJECTS)
		@$(CC)  $(OBJECTS) -o $(NAME)
		@echo "[\033[32m$(NAME) ready to use\033[0m]"


clean:
		@$(RM) $(OBJECTS)
		@echo "[\033[32m$(NAME) files cleaned !\033[0m]"

fclean: clean
		@$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all
