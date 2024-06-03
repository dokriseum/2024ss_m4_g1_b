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
    - Die `Makefile`-Datei wurde so angepasst, dass alle Quelldateien korrekt kompiliert und die Unit Tests mit Google Test ausgeführt werden können.

4. **Implementierung der Unit Tests**:
    - Die Unit Tests wurden in den Dateien `BoardTest.cpp`, `GameManagerTest.cpp`, `MenuTest.cpp` und `PlayerTest.cpp` definiert.

### Definition der Tests

- **BoardTest.cpp**:
    - **Test der Initialisierung**: Überprüft, ob das Spielfeld korrekt initialisiert wird, indem die Anfangspositionen der Spielsteine überprüft werden.
    - **Test der Spielfeldanzeige**: Überprüft, ob die Spielfeldanzeige korrekt funktioniert.
    - **Test auf Vollständigkeit des Spielfelds**: Überprüft, ob das Spielfeld korrekt als voll erkannt wird, wenn keine leeren Felder mehr vorhanden sind.
    - **Test der Gültigkeit von Zügen**: Überprüft, ob Züge korrekt als gültig oder ungültig erkannt werden.
    - **Test der Ausführung von Zügen**: Überprüft, ob Züge korrekt ausgeführt und die Spielsteine entsprechend umgedreht werden.

- **GameManagerTest.cpp**:
    - **Test des Spielerwechsels**: Überprüft, ob der Spielerwechsel korrekt funktioniert.
    - **Test auf Spielende**: Überprüft, ob das Spielende korrekt erkannt wird, wenn keine gültigen Züge mehr möglich sind.
    - **Test der Gewinnerbestimmung**: Überprüft, ob der Gewinner korrekt bestimmt wird, basierend auf der Anzahl der Spielsteine.

- **MenuTest.cpp**:
    - **Test der Menüanzeige**: Überprüft, ob das Menü korrekt angezeigt wird.
    - **Test der Menüauswahl**: Überprüft, ob die Menüauswahl korrekt funktioniert und die entsprechenden Aktionen ausgeführt werden.

- **PlayerTest.cpp**:
    - **Test der Rückgabe des Spielerzeichens**: Überprüft, ob das richtige Zeichen für den Spieler zurückgegeben wird.
    - **Test der Spielzüge des menschlichen Spielers**: Überprüft, ob der menschliche Spieler Züge korrekt eingeben und ausführen kann.
    - **Test der Spielzüge des Computergegners**: Überprüft, ob der Computergegner Züge korrekt ausführt.

## Ausführung der Tests

Die Tests wurden mit dem folgenden Befehl ausgeführt:

```bash
make test
```

### Ergebnisse der Tests

Alle definierten Tests wurden erfolgreich kompiliert und ausgeführt. Die Ergebnisse waren wie erwartet und es wurden keine Fehler im Code gefunden.

## Fazit

Die Implementierung und Ausführung der Unit Tests mit Google Test verliefen erfolgreich. Alle definierten Tests konnten erfolgreich ausgeführt werden und es wurden keine Fehler im Code festgestellt. Die Verwendung von Google Test ermöglicht es, die Qualität des Codes durch automatisierte Tests sicherzustellen und potenzielle Fehler frühzeitig zu erkennen.
