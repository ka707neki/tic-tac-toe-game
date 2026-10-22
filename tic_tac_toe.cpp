#include <iostream>
#include <string>
using namespace std;

// Prints the 3x3 board with grid lines
void printBoard(const char board[3][3])
{
    cout << "   |   |   " << endl;
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    cout << "   |   |   " << endl;
}

int main()
{
    // ===================== 🧩 Game Setup =====================

    // 3x3 game board, every cell starts empty
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    // Player symbols
    const char playerX = 'X';
    const char playerO = 'O';

    char currentPlayer = playerX;   // X always starts
    int r = -1;                     // row entered by the player
    int c = -1;                     // column entered by the player
    char winner = ' ';              // ' ' means no winner yet

    // ===================== 🔁 Main Game Loop =====================
    // The board has 9 cells, so the game lasts 9 turns at most
    for (int i = 0; i < 9; i++)
    {
        // ---------- 🖼 Print game board ----------
        printBoard(board);

        // ---------- ⌨️ Get player input ----------
        cout << "\n🎮 ==> Current Player is " << currentPlayer << endl;

        // Keep asking until the player enters a valid, empty tile
        while (true)
        {
            cout << "\n========================================" << endl;
            cout << "👉 Enter r c from 0-2 for row and column : ";
            cin >> r >> c;

            if (r < 0 || r > 2 || c < 0 || c > 2)
            {
                // Row or column is outside the board
                cout << "❌ Invalid input, try again." << endl;
            }
            else if (board[r][c] != ' ')
            {
                // The chosen tile is already taken
                cout << "⚠️ Tile is full, try again" << endl;
            }
            else
            {
                // Valid move, leave the input loop
                break;
            }

            // ---------- 🧹 Reset values ----------
            r = -1;
            c = -1;
            cin.clear();              // clear error flags
            cin.ignore(10000, '\n');  // discard leftover input up to the next newline
        }

        // ---------- ✍️ Place the move and switch turns ----------
        board[r][c] = currentPlayer;
        currentPlayer = (currentPlayer == playerX) ? playerO : playerX;

        // ===================== 🏆 Check winners =====================

        // Rows - horizontal
        for (int row = 0; row < 3; row++)
        {
            if (board[row][0] != ' ' && board[row][0] == board[row][1] && board[row][1] == board[row][2])
            {
                winner = board[row][0];
            }
        }

        // Columns - vertical
        for (int col = 0; col < 3; col++)
        {
            if (board[0][col] != ' ' && board[0][col] == board[1][col] && board[1][col] == board[2][col])
            {
                winner = board[0][col];
            }
        }

        // Diagonal - top-left to bottom-right
        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        {
            winner = board[0][0];
        }
        // Diagonal - top-right to bottom-left
        else if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        {
            winner = board[0][2];
        }

        // Game over: someone won, or the board is full. Show the final board.
        if (winner != ' ' || i == 8)
        {
            printBoard(board);
            break;
        }
    }

    // ===================== 🎉 Show Result =====================
    if (winner != ' ')
    {
        cout << "🏆 Player " << winner << " is the winner!" << endl;
    }
    else
    {
        cout << "🤝 Tie!" << endl;
    }

    return 0;
}
