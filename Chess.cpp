#include <iostream>
#include <iomanip>
using namespace std;

class Chessboard;

class Player {
public:
    Player(bool isWhite) : isWhitePlayer(isWhite) {}

    void displayChessboard(const Chessboard& chessboard) const;

private:
    bool isWhitePlayer;
};

class Chessboard {
    friend class Player;

public:
    Chessboard() {
        initializeBoard();
    }

    void display(Player& player) const {
        player.displayChessboard(*this);
    }

    char getPiece(int row, int col) const {
        return board[row][col];
    }

private:
    char board[8][8];

    void initializeBoard() {
        // Ініціалізація шахової дошки
        char initialBoard[8][8] = {
            {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
            {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
            {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
        };

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                board[i][j] = initialBoard[i][j];
            }
        }
    }
};

void Player::displayChessboard(const Chessboard& chessboard) const {
    char horizontalLabels[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };

    cout << "   ";
    for (int i = 0; i < 8; i++) {
        cout << " " << horizontalLabels[i] << "  ";
    }
    cout << endl;

    int startRow = isWhitePlayer ? 7 : 0;
    int endRow = isWhitePlayer ? 0 : 7;
    int step = isWhitePlayer ? -1 : 1;

    for (int i = startRow; i != endRow + step; i += step) {
        cout << " " << i + 1 << " ";
        for (int j = 0; j < 8; j++) {
            char piece = chessboard.getPiece(i, j);
            cout << " " << piece << " ";
        }
        cout << " " << i + 1 << endl;
    }

    cout << "   ";
    for (int i = 0; i < 8; i++) {
        cout << " " << horizontalLabels[i] << "  ";
    }
    cout << endl;
}

int main() {
    int side;

    cout << "Hello, this program shows you the placement of the chessboard depending on your choice!" << "\n";
    cout << "Let's choose the side." << "\n";
    cout << "If you want to choose 'white' press '1';" << "\n";
    cout << "If you want to choose 'black' press '2';" << "\n";
    cin >> side;

    Chessboard chessboard;

    if (side == 1) {
        Player whitePlayer(true);
        chessboard.display(whitePlayer);
    }
    else if (side == 2) {
        Player blackPlayer(false);
        chessboard.display(blackPlayer);
    }
    else {
        cout << "Incorrect input, please change it!";
    }

    return 0;
}
