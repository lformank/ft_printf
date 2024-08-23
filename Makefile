SRC		=	ft_printf.c ft_uphexdec.c ft_lowhexdec.c \
			ft_unsignedint.c ft_int.c ft_ptr.c ft_str.c \
			ft_char.c ft_putnbr_fd.c \
OBJ		=	$(SRC:.c=.o)
CC		=	cc
RM		=	rm -f
CFLAGS		=	-Wall -Wextra -Werror
NAME		=	libftprintf.a
all:		$(NAME)
$(NAME):	$(OBJ)
		ar rcs $(NAME) $(OBJ)
clean:
		$(RM) $(OBJ)
fclean:		clean
		$(RM) $(NAME)
re:		fclean $(NAME)
.PHONY:		all clean fclean re
