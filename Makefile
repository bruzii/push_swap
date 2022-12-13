NAME	= push_swap

SRC		= src/main.c src/ft_instruc.c src/parcing.c src/ft_instruct2.c src/ft_instruct3.c src/ft_treecase.c src/ft_instruct4.c src/ft_cost.c src/ft_instruct5.c

CC = gcc

INCLUDE =	-I./includes -Ilibft

LIB		= -Llibft -lft

CFLAGS	= -Wall -Wextra	-Werror -ggdb3 $(INCLUDE) $(LIB)

OBJ		= ${SRC:.c=.o}

all		: $(NAME)

$(NAME)	: $(OBJ)
		$(MAKE) bonus -C libft/
		$(CC) $(OBJ) $(CFLAGS) -o $(NAME)


clean	: 
		$(MAKE) clean -C libft/
		rm -f $(OBJ)

fclean	: clean
		$(MAKE) fclean -C libft/
		rm -f $(NAME)

re		: fclean all

.PHONY : all clean fclean re
