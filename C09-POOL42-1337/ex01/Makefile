SRCS = srcs/ft_putchar.c \
		srcs/ft_swap.c \
		srcs/ft_putstr.c \
		srcs/ft_strlen.c \
		srcs/ft_strcmp.c 

OBJ = $(SRCS:.c=.o)

CC = cc

FLAGS = -Wall -Wextra -Werror 

LIB = libft.a

all: $(LIB)

$(LIB) : $(OBJ)
		ar rcs $(LIB) $(OBJ)

%.o : %.c 
		$(CC) $(FLAGS) -c $<  -o $@

clean :
		rm -rf  $(OBJ)

fclean : clean
		m -rf  $(LIB)

re : fclean all

.PHONY : all clean fclean re