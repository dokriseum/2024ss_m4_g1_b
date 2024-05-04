classDiagram
    class Game {
        +start()
        +saveGame()
        +loadGame()
        +updateGameState()
    }
    class Board {
        +initialize()
        +placeStone(int, int, char)
        +flipStones(int, int)
        +checkFull()
        +calculateScore()
    }
    class Player {
        <<abstract>>
        +makeMove()
    }
    class HumanPlayer {
        +selectMove()
    }
    class AIPlayer {
        +calculateBestMove()
    }
    class GameUI {
        +displayBoard()
        +displayScore()
        +promptMove()
        +showEndGameResults()
    }
    class FileManager {
        +saveToFile()
        +loadFromFile()
        +logStats()
    }

    Game "1" --> "1" Board : contains
    Game "1" --> "2" Player : interacts
    Game "1" --> "1" GameUI : uses
    Game "1" --> "1" FileManager : uses
    Player <|-- HumanPlayer
    Player <|-- AIPlayer

----

sequenceDiagram
    participant UI as GameUI
    participant Game
    participant Board
    participant Player as HumanPlayer
    participant AI as AIPlayer

    UI->>Game: startGame()
    Game->>Board: initialize()
    Board-->>Game: Board initialized
    loop Game Loop
        Game->>UI: displayBoard()
        UI->>Player: promptMove()
        Player-->>Game: move(row, col)
        Game->>Board: placeStone(row, col, 'black')
        Board->>Game: stone placed
        alt Game not over
            Game->>AI: calculateBestMove()
            AI-->>Game: move(row, col)
            Game->>Board: placeStone(row, col, 'white')
            Board->>Game: stone placed
        else Game over
            Game->>UI: showEndGameResults()
        end
    end


----

stateDiagram-v2
    [*] --> Idle
    Idle --> GameRunning : startGame()
    GameRunning --> GamePaused : pauseGame()
    GamePaused --> GameRunning : resumeGame()
    GameRunning --> GameOver : checkFull() or no more moves
    GameOver --> Idle : resetGame() or closeGame()
    GameOver --> [*] : exitGame()

