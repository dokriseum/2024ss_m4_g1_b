# Name des ausführbaren Programms
PROG = main
TEST_PROG = runTests

# Compiler, der verwendet werden soll
CC = g++

# Compilerflags: Warnungen aktivieren und C++14-Standard erzwingen
CFLAGS = -Wall -Wextra -std=c++14

# Linker-Flags
LDFLAGS = -lgtest -lgtest_main -pthread

# Verzeichnisse
SRCDIR = src/reversi
TESTDIR = test/reversi
GTEST_DIR = /usr/local/include/gtest

# Liste der Quelldateien
SRCS = $(SRCDIR)/Board.cpp $(SRCDIR)/GameManager.cpp $(SRCDIR)/Menu.cpp $(SRCDIR)/Player.cpp $(SRCDIR)/main.cpp
TEST_SRCS = $(TESTDIR)/BoardTest.cpp $(TESTDIR)/GameManagerTest.cpp $(TESTDIR)/MenuTest.cpp $(TESTDIR)/PlayerTest.cpp

# Ausgabeverzeichnis
OUTPUT_DIR = output

# Umwandlung der Quelldateien in Objektdateien
OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(OUTPUT_DIR)/%.o)
TEST_OBJS = $(TEST_SRCS:$(TESTDIR)/%.cpp=$(OUTPUT_DIR)/%.o)

# Bibliotheken, die beim Linken verwendet werden sollen
LIBS = -lstdc++

# Standardziel, das gebaut wird, wenn kein spezifisches Ziel angegeben wird
all: $(OUTPUT_DIR) $(PROG) $(TEST_PROG)

# Regel, um das Ausgabeverzeichnis zu erstellen
$(OUTPUT_DIR):
	mkdir -p $(OUTPUT_DIR)

# Regel, um das Programm zu linken und das endgültige ausführbare Programm zu erstellen
$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(OUTPUT_DIR)/$(PROG) $(LIBS)

$(TEST_PROG): $(TEST_OBJS) $(OBJS)
	$(CC) $(CFLAGS) $(TEST_OBJS) $(OBJS) -o $(OUTPUT_DIR)/$(TEST_PROG) $(LDFLAGS)

# Regel, um Objektdateien zu kompilieren
$(OUTPUT_DIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -I$(SRCDIR) -I$(GTEST_DIR) -o $@ -c $<

$(OUTPUT_DIR)/%.o: $(TESTDIR)/%.cpp
	$(CC) $(CFLAGS) -I$(SRCDIR) -I$(GTEST_DIR) -o $@ -c $<

# Regel, um alle Zwischendateien und das ausführbare Programm zu löschen
clean:
	rm -rf $(OUTPUT_DIR) $(PROG) $(TEST_PROG)

# Regel, um das Programm auszuführen
run: $(PROG)
	./$(OUTPUT_DIR)/$(PROG)

# Regel, um die Tests auszuführen
test: $(TEST_PROG)
	./$(OUTPUT_DIR)/$(TEST_PROG)
