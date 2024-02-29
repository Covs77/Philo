
# nombre programa

NAME = philo


# compilador
CC = gcc 

CFLAGS = -Wall -Werror -Wextra -pthread #-fsanitize=thread

LIB = ar rcs

SRC = src/philo.c src/philo_utils_1.c src/philo_check_inputs.c \
src/philo_pthread.c src/philo_init.c src/philo_rutine.c \
src/philo_utils_2.c src/philo_control.c


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
	rm -rf $(NAME).dSYM
	rm -f .DS_Store


re: fclean all

norma:
	norminette $(SRC) inc/philo.h

.PHONY: re all clean fclean


