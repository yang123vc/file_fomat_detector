# compilation
CC = gcc
CFLAGS = -Walls -Werror -Wextra

# default rule
NAME = file_type

# directories
SRCDIR = src	
OBJDIR = objects
INCDIR = includes

# files
INC = file.h
SRC = \
	 main.c \
	 analysis.c\
	 mp4.c
OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
OBJ_DIRS = $(dir $(objs))

# prefix
SRCS = $(addprefix $(SRCDIR)/, $(SRC))
INCS = $(addprefix $(INCDIR)/, $(INC))


# rules
all: $(NAME)

$(NAME): build $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

build:
	@mkdir $(OBJDIR)

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -rf $(NAME)

re:
	fclean all
