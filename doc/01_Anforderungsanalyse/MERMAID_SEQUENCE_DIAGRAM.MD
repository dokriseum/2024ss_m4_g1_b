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
