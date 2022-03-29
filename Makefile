NAME = so_long

CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address

SRCS =	main.c audit_map/parsing_map.c error_management/error.c \
		audit_map/init_struct.c mlx_main/draw.c lib/ft_strdup.c \
		map_scaling/map_size_ajust.c error_management/free.c \
		lib/ft_strjoin.c lib/ft_split.c refresh_map/actualize.c \
		error_management/afftab.c lib/ft_putnbr.c lib/ft_strlen.c \

OBJS = $(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			gcc $(CFLAGS) $(OBJS) -lmlx -framework OpenGL -framework Appkit -o $(NAME)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

norme:
			norminette $(SRCS)

re:			fclean all

.PHONY:		re clean fclean all libft