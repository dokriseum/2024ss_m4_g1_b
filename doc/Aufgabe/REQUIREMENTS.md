# Anforderungen (EARS)

## Definition
|                           | Definition | Syntax |
| ------------------------- | ---------- | ------ |
| Ubiquitous requirements   | Anforderungen, die immer aktiv sind | `<actor> SHALL <action> <object>` |
| State-driven requirements | Anforderungen, die während der gesamten Zeit, in der ein definierter Zustand gilt, aktiv sind | `WHILE <precondition> <actor> SHALL <action> <object>` |
| Event-driven requirements | Anforderungen, die nur dann eine Reaktion erfordern, wenn ein Ereignis an der Grenze erkannt wird | `WHEN <trigger> <actor> SHALL <action> <object>` |

## Aufgabe/Abgabe (englisch)

SR-001. the system SHALL support two players, one being human and the other AI/CPU.
SR-002. the system SHALL use a game board of size 8x8.
SR-003. the system SHALL support the two colours black and white
SR-004. the system SHALL always keep the centre four squares of the board occupied diagonally with two black and two white pieces.
SR-005. the system SHALL display the current board.
SR-006. WHEN the game starts, black SHALL always make the first move.
SR-007. WHILE it is a player's turn, the player SHALL place a piece adjacent to at least one other piece.
SR-008. WHEN a new game begins, the human player SHALL be able to choose his colour.
SR-009. WHEN a player makes a move, the piece SHALL be placed on a square that has its own colour on the line.
SR-010. WHEN a player selects an invalid square, the system SHALL not make a move (and issue an error message).
SR-011. WHEN a move is made, the system SHALL count how many pieces of each colour are on the board.
SR-012. WHEN the board is full or no more moves are possible, the system SHALL give the final result as a win, loss or draw based on the majority of pieces.
SR-013. WHEN the player wishes to save the game, the system SHALL save all positions and the order of play to a file.
SR-014. WHEN the player wishes to load a saved game, the system SHALL load the file with the saved positions and sequence.
SR-015. WHEN the game ends, the system SHALL record statistics on the number of games won, lost and drawn.

## Aufgabe/Abgabe (deutsch)

### A) Kommandoausgabe
SR-005. Das System MUSS das Spielfeld im ASCII-Format anzeigen.
SR-017. WENN der Spieler eine Position auswählt, MUSS das Spielbrett auf der Kommandozeile aktualisiert werden.
SR-018. SOBALD die KI/CPU ihren Zug beendet, MUSS eine Eingabeauforderung an den Spieler starten.
SR-012. SOBALD das Spielbrett voll ist oder keine weiteren Züge möglich sind, MUSS das System das Endergebnis als Gewonnen, Verloren oder Unentschieden basierend auf der Mehrheit der Steine ausgeben.


### B) Persistenz
SR-013. SOBALD der Spieler das Spiel speichern möchte, MUSS das System alle Positionen und die Spielreihenfolge in eine Datei speichern.
SR-014. SOBALD der Spieler ein gespeichertes Spiel laden möchte, MUSS das System die Datei mit den gespeicherten Positionen und Reihenfolge laden.
SR-015. SOBALD das Spiel endet, MUSS das System eine Statistik über die Anzahl der gewonnenen, verlorenen und unentschiedenen Spiele aufzeichnen.

### C) Spielregeln
SR-001. Das System MUSS zwei Spieler unterstützen, wobei einer Mensch und der andere KI/CPU ist.
SR-002. Das System MUSS ein Spielbrett der Größe 8x8 verwenden.
SR-003. Das System MUSS die zwei Farben Schwarz und Weiß unterstützen.
SR-004. Das System MUSS die mittleren vier Felder des Bretts immer mit zwei schwarzen und zwei weißen Steinen diagonal belegt halten.
SR-006. SOBALD das Spiel beginnt, MUSS Schwarz immer den ersten Zug machen.
SR-007. WENN ein Spieler am Zug ist, MUSS der Spieler einen Stein an mindestens einen anderen Stein angrenzend anlegen.
SR-008. SOBALD ein neues Spiel beginnt, MUSS der menschliche Spieler seine Farbe auswählen können.
SR-009. SOBALD ein Spieler einen Zug macht, MUSS der Stein auf einem Feld platziert werden, welcher eine eigene Farbe auf der Linie vorliegend hat.
SR-010. SOBALD ein Spieler ein ungültiges Feld auswählt, MUSS das System keinen Zug machen (und eine Fehlermeldung ausgeben).
SR-011. SOBALD ein Zug gemacht wurde, MUSS das System zählen, wie viele Steine jeder Farbe auf dem Brett liegen.


----

**fachliche Erklärungen**

- [Erklärungen zur Anforderungsanalyse](https://gitlab.rz.htw-berlin.de/m14_vv/2024ss_m4_g1_b/-/wikis/Erkl%C3%A4rungen-Anforderungsanalyse)
