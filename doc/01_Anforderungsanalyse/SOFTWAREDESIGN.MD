# 1. Software-Entwurf

## a) Klassendiagramm
Wir beginnen mit einem UML-Klassendiagramm, um die Hauptkomponenten unseres Systems zu visualisieren:

- **Game**: Hauptklasse zur Steuerung des Spielablaufs. Verwaltet Spielstatus, Spieler und das Spielbrett.
- **Board**: Repräsentiert das 8x8-Spielfeld und ist verantwortlich für die Spiellogik wie das Platzieren der Steine und das Umdrehen der gegnerischen Steine.
- **Player**: Abstrakte Basisklasse für Spieler. Von dieser Klasse leiten sich zwei Klassen ab:
  - **HumanPlayer**: Für menschliche Spieler.
  - **AIPlayer**: Für den KI-Spieler, der die Züge des Computers ausführt.
- **GameUI**: Klasse für die Benutzeroberfläche in der Kommandozeile, zeigt das Spielbrett und Nachrichten an.
- **FileManager**: Verwaltet das Speichern und Laden von Spielständen sowie das Speichern von Statistiken.

## b) Sequenzdiagramme
Für wichtige Abläufe erstellen wir Sequenzdiagramme, z.B. für das Starten eines Spiels, das Machen eines Zuges und das Speichern eines Spiels.

## c) Zustandsdiagramm
Ein Zustandsdiagramm beschreibt die verschiedenen Zustände des Spiels, wie "Spiel läuft", "Spiel pausiert" und "Spiel beendet".

# 2. Implementierung

## a) Grundstruktur
Die Implementierung beginnt mit der Erstellung der Hauptklassen (`Game`, `Board`, `Player`, `HumanPlayer`, `AIPlayer`, `GameUI`, `FileManager`) und deren Methoden entsprechend dem Entwurf.

## b) Implementierungsdetails
- **Spiellogik**: Die Spielregeln werden im `Board` implementiert, einschließlich der Validierung der Züge und der Aktualisierung des Spielfelds.
- **Benutzeroberfläche**: Die `GameUI` Klasse wird Methoden zum Anzeigen des Spielbretts und zur Interaktion mit dem Spieler enthalten.
- **KI-Logik**: Die `AIPlayer` Klasse implementiert die KI-Logik für den Computergegner.
- **Datenpersistenz**: Die `FileManager` Klasse kümmert sich um das Speichern und Laden von Spielen sowie das Aufzeichnen von Spielstatistiken.

## c) Doxygen-Kommentare
Jede Methode und Klasse wird mit Doxygen-Kommentaren dokumentiert, um die Funktionsweise und die Schnittstellen klar zu definieren.

# 3. Testing
Schließlich wird das System umfassend getestet, um sicherzustellen, dass alle Anforderungen korrekt implementiert wurden und das Spiel korrekt funktioniert.

Ich werde mit der Erstellung der Klassendiagramme und der detaillierteren Planung beginnen, gefolgt von der Erstellung der Traceability-Tabelle und der eigentlichen Codierung.

----

# Implementierungskomponenten

| Anforderungs-ID | Beschreibung                                                                 | Implementierungskomponenten                                         |
|-----------------|------------------------------------------------------------------------------|---------------------------------------------------------------------|
| SR-005          | Das System MUSS das Spielfeld im ASCII-Format anzeigen.                      | `GameUI.displayBoard()`                                            |
| SR-017          | WENN der Spieler eine Position auswählt, MUSS das Spielbrett aktualisiert werden. | `GameUI.promptMove()`, `Board.placeStone()`, `GameUI.displayBoard()` |
| SR-018          | SOBALD die KI/CPU ihren Zug beendet, MUSS eine Eingabeaufforderung an den Spieler starten. | `AIPlayer.calculateBestMove()`, `GameUI.promptMove()`               |
| SR-012          | SOBALD das Spielbrett voll ist oder keine weiteren Züge möglich sind, MUSS das System das Endergebnis ausgeben. | `Board.checkFull()`, `Game.updateGameState()`, `GameUI.showEndGameResults()` |
| SR-013          | SOBALD der Spieler das Spiel speichern möchte, MUSS das System alle Positionen und die Spielreihenfolge in eine Datei speichern. | `FileManager.saveToFile()`                                         |
| SR-014          | SOBALD der Spieler ein gespeichertes Spiel laden möchte, MUSS das System die Datei laden. | `FileManager.loadFromFile()`                                       |
| SR-015          | SOBALD das Spiel endet, MUSS das System eine Statistik über die Anzahl der gewonnenen, verlorenen und unentschiedenen Spiele aufzeichnen. | `FileManager.logStats()`                                           |
| SR-001          | Das System MUSS zwei Spieler unterstützen, wobei einer Mensch und der andere KI/CPU ist. | `HumanPlayer`, `AIPlayer`                                          |
| SR-002          | Das System MUSS ein Spielbrett der Größe 8x8 verwenden.                      | `Board` (initialisiert mit 8x8 Feldern)                            |
| SR-003          | Das System MUSS die zwei Farben Schwarz und Weiß unterstützen.               | `Board` (Verwendung von 'black' und 'white' als Farben)            |
| SR-004          | Das System MUSS die mittleren vier Felder des Bretts immer mit zwei schwarzen und zwei weißen Steinen diagonal belegt halten. | `Board.initialize()`                                               |
| SR-006          | SOBALD das Spiel beginnt, MUSS Schwarz immer den ersten Zug machen.          | `Game.start()` (setzt den ersten Spieler als Schwarz)              |
| SR-007          | WENN ein Spieler am Zug ist, MUSS der Spieler einen Stein an mindestens einen anderen Stein angrenzend anlegen. | `Board.placeStone()` (Überprüft Nachbarsteine)                     |
| SR-008          | SOBALD ein neues Spiel beginnt, MUSS der menschliche Spieler seine Farbe auswählen können. | `GameUI.promptForColor()`                                          |
| SR-009          | SOBALD ein Spieler einen Zug macht, MUSS der Stein auf einem Feld platziert werden, welcher eine eigene Farbe auf der Linie vorliegend hat. | `Board.placeStone()` (validiert Linien mit eigener Farbe)          |
| SR-010          | SOBALD ein Spieler ein ungültiges Feld auswählt, MUSS das System keinen Zug machen (und eine Fehlermeldung ausgeben). | `Board.placeStone()` (prüft Gültigkeit, `GameUI.displayError()`)   |
| SR-011          | SOBALD ein Zug gemacht wurde, MUSS das System zählen, wie viele Steine jeder Farbe auf dem Brett liegen. | `Board.calculateScore()`                                           |

