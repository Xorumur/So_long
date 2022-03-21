NAME	= test

OBJ		= $(SRCS:.c=.o)

CFLAGS	= -Wall -Wextra -Werror -g -fsanitize=address

SRCS	=	main2.c ../audit_map/parsing_map.c ../gnl/get_next_line.c \
			../gnl/get_next_line_utils.c ../error_management/error.c afftab.c \
			../audit_map/init_struct.c ../refresh_map/actualize.c \
			../refresh_map/bot.c ../map_scaling/map_size_ajust.c \
			../error_management/free.c ../lib/ft_strjoin.c ../lib/ft_split.c \

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
 