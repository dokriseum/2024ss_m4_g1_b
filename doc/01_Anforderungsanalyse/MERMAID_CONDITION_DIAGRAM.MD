stateDiagram-v2
    [*] --> Idle
    Idle --> GameRunning : startGame()
    GameRunning --> GamePaused : pauseGame()
    GamePaused --> GameRunning : resumeGame()
    GameRunning --> GameOver : checkFull() or no more moves
    GameOver --> Idle : resetGame() or closeGame()
    GameOver --> [*] : exitGame()