# Tracebility-Tabellen

| Anforderungs-ID | Beschreibung                                                                                        | Modul             | Implementierte Methoden                                             | Testfälle                           |
|-----------------|----------------------------------------------------------------------------------------------------|-------------------|----------------------------------------------------------------------|-------------------------------------|
| SR-001          | Das System MUSS zwei Spieler unterstützen, wobei einer Mensch und der andere KI/CPU ist.          | Spielsteuerung    | `Game.initializePlayers()`, `HumanPlayer`, `AIPlayer`                | `testPlayerInitialization`          |
| SR-002          | Das System MUSS ein Spielbrett der Größe 8x8 verwenden.                                            | Spielbrett        | `Board.initializeBoard()`                                            | `testBoardSize`                     |
| SR-003          | Das System MUSS die zwei Farben Schwarz und Weiß unterstützen.                                     | Spielbrett        | `Game.initializeGame()`, `Board.setStoneColor()`                     | `testColorSupport`                  |
| SR-004          | Die mittleren vier Felder des Bretts immer mit zwei schwarzen und zwei weißen Steinen diagonal halten. | Spielbrett        | `Board.initializeBoard()`                                            | `testInitialBoardSetup`             |
| SR-005          | Das System MUSS das Spielfeld im ASCII-Format anzeigen.                                            | Benutzeroberfläche | `GameUI.displayBoard()`                                              | `testDisplayBoard`                  |
| SR-006          | Schwarz beginnt immer den ersten Zug.                                                              | Spielsteuerung    | `Game.startGame()`                                                   | `testFirstMoveBlack`                |
| SR-007          | Spieler muss einen Stein neben mindestens einen anderen legen.                                     | Spiellogik        | `Game.makeMove()`, `Board.isValidMove()`                             | `testValidMove`                     |
| SR-008          | Spieler kann seine Farbe zu Beginn eines Spiels wählen.                                            | Benutzeroberfläche | `GameUI.promptForColor()`, `Game.setPlayerColor()`                   | `testPlayerColorChoice`             |
| SR-009          | Stein muss auf einem Feld platziert werden, welches eine eigene Farbe auf der Linie vorliegend hat. | Spiellogik        | `Board.validateLinePresence()`, `Game.makeMove()`                    | `testValidateLinePresence`          |
| SR-010          | Bei Auswahl eines ungültigen Feldes keinen Zug machen und Fehlermeldung ausgeben.                  | Benutzeroberfläche | `GameUI.displayError()`, `Board.isValidMove()`                       | `testInvalidMove`                   |
| SR-011          | Nach jedem Zug zählen, wie viele Steine jeder Farbe auf dem Brett liegen.                          | Spiellogik        | `Board.calculateScore()`                                             | `testCountStones`                   |
| SR-012          | Ausgabe des Endergebnisses wenn das Brett voll ist oder keine Züge möglich sind.                   | Spielsteuerung    | `Game.checkGameOver()`, `GameUI.showEndGameResults()`                | `testGameOverResults`               |
| SR-013          | Speichern aller Positionen und Spielreihenfolge in eine Datei, wenn der Spieler das Spiel speichern möchte. | Datenverwaltung   | `FileManager.saveGame()`                                             | `testSaveGameFunctionality`         |
| SR-014          | Laden eines gespeicherten Spiels aus einer Datei.                                                  | Datenverwaltung   | `FileManager.loadGame()`                                             | `testLoadGameFunctionality`         |
| SR-015          | Aufzeichnen einer Statistik über gewonnene, verlorene und unentschiedene Spiele am Spielende.     | Datenverwaltung   | `FileManager.logStatistics()`                                        | `testLogGameStatistics`             |
| SR-017          | Aktualisierung des Spielbretts auf der Kommandozeile, wenn der Spieler eine Position wählt.        | Benutzeroberfläche | `Game.makeMove()`, `GameUI.updateBoardDisplay()`                     | `testBoardUpdateOnMove`             |
| SR-018          | Start einer Eingabeaufforderung für den Spieler, sobald die KI/CPU ihren Zug beendet hat.          | Benutzeroberfläche | `Game.nextTurn()`, `GameUI.promptNextMove()`                         | `testPromptAfterAITurn`             |
