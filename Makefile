NAME =  libftpush.a

TARGET =	so_long

CHECKER =	checker

DIR_SRC = so_long/

DIR_LIB = include/

DIR_OBJS = obj/

SRCS	=	

MAIN	= 	main.c

MAINC	= 	checker.c

OBJS	=	${SRCS:.c=.o}

CC = gcc 
	
C = -c 

CFLAGS = 

AR = ar 

ARFLGS = crs

RM = rm

LIBF = libft/

MINILIX = minilibx_opengl/

NORMINETTE = norminette .

ARGMN = 5 4 3 2 1 0

all: $(NAME)




$(NAME): 
	@make -C $(MINILIX)
	@make -C $(LIBF)
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	@mkdir obj
	@cp $(DIR_SRC)* .
	@$(CC) $(C) $(SRCS) 
	@$(AR) $(ARFLGS) $(NAME) $(OBJS)
	@rm *.c
	@mv *.o $(DIR_OBJS)
	@$(CC) $(CFLAGS) $(DIR_SRC)$(MAIN) $(NAME) -o $(TARGET)
	@$(CC) $(CFLAGS) $(DIR_SRC)$(MAINC) $(NAME) -o $(CHECKER)
	@echo Compiled push_swap finish OK!!
	

.PHONY: clean fclean re
clean:
	@$(RM) -r obj/
	@make fclean -C $(LIBF)
	@make clean -C $(MINILIX)
	@echo Delete completed successfully! *.o

fclean: clean
	@rm libftpush.a push_swap
	@make clean -C $(LIBF)
	@make clean -C $(MINILIX)
	
	@echo Delete completed successfully! *.a
 
re: fclean all

norm:
	@$(NORMINETTE) $(SRCS)