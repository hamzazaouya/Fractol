NAME = fractols
SRCS = fractols.c functions1.c functions2.c main.c
CC = cc

CFLAGS = -Wall -Wextra -Werror
OBJS := $(SRCS:.c=.o)
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

bonus : all

$(NAME) : $(OBJS)  
	$(CC) $(MLX_FLAGS) $(CFLAGS) $(OBJS) -o $(NAME)
clean :
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re : fclean all