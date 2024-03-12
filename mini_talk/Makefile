# NAME = minitalk

# SERVER = server

# SERVER_BONUS = server

# CLIENT = client

# CLIENT_BONUS = client

# CC = cc

# CFLAGS = -Wall -Wextra -Werror

# RM = rm -f

# SRCS_SERVER = server.c utils.c

# SRCS_CLIENT = client.c utils.c

# SRCS_SERVER_BONUS = server_bonus.c utils.c

# CLIENT_BONUS = client_bonus.c utils.c

# OBJS_SERVER = $(SRCS_SERVER:.c=.o)

# OBJS_SERVER_BONUS = $(SRCS_SERVER_BONUS:.c=.o)

# OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

# OBJS_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)

# all: $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

# $(SERVER): $(OBJS_SERVER)
# 	$(CC) $(CFLAGS) -o $(SERVER) $(OBJS_SERVER)

# $(SERVER_BONUS): $(OBJS_SERVER_BONUS)
# 	$(CC) $(CFLAGS) -o $(SERVER_BONUS) $(OBJS_SERVER_BONUS)

# $(CLIENT): $(OBJS_CLIENT)
# 	$(CC) $(CFLAGS) -o $(CLIENT) $(OBJS_CLIENT)

# $(CLIENT_BONUS): $(OBJS_CLIENT_BONUS)
# 	$(CC) $(CFLAGS) -o $(CLIENT_BONUS) $(OBJS_CLIENT_BONUS)


# $(NAME): all

# #bonus: all

# clean:
# 	$(RM) $(OBJS_SERVER) $(OBJS_CLIENT)
# 	$(RM) $(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS)

# fclean: clean
# 	$(RM) $(SERVER) $(CLIENT)
# 	$(RM) $(SERVER_BONUS) $(CLIENT_BONUS)

# re: fclean all

# .PHONY: all clean fclean re
NAME = minitalk
SERVER = server
CLIENT = client
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS_SERVER = server.c utils.c
SRCS_CLIENT = client.c utils.c
SRCS_SERVER_BONUS = server_bonus.c utils.c
SRCS_CLIENT_BONUS = client_bonus.c utils.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_SERVER_BONUS = $(SRCS_SERVER_BONUS:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) -o $(SERVER) $(OBJS_SERVER)

$(CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) -o $(CLIENT) $(OBJS_CLIENT)

bonus: $(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS)
	$(CC) $(CFLAGS) -o $(SERVER) $(OBJS_SERVER_BONUS)
	$(CC) $(CFLAGS) -o $(CLIENT) $(OBJS_CLIENT_BONUS)

$(NAME): all

clean:
	$(RM) $(OBJS_SERVER) $(OBJS_CLIENT) $(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS)

fclean: clean
	$(RM) $(SERVER) $(CLIENT) 

re: fclean all

.PHONY: bonus all clean fclean re bonus