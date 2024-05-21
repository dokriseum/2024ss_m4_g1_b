

#ifndef INC_2024SS_M4_G1_B_PLAYER_H
#define INC_2024SS_M4_G1_B_PLAYER_H


class Player {
protected:
    char color; // 'B' for Black, 'W' for White

public:
    Player(char color) : color(color) {}
    virtual ~Player() {}
    virtual void makeMove(int& x, int& y) = 0;
    char getColor() const { return color; }
};

class HumanPlayer : public Player {
public:
    HumanPlayer(char color) : Player(color) {}
    void makeMove(int& x, int& y) override {
        std::cout << "Enter move for " << color << " (row col): ";
        std::cin >> x >> y;
    }
};

class AIPlayer : public Player {
public:
    AIPlayer(char color) : Player(color) {}
    void makeMove(int& x, int& y) override {
        // AI logic to determine best move
        x = y = 0; // Placeholder
    }
};



#endif //INC_2024SS_M4_G1_B_PLAYER_H
