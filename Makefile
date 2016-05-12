NAME=orbite
CC=g++
CFLAGS=-Wall -Wextra -Werror -std=c++11
LSFML=-lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio -lsfml-network
HEADER=-I includes/
RM=rm -f

SRCS=main.cpp\
Particule.cpp

OBJ=$(SRCS:.cpp=.o)

$(NAME):
	$(CC) $(CFLAGS) $(HEADER) $(SRCS) $(LSFML) -c
	$(CC) $(CFLAGS) $(HEADER) $(OBJ) $(LSFML) -o $(NAME)

noWall:
	$(CC) -std=c++11 $(HEADER) $(SRCS) $(LSFML) -c
	$(CC) -std=c++11 $(HEADER) $(OBJ) $(LSFML) -o $(NAME)

all: $(NAME)

noObjects: $(NAME) clean

clearDisplay:
	clear

debug:
	$(CC) -g $(CFLAGS) $(HEADER) $(SRCS) $(LSFML) -o $(NAME)

clean: 
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean clearDisplay all

