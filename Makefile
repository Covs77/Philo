
# nombre programa

NAME = philo


# compilador
CC = gcc 

CFLAGS = -Wall -Werror -Wextra -pthread

LIB = ar rcs

SRC = src/philo.c src/philo_utils_1.c src/philo_check_inputs.c \
src/philo_pthread.c src/philo_init.c src/philo_rutine.c \
src/philo_utils_2.c 


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


