##
## EPITECH PROJECT, 2019
## SOURCES
## File description:
## Makefile
##

ROOT_PATH			=	../
LIBSRC_PATH         =   libsrc/

NAME 		= 	$(ROOT_PATH)plazza
SRC_LIB 	= 	$(LIBSRC_PATH)libsrc.a

SRC_PATH			=	sources/
INCLUDE_PATH		=	$(ROOT_PATH)include/

KITCHEN_PATH		=	kitchen/
PIZZA_PATH			=	pizza/
RECEPTION_PATH		=	reception/

INCLUDES	=	-I./$(INCLUDE_PATH)$(KITCHEN_PATH) 		\
				-I./$(INCLUDE_PATH)$(PIZZA_PATH) 		\
				-I./$(INCLUDE_PATH)$(RECEPTION_PATH)

override CPPFLAGS 	+=	-W -Wall -Werror -Wextra $(INCLUDES) -std=c++11 -pthread
override LDFLAGS 	+=
override LDLIBS 	+=

TST_SRC		=	$(KITCHEN_PATH)Kitchen.cpp				\
				$(KITCHEN_PATH)Cook.cpp					\
				$(PIZZA_PATH)Pizza.cpp					\
				$(PIZZA_PATH)Recipe.cpp					\
				$(RECEPTION_PATH)ArgumentsHandler.cpp	\
				$(RECEPTION_PATH)Parser.cpp				\
				$(RECEPTION_PATH)Reception.cpp			\
				$(RECEPTION_PATH)Usage.cpp				\

SRC			=		main.cpp							\
					$(TST_SRC)


OBJ 		= 	$(SRC:.cpp=.o)

TST_OBJ 	= 	$(TST_SRC:.cpp=.o)

CC		= 	g++
LD		=	$(CC)
PRINT		=	@echo -e
RM          =   @rm -f

$(NAME): $(OBJ)
	$(PRINT) "\n------->\tCOMPILED SRC DEPENDENCIES.\n\nLET'S LINK IT ALL:\n"
	$(LD) $(CPPFLAGS) $^ $(LDFLAGS) $(LDLIBS) -o $@
	$(PRINT) "\n------->\tCONGRATS !\n"

$(SRC_LIB): $(TST_OBJ)
	$(PRINT) "\n------->\tCOMPILED SRC DEPENDENCIES.\n\nLET'S PACK AS A LIBRARY:\n"
	@mkdir $(LIBSRC_PATH)
	$(AR) rc $@ $^
	$(PRINT) "\n------->\tCONGRATS ! YOUR LIBRARY HAS BEEN CREATED.\n"

all: $(NAME)

lib: $(SRC_LIB)

clean:
	$(PRINT) "\n------->\tREMOVE TMP FILES\n"
	$(RM) $(OBJ) $(OBJ:.o=.gcno) $(OBJ:.o=.gcda)

fclean: clean
	$(PRINT) "------->\tREMOVE BINARY\n"
	$(RM) $(NAME)
	$(PRINT) "------->\tREMOVE SERVER'S LIBRARY\n"
	$(RM) $(SRC_LIB)
	$(RM) -r $(LIBSRC_PATH)

re: fclean all

.PHONY: all clean fclean re
