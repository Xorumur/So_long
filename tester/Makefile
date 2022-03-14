NAME	= test

OBJ		= $(SRCS:.c=.o)

CFLAGS	= -Wall -Wextra -Werror #-g -fsanitize=address

SRCS	=	main.c ../audit_map/parsing_map.c ../gnl/get_next_line.c \
			../gnl/get_next_line_utils.c ../error_management/error.c afftab.c

all: $(NAME)

$(NAME):	$(OBJ)
	gcc $(CFLAGS) $(OBJ) -o $(NAME)

clean:
			rm -f $(OBJ) 

fclean: 	clean
			rm -f $(NAME)

norme:
			norminette -R CheckForbiddenSourceHeader $(SRCS)

re:			fclean all

.PHONY :	all clean fclean re
 