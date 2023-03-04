# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/03 15:12:02 by oezzaou           #+#    #+#              #
#    Updated: 2023/03/03 20:28:12 by oezzaou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
##################################
#            COMPILER            #
##################################
CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror
NAME		:= philo
PTHREAD_LIB := pthread

##################################
#              SRCS              #
##################################
INCDIR		:= include/
SRCDIR 		:= src
OBJDIR 		:= obj
SRCS 		:= philo philo_info philo_utils
OBJS 		:= $(addprefix $(OBJDIR)/, $(addsuffix .o, $(SRCS)))
SRCS 		:= $(addprefix $(SRCDIR)/, $(addsuffix .c, $(SRCS)))

##################################
#             COLORS             #
##################################
GREEN 		:= \033[1;32m
RED 		:= \033[1;31m
CYAN 		:= \033[1;36m
NOCLR 		:= \033[1;0m

##################################
#              RULS              #
##################################

all: $(OBJDIR) $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $^ -I $(INCDIR) -o $@
	@printf "\n%45s\n\n" "<<<<<<<<<<<<< $(NAME) >>>>>>>>>>>>>>"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@
	@printf "Compiling : $< %25s\n" "===> $@"

$(OBJDIR):
	@mkdir -p $@

clean:
	@rm -rf $(OBJDIR)
	@echo "" | awk 'BEGIN{a=0; printf("["); while(a < 50){printf("%c", "#"); system("sleep 0.0005");a++}}{print "]\n\n	=> Done Cleaing\n"}'

fclean: clean
	@rm -rf $(NAME)

re: fclean all 

test:
	./$(NAME) 4 3000 3000 3000
.PHONY: all clean fclean re
