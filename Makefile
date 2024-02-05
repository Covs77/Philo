# nombre programa

NAME = philo


# compilador
CC = gcc 

CFLAGS = -Wall -Werror -Wextra 

LIB = ar rcs

SRC = src/philo.c src/philo_utils.c

OBJS = $(SRC:.c=.o)



$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


all: clean $(NAME)


clean:
	rm -f $(OBJS)
		
			
fclean: clean
	rm -f $(NAME)


re: fclean all


.PHONY: re all clean fclean


