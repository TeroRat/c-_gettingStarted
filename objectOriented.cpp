#include <iostream>
#include <vector>

using namespace std;

class TicTacToe {
public:
  TicTacToe() {
    board = vector<char>(9, ' ');
  }

  void play() {
    while (true) {
      // Get the player's move.
      int row, col;
      cout << "Enter your move (row, col): ";
      cin >> row >> col;

      // Make the move.
      board[row * 3 + col] = (turn == 1) ? 'X' : 'O';

      // Check if the game is over.
      if (is_winner(row, col)) {
        cout << "Player " << turn << " wins!" << endl;
        break;
      } else if (is_draw()) {
        cout << "The game is a draw!" << endl;
        break;
      }

      // Switch turns.
      turn = (turn == 1) ? 2 : 1;
    }
  }

private:
  vector<char> board;
  int turn = 1;

  bool is_winner(int row, int col) {
    // Check for a row win.
    for (int i = 0; i < 3; i++) {
      if (board[i * 3] == board[i * 3 + 1] && board[i * 3 + 1] == board[i * 3 + 2] && board[i * 3] != ' ') {
        return true;
      }
    }

    // Check for a column win.
    for (int i = 0; i < 3; i++) {
      if (board[i] == board[i + 3] && board[i + 3] == board[i + 6] && board[i] != ' ') {
        return true;
      }
    }

    // Check for a diagonal win.
    if (board[0] == board[4] && board[4] == board[8] && board[0] != ' ') {
      return true;
    }

    if (board[2] == board[4] && board[4] == board[6] && board[2] != ' ') {
      return true;
    }

    return false;
  }

  bool is_draw() {
    for (int i = 0; i < 9; i++) {
      if (board[i] == ' ') {
        return false;
      }
    }

    return true;
  }
};

int main() {
  TicTacToe game;
  game.play();
  return 0;
}
