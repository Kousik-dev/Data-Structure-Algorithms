#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Solution {
public:
    int numPossibilities = 0;  // Counter for possibilities

    bool isValid(vector<vector<char>>& board, int row, int col, char ch) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == ch || board[row][i] == ch)
                return false;
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == ch)
                return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == '.') {
                    for (char ch = '1'; ch <= '9'; ch++) {
                        if (isValid(board, i, j, ch)) {
                            board[i][j] = ch;
                            numPossibilities++;  // Increment the count for each valid placement
                            
                            printBoard(board, "After placing " + string(1, ch));  // Print board after placement
                            
                            if (solve(board))
                                return true;

                            board[i][j] = '.';
                            numPossibilities++;  // Increment the count for each backtrack
                            printBoard(board, "After backtracking");  // Print board after backtracking
                        }
                    }
                    return false;  // If no valid number can be placed, backtrack
                }
            }
        }
        return true;  // If the board is completely filled
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

    void printBoard(const vector<vector<char>>& board, const string& message) const {
        ofstream file("sudoku_solutions.txt", ios::app);  // Open file in append mode
        if (!file) {
            cerr << "Error opening file for writing\n";
            return;
        }
        file << message << ":\n";
        for (const auto& row : board) {
            for (const auto& cell : row) {
                file << cell << " ";
            }
            file << "\n";
        }
        file << "\n";
        file.close();  // Close the file
    }

    int getPossibilityCount() const {
        return numPossibilities;
    }
};

int main() {
    Solution solution;
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    cout << "Initial board:\n";
    solution.printBoard(board, "Initial board");

    solution.solveSudoku(board);

    cout << "Solved board:\n";
    solution.printBoard(board, "Solved board");

    cout << "Total number of possibilities explored: " << solution.getPossibilityCount() << endl;

    return 0;
}
