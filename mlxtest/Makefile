EXEC		=	so_long

CC			=	gcc
RM			= 	rm -f
FLAG		=	-Wall -Werror -Wextra

# LIBFT_DIR	=	./ToolBox/Libft
# LIBFT_EXEC	=	./ToolBox/Libft/libft

# MLX_DIR		=	./ToolBox/MiniLibX
MLX_EXEC	=	../MiniLibX/libmlx.a
MLX_LIB		=	$(MLX_EXEC) -framework OpenGL -framework AppKit -lm

SRC			=	main.c 

OBJ			=	$(SRC:.c=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(FLAG) $(MLX_LIB) $(SRC) -o $(EXEC)

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)
	$(RM) $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(EXEC)

re: fclean all

.PHONY: all clean fclean re
