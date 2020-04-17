##
## EPITECH PROJECT, 2019
## TESTS
## File description:
## MAKEFILE
##

NAME 	= 	critests

CC		= 	gcc
LD		=	$(CC)

LIB			=	lib
PRINT		=	@echo -e
RM			=	@rm -f

ADD_COVERAGE	=	'CPPFLAGS	+=	--coverage'
ADD_LCRITERION	=	'LDLIBS		+=	-lcriterion'

ROOT_PATH		=	../

SOURCES_PATH		=	$(ROOT_PATH)sources/
INCLUDE_PATH		=	$(ROOT_PATH)include/
SRCLIB				=	$(SOURCES_PATH)libsrc/

KITCHEN_PATH		=	kitchen/
PIZZA_PATH			=	pizza/
RECEPTION_PATH		=	reception/

INCLUDES	=	-I./$(INCLUDE_PATH)$(KITCHEN_PATH) 		\
				-I./$(INCLUDE_PATH)$(PIZZA_PATH) 		\
				-I./$(INCLUDE_PATH)$(RECEPTION_PATH)

override CFLAGS	  		+=	-W -Wall -Wextra -Wextra $(INCLUDES) --coverage
override LDFLAGS    	+= 	-L./$(SRCLIB)
override LDLIBS     	+=	-lcriterion -lsrc


TEST_SRC		=	sources/
REC_FUNC		=	generic/


SRC 	= 	$(REC_FUNC)redirect.c

OBJ 	= 	$(SRC:.c=.o)


$(NAME): $(OBJ)
	$(PRINT) "\n------->\tCOMPILED TESTS SRC DEPENDECIES.\n"
	@$(MAKE) $(LIB) -C $(SOURCES_PATH) $(ADD_COVERAGE) $(ADD_LCRITERION)
	$(PRINT) "\n------->\tLET'S LINK IT ALL.\n"
	$(LD) $^ -o $@ $(CFLAGS) $(LDFLAGS) $(LDLIBS)
	$(PRINT) "\n------->\tCONGRATS!"
	$(PRINT) "\n\n"
	./$(NAME)
	$(PRINT) "\n\n"

all: $(NAME)

clean:
	$(PRINT) "\n------->\tREMOVE TESTS TMP FILES\n"
	$(RM) $(OBJ) $(OBJ:.o=.gcno) $(OBJ:.o=.gcda)

fclean: clean
	$(PRINT) "------->\tREMOVE TESTS\n"
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re