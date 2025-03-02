# Laborprotokoll zur statischen Analyse mit Cppcheck

## Einführung

Dieses Laborprotokoll dokumentiert die Ergebnisse der statischen Analyse des Reversi-Projekts unter Verwendung von `cppcheck`. Die Analyse wurde durchgeführt, um potenzielle Fehler, Stilprobleme und andere Probleme im Code zu identifizieren.

## Vorgehensweise

1. **Installation von Cppcheck**:
   - Cppcheck wurde mittels Homebrew installiert:
     ```bash
     brew install cppcheck
     ```

2. **Durchführung der Analyse**:
   - Die Analyse wurde mit den folgenden Befehlen durchgeführt:
     ```bash
     cd /path/to/your/project
     cppcheck --enable=all --inconclusive --check-config -I /usr/include -I /usr/local/include . 2> cppcheck_report.txt
     ```

3. **Dokumentation der Ergebnisse**:
   - Die Ergebnisse der Analyse wurden in der Datei `cppcheck_report.txt` gespeichert.

## Ergebnisse

### Zusammenfassung der Probleme

| Typ               | Häufigkeit | Ähnlichkeit | Schwere |
|-------------------|------------|-------------|---------|
| Fehlende virtuelle Destruktoren | 2          | Hoch        | Hoch    |
| Veraltete Syntax  | 1          | Mittel      | Mittel  |
| Potenzieller Ressourcenleck  | 1          | Gering      | Hoch    |

### Detaillierte Probleme

#### 1. Fehlende virtuelle Destruktoren
- **Datei**: `Player.h`
- **Beschreibung**: Klassen `Player`, die von `HumanPlayer` und `ComputerPlayer` geerbt werden, haben keinen virtuellen Destruktor.
- **Schwere**: Hoch
- **Lösung**: Einen virtuellen Destruktor zur `Player`-Klasse hinzufügen.

  ```cpp
  virtual ~Player();
