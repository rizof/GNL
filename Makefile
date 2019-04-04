CC			=	gcc
NAME		=	gnl
FLAGS		=	-Wall -Wextra -Werror
LIBDIR		=	libft
LIBLINK		=	-L $(LIBDIR) -lft
LIB 		=	$(LIBDIR)/libft.a
INCLUDES	= 	-I ./includes
INCLUDE		=	./includes
INCLUDEL	=	-I ./$(LIBDIR)/

OBJDIR		= 	objs

OBJDIR_ALGO	=	objs/

SRCDIR_ALGO	=	srcs/

SRC_ALGO	=	main.c\
				get_next_line.c\

OBJ_ALGO	=	$(SRC_ALGO:.c=.o)

SRCS_ALGO	=	$(addprefix $(SRCDIR_ALGO)/, $(SRC_ALGO))
OBJS_ALGO	=	$(addprefix $(OBJDIR_ALGO)/, $(SRC_ALGO:.c=.o))

all: directory $(NAME) 

$(NAME): $(OBJDIR_ALGO) $(LIB) $(OBJS_ALGO) $(INCLUDE)
	@$(CC) $(FLAGS) $(LIB) -o $@ $(OBJS_ALGO) $(LIBLINK)

$(LIB):
	@make -C $(LIBDIR)

$(OBJDIR_ALGO)/%.o: $(SRCDIR_ALGO)/%.c
	gcc $(FLAGS) -c $^ -o $@ $(INCLUDES) $(INCLUDEL)

directory: $(OBJDIR) $(OBJDIR_ALGO)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR_ALGO):
	@mkdir -p $(OBJDIR_ALGO)

clean:
	@rm -rf $(OBJDIR)
	@rm -rf $(OBJS_ALGO)
	@make -C $(LIBDIR) clean
	@rm -rf $(OBJDIR_ALGO)

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBDIR) fclean

re: fclean all

.PHONY: clean all re fclean directory
