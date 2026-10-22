# ❌⭕ Tic-Tac-Toe (C++)

A two-player Tic-Tac-Toe game for the terminal, written in standard C++ with no external dependencies.

## Features

- Classic 3×3 board rendered in the console
- Two players alternate turns (**X** always starts)
- Input validation: rejects out-of-range coordinates, occupied tiles, and non-numeric input
- Win detection across rows, columns, and both diagonals
- Tie detection when the board fills up
- Final board is displayed before the result

## Requirements

- A C++11 (or newer) compiler such as `g++` or `clang++`
- A terminal with UTF-8 support (for the emoji messages)

## Build & Run

```bash
git clone https://github.com/ka707neki/tic-tac-toe-cpp.git
cd tic-tac-toe-cpp
g++ -std=c++11 -Wall -o tic_tac_toe tic_tac_toe.cpp
./tic_tac_toe
```

## How to Play

Enter the **row** and **column** of your move, separated by a space. Both range from `0` to `2`:

```
 col:  0   1   2
row 0  | 0 0 | 0 1 | 0 2
row 1  | 1 0 | 1 1 | 1 2
row 2  | 2 0 | 2 1 | 2 2
```

Example: entering `1 1` places your mark in the center.

### Sample Output

```
   |   |
 X | O |
___|___|___
   |   |
   | X |
___|___|___
   |   |
   |   | O
   |   |

🎮 ==> Current Player is X
👉 Enter r c from 0-2 for row and column :
```

## How It Works

- The board is a `char[3][3]` array; empty cells hold `' '`
- The main loop runs at most 9 turns (one per cell)
- After each move, all rows, columns, and diagonals are checked for three matching marks
- Invalid input clears the stream error flags and discards the rest of the line, so the game never gets stuck

## Possible Improvements

- Play against a computer opponent
- Replay option after a game ends
- Score tracking across rounds

## License

Released under the [MIT License](LICENSE).
