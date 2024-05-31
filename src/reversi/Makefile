# Name des ausführbaren Programms
PROG = main

# Compiler, der verwendet werden soll
CC = gcc

# Compilerflags: Warnungen aktivieren und C++98-Standard erzwingen
CFLAGS = -Wall -Wextra -std=c++98

# Linker-Flags
LDFLAGS =

# Liste der Quelldateien
SRCS = Board.cpp GameManager.cpp Menu.cpp Player.cpp main.cpp

# Umwandlung der Quelldateien in Objektdateien
OBJS = $(SRCS:.cpp=.o)

# Bibliotheken, die beim Linken verwendet werden sollen
LIBS = -lstdc++

# Standardziel, das gebaut wird, wenn kein spezifisches Ziel angegeben wird
all: $(PROG)

# Regel, um das Programm zu linken und das endgültige ausführbare Programm zu erstellen
$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(PROG) $(OBJS) $(LIBS)

# Regel, um alle Zwischendateien und das ausführbare Programm zu löschen
clean:
	rm -f $(OBJS) $(PROG)

# Regel, um das Programm auszuführen
run: $(PROG)
	./$(PROG)
