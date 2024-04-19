# Anforderungen (EARS)

## Definition
|                           | Definition | Syntax |
| ------------------------- | ---------- | ------ |
| Ubiquitous requirements   | Anforderungen, die immer aktiv sind | `<actor> SHALL <action> <object>` |
| State-driven requirements | Anforderungen, die während der gesamten Zeit, in der ein definierter Zustand gilt, aktiv sind | `WHILE <precondition> <actor> SHALL <action> <object>` |
| Event-driven requirements | Anforderungen, die nur dann eine Reaktion erfordern, wenn ein Ereignis an der Grenze erkannt wird | `WHEN <trigger> <actor> SHALL <action> <object>` |

## Aufgabe/Abgabe (englisch)

1. the system SHALL support two players, one being human and the other AI/CPU.
2. the system SHALL use a game board of size 8x8.
3. the system SHALL support the two colours black and white
4. the system SHALL always keep the centre four squares of the board occupied diagonally with two black and two white pieces.
5. the system SHALL display the current board.
6. WHILE the game starts, black SHALL always make the first move.
7. WHILE it is a player's turn, the player SHALL place a piece adjacent to at least one other piece.
8. WHEN a new game begins, the human player SHALL be able to choose his colour.
9. WHEN a player makes a move, the piece SHALL be placed on a square that has its own colour on the line.
10. WHEN a player selects an invalid square, the system SHALL not make a move (and issue an error message).
11. WHEN a move is made, the system SHALL count how many pieces of each colour are on the board.
12. WHEN the board is full or no more moves are possible, the system SHALL give the final result as a win, loss or draw based on the majority of pieces.
13. WHEN the player wishes to save the game, the system SHALL save the current score.
14. WHEN the player wants to load a saved game, the system SHALL load the saved score.
15. WHEN the game ends, the system SHALL record statistics on the number of games won, lost and drawn.

## Aufgabe/Abgabe (deutsch)

1. Das System MUSS zwei Spieler unterstützen, wobei einer Mensch und der andere KI/CPU ist.
2. Das System MUSS ein Spielbrett der Größe 8x8 verwenden.
3. Das System MUSS die zwei Farben Schwarz und Weiß unterstützen.
4. Das System MUSS die mittleren vier Felder des Bretts immer mit zwei schwarzen und zwei weißen Steinen diagonal belegt halten.
5. Das System MUSS das aktuelle Spielfeld anzeigen.
6. WENN das Spiel beginnt, MUSS Schwarz immer den ersten Zug machen.
7. WENN ein Spieler am Zug ist, MUSS der Spieler einen Stein an mindestens einen anderen Stein angrenzend anlegen.
8. SOBALD ein neues Spiel beginnt, MUSS der menschliche Spieler seine Farbe auswählen können.
9. SOBALD ein Spieler einen Zug macht, MUSS der Stein auf einem Feld platziert werden, welcher eine eigene Farbe auf der Linie vorliegend hat.
10. SOBALD ein Spieler ein ungültiges Feld auswählt, MUSS das System keinen Zug machen (und eine Fehlermeldung ausgeben).
11. SOBALD ein Zug gemacht wurde, MUSS das System zählen, wie viele Steine jeder Farbe auf dem Brett liegen.
12. SOBALD das Spielbrett voll ist oder keine weiteren Züge möglich sind, MUSS das System das Endergebnis als Gewonnen, Verloren oder Unentschieden basierend auf der Mehrheit der Steine ausgeben.
13. SOBALD der Spieler das Spiel speichern möchte, MUSS das System den aktuellen Spielstand speichern.
14. SOBALD der Spieler ein gespeichertes Spiel laden möchte, MUSS das System den gespeicherten Spielstand laden.
15. SOBALD das Spiel endet, MUSS das System eine Statistik über die Anzahl der gewonnenen, verlorenen und unentschiedenen Spiele aufzeichnen.

----

**fachliche Erklärungen**

- [Erklärungen zur Anforderungsanalyse](https://gitlab.rz.htw-berlin.de/m14_vv/2024ss_m4_g1_b/-/wikis/Erkl%C3%A4rungen-Anforderungsanalyse)
