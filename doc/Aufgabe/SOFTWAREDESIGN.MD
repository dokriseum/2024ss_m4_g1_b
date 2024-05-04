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

# 2. Traceability-Tabelle

Die Traceability-Tabelle wird folgendermaßen aufgebaut:
- **Anforderungs-ID**: Jede spezifische Anforderung (z.B. SR-005) wird aufgelistet.
- **Beschreibung**: Eine kurze Beschreibung der Anforderung.
- **Implementierung**: Hier wird angegeben, in welchen Klassen und Methoden die Anforderung implementiert wird.

# 3. Implementierung

## a) Grundstruktur
Die Implementierung beginnt mit der Erstellung der Hauptklassen (`Game`, `Board`, `Player`, `HumanPlayer`, `AIPlayer`, `GameUI`, `FileManager`) und deren Methoden entsprechend dem Entwurf.

## b) Implementierungsdetails
- **Spiellogik**: Die Spielregeln werden im `Board` implementiert, einschließlich der Validierung der Züge und der Aktualisierung des Spielfelds.
- **Benutzeroberfläche**: Die `GameUI` Klasse wird Methoden zum Anzeigen des Spielbretts und zur Interaktion mit dem Spieler enthalten.
- **KI-Logik**: Die `AIPlayer` Klasse implementiert die KI-Logik für den Computergegner.
- **Datenpersistenz**: Die `FileManager` Klasse kümmert sich um das Speichern und Laden von Spielen sowie das Aufzeichnen von Spielstatistiken.

## c) Doxygen-Kommentare
Jede Methode und Klasse wird mit Doxygen-Kommentaren dokumentiert, um die Funktionsweise und die Schnittstellen klar zu definieren.

# 4. Testing
Schließlich wird das System umfassend getestet, um sicherzustellen, dass alle Anforderungen korrekt implementiert wurden und das Spiel korrekt funktioniert.

Ich werde mit der Erstellung der Klassendiagramme und der detaillierteren Planung beginnen, gefolgt von der Erstellung der Traceability-Tabelle und der eigentlichen Codierung.