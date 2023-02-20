NAME = minishell
COM = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
LIBFT = libft/libft.a

FUN=	main.c	\
		expande.c	\
		err_msg.c	\
		break_cmd.c	\
		divide.c	\
		ft_list.c	\

OBJ= $(FUN.c=.o)

all: $(NAME) $(LIBFT)

$(NAME): $(OBJ) $(LIBFT)
	$(COM) $(CFLAGS) -fsanitize=address -g3  -lreadline $(FUN) $(LIBFT) -o $(NAME)


$(LIBFT):
	make all -C ./libft

clean:
	$(RM) $(OBJ)
	make clean -C ./libft

fclean:
	$(RM) $(NAME)
	make fclean -C ./libft

re:	fclean all

#-fsanitize=address -g3 