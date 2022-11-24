# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnabil < rnabil@student.1337.ma >          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 16:21:43 by rnabil            #+#    #+#              #
#    Updated: 2022/11/24 12:51:43 by rnabil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Main_functions = $(addprefix src/, main errors philo philo_utils utils initializations)
OBJS_main = $(Main_functions:=.o)

NAME  = philo
CC	  = gcc
FLAGS = -g -Wall -Wextra -Werror

.Phony: all clean fclean re bonus

all : $(NAME)

%.o: %.c includes/philo.h
	$(CC) $(FLAGS)  -c $< -o $@
 
$(NAME): $(OBJS_main) includes/philo.h
		$(CC) $(OBJS_main) $(FLAGS) -o $(NAME) 

clean:
		rm -f $(OBJS_main)

fclean: clean
		rm -f $(NAME)

re: fclean all