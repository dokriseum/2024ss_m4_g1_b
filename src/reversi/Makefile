PROG = game
CC = gcc
CFLAGS = -Wall -Wextra -std=c++98
LDFLAGS =
SRCS = game.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
LIBS = -lstdc++

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(PROG) $(OBJS) $(LIBS)

clean:
	rm -f $(OBJS) $(PROG)

run: $(PROG)
	./$(PROG)

