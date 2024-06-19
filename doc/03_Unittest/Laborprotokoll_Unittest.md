# Laborprotokoll zu Unit Tests mit Google Test

## Einführung

Dieses Laborprotokoll dokumentiert die Implementierung und Durchführung von Unit Tests für das Reversi-Projekt unter Verwendung von Google Test. Ziel ist es, mindestens 10 Unit Tests zu definieren, um die Funktionalität des Codes zu überprüfen und potenzielle Fehler frühzeitig zu erkennen.

## Vorgehensweise

1. **Installation von Google Test**:
   - Google Test wurde mittels des Quellcode vom GitHub-Repository installiert:
```bash
git clone https://github.com/google/googletest
cd googletest
mkdir build
cd build
cmake ..
make
make install
```

2. **Einrichtung der Verzeichnisstruktur**:
   - Die Verzeichnisstruktur wurde angepasst, um die Quell- und Testdateien zu trennen:
     ```
     Repo/
     ├── src/
     │   └── reversi/
     │       ├── Board.cpp
     │       ├── Board.h
     │       ├── GameManager.cpp
     │       ├── GameManager.h
     │       ├── Menu.cpp
     │       ├── Menu.h
     │       ├── Player.cpp
     │       ├── Player.h
     │       └── main.cpp
     ├── test/
     │   └── reversi/
     │       ├── BoardTest.cpp
     │       ├── GameManagerTest.cpp
     │       ├── MenuTest.cpp
     │       ├── PlayerTest.cpp
     ├── output/
     └── Makefile
     ```

3. **Erstellung der Makefile**:
   - Die `Makefile`-Datei wurde so angepasst, dass alle Quelldateien korrekt kompiliert und die Unit Tests mit Google Test ausgeführt werden können:

    ```makefile
    PROG = main
    TEST_PROG = runTests
    
    CC = g++
    CFLAGS = -Wall -Wextra -std=c++14
    
    LDFLAGS = -lgtest -lgtest_main -pthread
    
    
    SRCDIR = src/reversi
    TESTDIR = test/reversi
    GTEST_DIR = /usr/local/include/gtest
    
    SRCS = $(SRCDIR)/Board.cpp $(SRCDIR)/GameManager.cpp $(SRCDIR)/Menu.cpp $(SRCDIR)/Player.cpp $(SRCDIR)/main.cpp
    TEST_SRCS = $(TESTDIR)/BoardTest.cpp $(TESTDIR)/GameManagerTest.cpp $(TESTDIR)/MenuTest.cpp $(TESTDIR)/PlayerTest.cpp
    
    OUTPUT_DIR = output
    
    OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(OUTPUT_DIR)/%.o)
    TEST_OBJS = $(TEST_SRCS:$(TESTDIR)/%.cpp=$(OUTPUT_DIR)/%.o)
    
    LIBS = -lstdc++
    
    all: $(OUTPUT_DIR) $(PROG) $(TEST_PROG)
    
    $(OUTPUT_DIR):
        mkdir -p $(OUTPUT_DIR)
    
    $(PROG): $(OUTPUT_DIR)/main.o $(filter-out $(OUTPUT_DIR)/main.o, $(OBJS))
        $(CC) $(CFLAGS) $(OBJS) -o $(OUTPUT_DIR)/$(PROG) $(LIBS)
    
    $(TEST_PROG): $(TEST_OBJS) $(filter-out $(OUTPUT_DIR)/main.o, $(OBJS))
        $(CC) $(CFLAGS) $(TEST_OBJS) $(filter-out $(OUTPUT_DIR)/main.o, $(OBJS)) -o $(OUTPUT_DIR)/$(TEST_PROG) $(LDFLAGS)
    
    $(OUTPUT_DIR)/%.o: $(SRCDIR)/%.cpp
        $(CC) $(CFLAGS) -I$(SRCDIR) -I$(GTEST_DIR) -o $@ -c $<
    
    $(OUTPUT_DIR)/%.o: $(TESTDIR)/%.cpp
        $(CC) $(CFLAGS) -I$(SRCDIR) -I$(GTEST_DIR) -o $@ -c $<
    
    clean:
        rm -rf $(OUTPUT_DIR) $(PROG) $(TEST_PROG)
    
    run: $(PROG)
        ./$(OUTPUT_DIR)/$(PROG)
    
    test: $(TEST_PROG)
        ./$(OUTPUT_DIR)/$(TEST_PROG)
    ```

4. **Implementierung der Unit Tests**:
   - Die Unit Tests wurden in den Dateien `BoardTest.cpp`, `GameManagerTest.cpp`, `MenuTest.cpp` und `PlayerTest.cpp` definiert.

### Definition der Tests

- **BoardTest.cpp**:
  - Testet die Initialisierung des Spielfelds.
  - Testet, ob das Spielfeld vollständig ist.

- **GameManagerTest.cpp**:
  - Testet den Spielerwechsel.
  - Testet, ob das Spiel vorbei ist.

- **MenuTest.cpp**:
  - Testet die Ausgabe des Menüs.

- **PlayerTest.cpp**:
  - Testet die Rückgabe des Spielerzeichens.

## Ausführung der Tests

Die Tests wurden mit dem folgenden Befehl ausgeführt:

```bash
make test
```

### Ergebnisse der Tests

Alle definierten Tests wurden erfolgreich kompiliert und ausgeführt. Die Ergebnisse waren wie erwartet und es wurden keine Fehler im Code gefunden.

## Fazit

Die Implementierung und Ausführung der Unit Tests mit Google Test verliefen erfolgreich. Alle definierten Tests konnten erfolgreich ausgeführt werden und es wurden keine Fehler im Code festgestellt. Die Verwendung von Google Test ermöglicht es, die Qualität des Codes durch automatisierte Tests sicherzustellen und potenzielle Fehler frühzeitig zu erkennen.
