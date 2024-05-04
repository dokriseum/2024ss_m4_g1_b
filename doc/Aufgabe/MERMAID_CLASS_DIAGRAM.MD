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
