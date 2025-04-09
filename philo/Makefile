NAME = philo

SRCS = \
		philo_check.c \
		philo_init.c \
		philo_main.c \
		philo_msg.c \
		philo_routine.c \
		philo_single.c \
		philo_thread.c

FLAGS = -Wall -Werror -Wextra -g -pthread
CC = gcc $(FLAGS)
RM = rm -f

OBJS = $(SRCS:%.c=%.o)

$(NAME): $(OBJS)
	@echo "Linking $(NAME)..."
	$(CC) $(OBJS) -o $(NAME)

all : $(NAME)

clean :
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re