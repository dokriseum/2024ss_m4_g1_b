# Name des ausführbaren Programms
TEST_PROG = GTestChecker

# Compiler, der verwendet werden soll
CC = g++

# Compilerflags: Warnungen aktivieren und C++11-Standard erzwingen
CFLAGS = -Wall -Wextra -std=c++14

# Linker-Flags
LDFLAGS = -lgtest -lgtest_main -pthread

# Verzeichnisse
GTEST_DIR = /opt/homebrew/Cellar/googletest/1.14.0/include

# Regel, um das Testprogramm zu kompilieren
$(TEST_PROG): GTestChecker.o
	$(CC) $(CFLAGS) GTestChecker.o -o $(TEST_PROG) $(LDFLAGS)

# Regel, um Objektdateien zu kompilieren
%.o: %.cpp
	$(CC) $(CFLAGS) -I$(GTEST_DIR) -o $@ -c $<

# Regel, um alle Zwischendateien und das ausführbare Programm zu löschen
clean:
	rm -f GTestChecker.o $(TEST_PROG)

# Regel, um das Testprogramm auszuführen
run: $(TEST_PROG)
	./$(TEST_PROG)
