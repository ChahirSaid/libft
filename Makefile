SRCS		= char_utils/ft_isalpha.c char_utils/ft_isdigit.c char_utils/ft_isalnum.c char_utils/ft_isascii.c \
			char_utils/ft_isprint.c char_utils/ft_toupper.c char_utils/ft_tolower.c \
			mem_utils/ft_bzero.c mem_utils/ft_calloc.c mem_utils/ft_memchr.c mem_utils/ft_memcmp.c \
			mem_utils/ft_memcpy.c mem_utils/ft_memmove.c mem_utils/ft_memset.c \
			str_utils/ft_atoi.c str_utils/ft_itoa.c str_utils/ft_split.c str_utils/ft_strchr.c \
			str_utils/ft_strdup.c str_utils/ft_striteri.c str_utils/ft_strjoin.c \
			str_utils/ft_strlcat.c str_utils/ft_strlcpy.c str_utils/ft_strlen.c str_utils/ft_strmapi.c \
			str_utils/ft_strncmp.c str_utils/ft_strnstr.c str_utils/ft_strrchr.c \
			str_utils/ft_strtrim.c str_utils/ft_substr.c str_utils/ft_haschar.c str_utils/ft_uitoa.c \
			fd_utils/ft_putchar_fd.c fd_utils/ft_putendl_fd.c fd_utils/ft_putnbr_fd.c fd_utils/ft_putstr_fd.c \
			lst_utils/ft_lstnew_bonus.c lst_utils/ft_lstadd_front_bonus.c \
			lst_utils/ft_lstsize_bonus.c lst_utils/ft_lstlast_bonus.c \
			lst_utils/ft_lstadd_back_bonus.c lst_utils/ft_lstdelone_bonus.c \
			lst_utils/ft_lstclear_bonus.c lst_utils/ft_lstiter_bonus.c lst_utils/ft_lstmap_bonus.c \
			get_next_line/get_next_line.c \
			ft_printf/ft_handleflags.c ft_printf/ft_pintint.c ft_printf/ft_printchar.c \
			ft_printf/ft_printf.c ft_printf/ft_printhex.c ft_printf/ft_printptr.c ft_printf/ft_printstr.c

OBJS		= ${SRCS:.c=.o}
NAME		= libft.a
LIBC		= ar rcs
CC			= cc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror

.PHONY: all clean fclean re

%.o: %.c
	@echo "Compiling $<..."
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	@echo "Creating ${NAME}..."
	@${LIBC} ${NAME} ${OBJS}
	@echo "Library ${NAME} created successfully!"

all: ${NAME}

clean:
	@echo "Cleaning up object files..."
	@${RM} ${OBJS}
	@echo "Object files cleaned!"

fclean: clean
	@echo "Cleaning up ${NAME}..."
	@${RM} ${NAME}
	@echo "Library ${NAME} removed!"

re: fclean all
	@echo "Rebuilding the project..."
