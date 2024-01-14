#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool searchWord(vector<vector<char>>& board, string word, int row, int col, int index) {
    if (index == word.size()) {
        return true; // Word found
    }

    if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() ||
        board[row][col] != word[index]) {
        return false; // Out of bounds or mismatch
    }

    char original = board[row][col];
    board[row][col] = '*'; // Mark the cell as visited

    // Recurse in all four directions
    bool found = searchWord(board, word, row - 1, col, index + 1) ||
                searchWord(board, word, row + 1, col, index + 1) ||
                searchWord(board, word, row, col - 1, index + 1) ||
                searchWord(board, word, row, col + 1, index + 1);

    board[row][col] = original; // Restore the original value
    return found;
}

bool exist(vector<vector<char>>& board, string word) {
    int rows = board.size();
    int cols = board[0].size();

    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            if (board[row][col] == word[0] && searchWord(board, word, row, col, 0)) {
                return true;
            }
        }
    }

    return false;
}


int main(){
    vector<vector<char>> board = {{'A','B','C','D'},{'S','F','C','S'},{'A','D','E','E'}};
    cout << exist(board, "SEE") << endl; 
}
