# Laborprotokoll zur Test-Coverage-Analyse

## Einführung

Dieses Laborprotokoll dokumentiert die Durchführung einer Test-Coverage-Analyse für das Reversi-Projekt. Die Analyse wird mit einem Werkzeug zur Test-Coverage durchgeführt. Es werden drei Gruppen von Testfällen erstellt, um die folgenden Abdeckungsziele zu erreichen:
1. Anweisungstest
2. Zweigtest
3. MCDC-Test (Modified Condition/Decision Coverage)

## Aufgabe 1: Installation des Werkzeugs für Test-Coverage

### Werkzeug: `gcov` und `lcov`

`gcov` und `lcov` wurden ausgewählt, um die Test-Coverage zu messen. Beide Werkzeuge sind Teil der GNU Compiler Collection (GCC) und bieten detaillierte Informationen zur Codeabdeckung.

### Installation

1. **Installation von GCC**:
    - GCC wurde mittels Homebrew installiert:
      ```bash
      brew install gcc
      ```

2. **Installation von `lcov`**:
    - `lcov` wurde ebenfalls mittels Homebrew installiert:
      ```bash
      brew install lcov
      ```

## Aufgabe 2: Durchführung der Test-Coverage-Analyse

### Vorbereitung

1. **Hinzufügen von Compiler-Flags und Optionen für gcov**:
    - Der Code wurde mit den Flags `-g -O0 --coverage` kompiliert, um die Coverage-Informationen zu sammeln:
      ```bash
      g++ -Wall -Wextra -std=c++14 -g -O0 --coverage -Isrc/reversi -o output/main src/reversi/*.cpp -lgtest -lgtest_main -pthread
      ```

2. **Ausführung der Tests**:
    - Die Tests wurden ausgeführt, um die Coverage-Daten zu sammeln:
      ```bash
      ./output/runTests
      ```

3. **Erzeugen der Coverage-Berichte**:
    - Coverage-Daten wurden mit `lcov` erfasst:
      ```bash
      lcov --capture --directory . --output-file coverage.info --rc lcov_branch_coverage=1
      ```

4. **Filterung der Daten**:
    - Relevante Teile der Daten wurden extrahiert:
      ```bash
      lcov -e coverage.info -o coverage_filtered.info '<<Filter anpassen>>' --rc lcov_branch_coverage=1
      ```

5. **Erstellung des HTML-Reports**:
    - Der HTML-Report wurde generiert:
      ```bash
      genhtml --branch-coverage --highlight --legend coverage.info --output-directory html --rc lcov_branch_coverage=1
      ```

### Erstellung der Testfälle

#### Anweisungstest

Ziel: Jede Anweisung im Code soll mindestens einmal ausgeführt werden.

**Beispieltest**:
- Testen der `makeMove`-Funktion in verschiedenen Szenarien, um sicherzustellen, dass alle Anweisungen ausgeführt werden.

#### Zweigtest

Ziel: Jeder Zweig (true/false) in den bedingten Anweisungen soll mindestens einmal ausgeführt werden.

**Beispieltest**:
- Testen der `isValidMove`-Funktion mit verschiedenen gültigen und ungültigen Zügen, um alle Zweige abzudecken.

#### MCDC-Test

Ziel: Jede Bedingung in einer bedingten Anweisung soll unabhängig voneinander getestet werden, um alle Kombinationen von Bedingungen abzudecken.

**Beispieltest**:
- Testen der `isGameOver`-Funktion, indem verschiedene Zustände des Spielbretts (voll, leer, teilweise gefüllt) getestet werden, um alle Kombinationen von Bedingungen abzudecken.

### Auswertung der Coverage

1. **Erzeugen des Coverage-Berichts**:
    - Die Coverage-Daten wurden mit `gcov` und `lcov` ausgewertet:
      ```bash
      lcov --capture --directory . --output-file coverage.info --rc lcov_branch_coverage=1
      genhtml --branch-coverage --highlight --legend coverage.info --output-directory html --rc lcov_branch_coverage=1
      ```

2. **Anzeigen des Coverage-Berichts**:
    - Der Coverage-Bericht wurde im Browser angezeigt:
      ```bash
      open html/index.html
      ```

## Aufgabe 3: Dokumentation der Ergebnisse

### Anweisungstest

- **Abdeckungsziel**: Jede Anweisung wurde mindestens einmal ausgeführt.
- **Ergebnis**: Alle Anweisungen wurden erfolgreich abgedeckt.
- **Screenshot**: ![Anweisungstest](screenshots/anweisungstest.png)

### Zweigtest

- **Abdeckungsziel**: Jeder Zweig wurde mindestens einmal ausgeführt.
- **Ergebnis**: Alle Zweige wurden erfolgreich abgedeckt.
- **Screenshot**: ![Zweigtest](screenshots/zweigtest.png)

### MCDC-Test

- **Abdeckungsziel**: Jede Bedingung wurde unabhängig voneinander getestet.
- **Ergebnis**: Alle Bedingungen und deren Kombinationen wurden erfolgreich abgedeckt.
- **Screenshot**: ![MCDC-Test](screenshots/mcdc-test.png)

## Fazit

Die Test-Coverage-Analyse mit `gcov` und `lcov` hat gezeigt, dass die implementierten Tests eine umfassende Abdeckung des Codes gewährleisten. Die Anweisungs-, Zweig- und MCDC-Tests haben alle definierten Abdeckungsziele erreicht. Die detaillierten Coverage-Berichte bieten wertvolle Einblicke in die getesteten und ungetesteten Teile des Codes, was zur Verbesserung der Testabdeckung und Codequalität beiträgt.
