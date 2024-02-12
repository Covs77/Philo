
# Colores

BOLD      := \033[1m
#BLACK     := \033[30;1m
#RED       := \033[31;1m
#GREEN     := \033[32;1m
#YELLOW    := \033[33;1m
#BLUE      := \033[34;1m
#MAGENTA   := \033[35;1m
#CYAN      := \033[36;1m
#WHITE     := \033[37;1m
#RESET     := \033[0m 

# nombre programa

NAME = philo


# compilador
CC = gcc 

CFLAGS = -Wall -Werror -Wextra -pthread

LIB = ar rcs

SRC = src/philo.c src/philo_utils_1.c src/philo_check_inputs.c \
src/philo_init.c 


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


