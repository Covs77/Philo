# nombre programa

NAME = philo


# compilador
CC = gcc #-g

CFLAGS = -Wall -Werror -Wextra #-fsanitize=address

LIB = ar rcs


SRC = src/philo.c src/philo_utils.c

OBJS = $(SRC:.c=.o)




$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB_SYS) -o $(NAME)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@



$(LIBFT_PATH):
	make -s -C $(LIBFT_DIR)

# Agrega los archivos objeto a la lista de archivos secundarios
all: $(NAME)

clean:
	rm -f $(OBJS) 
	
			
fclean: clean
	make fclean -s -C 
	rm -f $(NAME)


re: fclean all


.PHONY: re all clean fclean


