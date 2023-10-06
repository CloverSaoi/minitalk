# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddutta <ddutta@student.42adel.org.au>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/05 01:51:45 by ddutta            #+#    #+#              #
#    Updated: 2023/10/06 20:01:07 by ddutta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

CFLAGS = -Wall -Werror -Wextra
CC = cc

all: $(SERVER) $(CLIENT)
$(SERVER):
	$(CC) $(CFLAGS) server.c -o $(SERVER)
	@echo "server:ready"
$(CLIENT):
	$(CC) $(CFLAGS) client.c -o $(CLIENT)
	@echo "client:ready"

clean:
	@echo "clean successful :)"

fclean: clean
	@rm -f $(SERVER) $(CLIENT)
	@echo "server and client cleaned successfully"

re: fclean all
