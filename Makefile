NAME = bmiklaz.filler
FLAGS = -Wall -Wextra -Werror
LIB = libft/libft.a
CNAME = main.c filler_vectors.c filler_map.c in_main_functions.c reit_rep.c
ONAME = $(CNAME:.c=.o)

all: $(NAME)
	@echo 'Filler done!'

$(ONAME): %.o: %.c
	@make -C ./libft/
	@gcc $(FLAGS) -c $< -o $@

$(NAME): $(ONAME)
	@gcc $(ONAME) $(LIB) -o $(NAME)

clean:
	@make -C ./libft/ clean
	@echo "Clean Filler's .o"
	@rm -f $(ONAME)

fclean: clean
	@make -C ./libft/ fclean
	@echo "Clean Filler's executable"
	@rm -f $(NAME)

re: fclean all
