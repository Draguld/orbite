//////////////////////////////////////////////////////////////////////////////////
//																				//
//    Copyright (C) 2016 RUE Thomas												//
//																				//
//    This program is free software; you can redistribute it and/or modify		//
//    it under the terms of the GNU General Public License as published by		//
//    the Free Software Foundation; either version 2 of the License, or			//
//    (at your option) any later version.										//
//																				//
//    This program is distributed in the hope that it will be useful,			//
//    but WITHOUT ANY WARRANTY; without even the implied warranty of			//
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the				//
//    GNU General Public License for more details.								//
//																				//
//    You should have received a copy of the GNU General Public License along	//
//    with this program; if not, write to the Free Software Foundation, Inc.,	//
//    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.				//
//																				//
//////////////////////////////////////////////////////////////////////////////////

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

