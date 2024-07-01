##
## EPITECH PROJECT, 2023
## bsorganized
## File description:
## Makefile
##
NAME = organized

SRCS =	main.c \
		number_management.c \
		disp_files.c \
		error_handling.c
OBJ = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -Iinclude/
LDFLAGS = -L. -lmy -lshell
DBUGFLAGS = -g3
DBUGRUN_LOGNAME = valgrind-out.txt
DBUGRUN_FLAGS = --leak-check=yes --show-leak-kinds=all --track-origins=yes \
				--verbose --log-file=$(DBUGRUN_LOGNAME) \
				--trace-children=yes --track-fds=yes
TEST_VALUES = 90 "...o"

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C lib/my
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(MAKE) -C lib/my clean
	$(RM) -f $(OBJ)
	$(RM) -f $(DBUGRUN_LOGNAME)

fclean: clean
	$(MAKE) -C lib/my fclean
	$(RM) -f $(NAME)

re: fclean all

debug: CFLAGS += $(DBUGFLAGS)
debug: $(OBJ)
	$(MAKE) -C lib/my
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(DBUGFLAGS)

debug_re: fclean debug

debug_run: debug_re
	valgrind $(DBUGRUN_FLAGS) ./$(NAME)
	cat $(DBUGRUN_LOGNAME)
	echo $$(cat $(DBUGRUN_LOGNAME))
