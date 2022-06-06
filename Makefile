MAKE		=	make

LIBPATH		=	libft

LIB 		=	libft.a

NAME		=	push_swap

SRC_FILES	=	push_swap.c check_args.c actions.c radix_sort.c sort_small.c sort_big.c

OBJS		=	$(SRC_FILES:.c=.o)

CC			= 	gcc

SRC_DIR		=	srcs/

OBJS_DIR	=	objs/

FLAGS 		=	-c	-Wall -Wextra -Werror

INCLUDE		=	-I includes/	-I $(LIBPATH)

RM 			=	rm -rf

PS_SRCS		=	$(addprefix $(SRC_DIR), $(SRC_FILES))

PS_OBJS		=	$(PS_SRCS:$(SRC_DIR)%.c=$(OBJS_DIR)%.o)

all			:	$(NAME)

objs/%.o	:	srcs/%.c
				@mkdir -p $(OBJS_DIR)
				$(CC) -g $(FLAGS) $(INCLUDE) $< -o $@

$(NAME)		:	$(PS_OBJS)
				@make -C $(LIBPATH) --silent
				$(CC) -o $(NAME) $(PS_OBJS) -L $(LIBPATH) -lft
				@echo "##### Compiled object files #####"

clean		:	
				@make -C $(LIBPATH) fclean  --silent
				@rm -f $(PS_OBJS) $(SRC_DIR)push_swap push_swap
				@echo "##### Removed push_swap files #####"

fclean		:	clean
				@make -C $(LIBPATH) fclean  --silent
				@rm -f $(NAME)
				@echo "##### Removed all files #####

.PHONY: all clean fclean re