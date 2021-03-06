# compilation
CC = gcc
CFLAGS = -Wall -Werror -Wextra

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
	 mp4.c \
	 raw.c \
	 png.c \
	 wmv.c \
	 deb.c \
	 rar.c \
	 3pg.c \
	 gif.c \
	 lzip.c \
	 amazon_kindle.c \
	 jar.c \
	 java_class.c \
	 avi.c \
	 wav.c \
	 rpm_package.c \
	 ico.c \
	 pdf.c \
	 jpg.c \
	 tiff.c \
	 bzh.c \
	 zip.c \
	 tarz.c \
	 exe.c \
	 bmp.c \
	 mp3.c

OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

# prefix
SRCS = $(addprefix $(SRCDIR)/, $(SRC))
INCS = $(addprefix $(INCDIR)/, $(INC))


# rules
all: $(NAME)

$(NAME): build $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

build:
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) -c -o $@ $< -I$(INCDIR) $(CFLAGS)

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
