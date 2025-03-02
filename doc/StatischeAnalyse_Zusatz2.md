# Zusatzaufgabe 2

## Automatische Prüfung der Kundenanforderung mit `lizard`

**Kundenanforderung**: Quelltext von Funktionen soll nicht länger als 20 Zeilen sein.

1. **Installation von `lizard`**:
   - `lizard` wurde mittels Pip installiert:
     ```bash
     pip install lizard
     ```

2. **Durchführung der Analyse**:
   - Die Analyse wurde mit dem folgenden Befehl durchgeführt:
     ```bash
     lizard -l cpp -L 20 *.cpp > lizard_report.txt
     ```

3. **Dokumentation der Ergebnisse**:
   - Die Ergebnisse der Analyse wurden in der Datei `lizard_report.txt` gespeichert.

## Prüfergebnis

### Funktionen, die länger als 20 Zeilen sind

| Datei               | Funktion        | Zeilenanzahl |
|---------------------|-----------------|--------------|
| `Board.cpp`         | `isValidMove`   | 23           |
| `Board.cpp`         | `makeMove`      | 21           |
| `GameManager.cpp`   | `loadGame`      | 42           |
| `GameManager.cpp`   | `play`          | 22           |
| `Menu.cpp`          | `run`           | 28           |
| `Player.cpp`        | `makeMove`      | 26           |

### Lösungsvorschläge

- **Funktion `isValidMove`**: Diese Funktion könnte durch die Einführung von Hilfsfunktionen zur Überprüfung einzelner Bedingungen verkürzt werden.
- **Funktion `makeMove`**: Diese Funktion könnte durch Einführung von Hilfsfunktionen zur Verarbeitung von Spielzügen verkürzt werden.
- **Funktion `loadGame`**: Diese Funktion könnte in kleinere Funktionen zur Dateioperation und zum Einlesen der Daten aufgeteilt werden.
- **Funktion `play`**: Diese Funktion könnte in mehrere kleinere Funktionen aufgeteilt werden, um die Lesbarkeit und Wartbarkeit zu verbessern.
- **Funktion `run`**: Diese Funktion könnte durch die Auslagerung der Menüverarbeitung in separate Funktionen verkürzt werden.
- **Funktion `makeMove`**: Diese Funktion könnte durch Einführung von Hilfsfunktionen zur Verarbeitung von Spielzügen verkürzt werden.


## Fazit

----

# lizard_report.txt

```
================================================
  NLOC    CCN   token  PARAM  length  location  
------------------------------------------------
       7      1     76      0       7 Board::Board@3-9@Board.cpp
      15      4    136      0      15 Board::display@11-25@Board.cpp
      10      4     42      0      10 Board::isFull@27-36@Board.cpp
      22     21    202      4      23 Board::isValidMove@38-60@Board.cpp
      20     17    211      4      21 Board::makeMove@62-82@Board.cpp
       3      1     22      2       3 Board::getPiece@84-86@Board.cpp
       3      1     25      3       3 Board::setPiece@88-90@Board.cpp
      11      4     49      1      11 Board::countPieces@92-102@Board.cpp
       8      1     39      0       8 GameManager::GameManager@8-15@GameManager.cpp
       4      1     13      0       5 GameManager::~GameManager@17-21@GameManager.cpp
       3      2     19      0       3 GameManager::switchPlayer@23-25@GameManager.cpp
      12      6     80      0      12 GameManager::isGameOver@27-38@GameManager.cpp
      11      3     57      0      11 GameManager::getWinner@40-50@GameManager.cpp
      18      4    148      1      18 GameManager::saveGame@52-69@GameManager.cpp
      42     12    315      1      42 GameManager::loadGame@71-112@GameManager.cpp
      18      2     84      0      18 GameManager::chooseColour@114-131@GameManager.cpp
       7      2     43      0       7 GameManager::printCurrentPlayer@133-139@GameManager.cpp
      22      5    128      0      22 GameManager::play@141-162@GameManager.cpp
       5      1     44      0       5 Menu::display@5-9@Menu.cpp
      27      5    112      0      28 Menu::run@11-38@Menu.cpp
       4      1     16      0       4 Menu::runTests@40-43@Menu.cpp
       1      1     14      1       1 Player::Player@8-8@Player.cpp
       3      1     11      0       3 Player::getPiece@10-12@Player.cpp
       2      1      7      0       3 Player::~Player@14-16@Player.cpp
       1      1     14      1       1 HumanPlayer::HumanPlayer@18-18@Player.cpp
      26     10    220      1      26 HumanPlayer::makeMove@20-45@Player.cpp
       1      1     14      1       1 ComputerPlayer::ComputerPlayer@47-47@Player.cpp
      10      6     86      1      10 ComputerPlayer::makeMove@49-58@Player.cpp
       9      3     54      2       9 main@13-21@main.cpp
5 file analyzed.
==============================================================
NLOC    Avg.NLOC  AvgCCN  Avg.token  function_cnt    file
--------------------------------------------------------------
     92      11.4     6.6       95.4         8     Board.cpp
    150      14.5     3.8       92.6        10     GameManager.cpp
     39      12.0     2.3       57.3         3     Menu.cpp
     49       6.3     3.0       52.3         7     Player.cpp
     11       9.0     3.0       54.0         1     main.cpp

=========================================================================================================
!!!! Warnings (cyclomatic_complexity > 15 or length > 20 or nloc > 1000000 or parameter_count > 100) !!!!
================================================
  NLOC    CCN   token  PARAM  length  location  
------------------------------------------------
      22     21    202      4      23 Board::isValidMove@38-60@Board.cpp
      20     17    211      4      21 Board::makeMove@62-82@Board.cpp
      42     12    315      1      42 GameManager::loadGame@71-112@GameManager.cpp
      22      5    128      0      22 GameManager::play@141-162@GameManager.cpp
      27      5    112      0      28 Menu::run@11-38@Menu.cpp
      26     10    220      1      26 HumanPlayer::makeMove@20-45@Player.cpp
==========================================================================================
Total nloc   Avg.NLOC  AvgCCN  Avg.token   Fun Cnt  Warning cnt   Fun Rt   nloc Rt
------------------------------------------------------------------------------------------
       341      11.2     4.2       78.7       29            6      0.21    0.49
```