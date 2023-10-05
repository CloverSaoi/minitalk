# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddutta <ddutta@student.42adel.org.au>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/05 01:51:45 by ddutta            #+#    #+#              #
#    Updated: 2023/10/05 01:51:47 by ddutta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

CFLAGS = -Wall -Werror -Wextra
CC = cc

all: $(SERVER) $(CLIENT)
$(SERVER):
	$(CC) $(CFLAGS) server.c -o $(SERVER)
	@echo "Server is Ready!"
$(CLIENT):
	$(CC) $(CFLAGS) client.c -o $(CLIENT)
	@echo "Client is Ready!"

clean:
	@echo "clean successful"

fclean: clean
	@rm -f $(SERVER) $(CLIENT)
	@echo "Server and Client Have Been Cleaned Successfully"

re: fclean all