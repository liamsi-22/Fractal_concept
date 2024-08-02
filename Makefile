NAME = fractol

SRC_FILES = main.c fractal_init.c fractal_rend.c events.c guid_fnc.c math_fnc.c
OBJ_FILES = $(SRC_FILES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
MINILIBX = -Lminilibx -lmlx -lX11 -lXext -lm

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	$(CC) $(OBJ_FILES) $(MINILIBX) -o $@

clean :
	rm -f $(OBJ_FILES)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
