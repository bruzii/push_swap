NAME	= push_swap

CHECKER = checker

SRC		= src/main.c src/parcing_one_arg.c src/ft_instruc.c src/parcing_multiple_arg.c src/ft_instruct2.c src/ft_instruct3.c src/ft_push_to_b.c src/ft_instruct4.c src/ft_cost.c src/ft_instruct5.c src/ft_median.c src/ft_replace.c src/ft_free.c src/ft_algo.c src/ft_push_to_b_aux.c src/ft_special_case.c

CC = gcc

INCLUDE =	-I./includes -Ilibft

LIB		= -Llibft -lft

CFLAGS	= -Wall -Wextra	-Werror -ggdb3 $(INCLUDE) $(LIB)

OBJ		= ${SRC:.c=.o}

BONUS = src/ft_instruct_parsing.c src/ft_checker.c src/parcing_one_arg.c src/ft_instruc.c src/parcing_multiple_arg.c src/ft_instruct2.c src/ft_instruct3.c src/ft_push_to_b.c src/ft_instruct4.c src/ft_cost.c src/ft_instruct5.c src/ft_median.c src/ft_replace.c src/ft_free.c src/ft_algo.c src/ft_push_to_b_aux.c src/ft_special_case.c

BONUS_OBJS = $(BONUS:.c=.o)

all		: $(NAME)

$(NAME)	: $(OBJ)
		$(MAKE) bonus -C libft/
		$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

bonus : ${BONUS_OBJS}
		$(MAKE) bonus -C libft/
		$(CC) $(BONUS_OBJS) $(CFLAGS) -o $(CHECKER)

clean	: 
		$(MAKE) clean -C libft/
		rm -f $(OBJ) $(BONUS_OBJS)

fclean	: clean
		$(MAKE) fclean -C libft/
		rm -f $(NAME) $(CHECKER)

re		: fclean all

.PHONY : all clean fclean re
