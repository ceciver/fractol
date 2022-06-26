SRCS = colors.c \
		complex.c \
		utils.c \
		main.c \
		fractol.c \
		events.c \
		events_utils.c \
		fractals.c 

OBJS = ${SRCS:%.c=%.o}
NAME = FRACTOL

CC		= cc
CFLAGS	= -Wall -Werror -Wextra -O2 -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@


$(NAME): $(OBJS)
	$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all
