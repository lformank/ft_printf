SRC		=	ft_printf.c
OBJ		=	$(SRC:.c=.o)
CC		=	cc
RM		=	rm -f
CFLAGS		=	-Wall -Wextra -Werror
NAME		=	libftprintf.a
all:		$(NAME)
$(NAME):	$OBJ
		ar rcs $(NAME) $(OBJ)
clean:
		$(RM) $(OBJ)
fclean:		clean
		$(RM) $(NAME)
re:		fclean $(NAME)
.PHONY		all clean fclean re
