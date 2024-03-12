/** solution to: https://codeforces.com/contest/377/problem/A/
 * Maze
*/

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int visited[501][501]; 
int freeCellsCount = 0;
int vsCount = 0;

void explore(int a, int b, int n, int m, int& remainingMoves, vector<string>& board) {
    if (a >= 0 && a < n && b >= 0 && b < m && board[a][b] != '#' && visited[a][b] == 0) {
        visited[a][b]++; // Increment visit count
        if (remainingMoves <= 0) {
            board[a][b] = 'X';
        } else {
            remainingMoves--;
        }
        explore(a + 0, b - 1, n, m, remainingMoves, board);
        explore(a - 1, b + 0, n, m, remainingMoves, board);
        explore(a + 0, b + 1, n, m, remainingMoves, board);
        explore(a + 1, b + 0, n, m, remainingMoves, board);
    }
}

void printBoard(const vector<string>& board) {
    for (const string& row : board) {
        cout << row << endl;
    }
}

int main() {
    int rows, cols;
    cin >> rows >> cols;

    int initialK;
    cin >> initialK;
    
    memset(visited, 0, sizeof(visited)); // Initialize to 0
    vector<string> gameBoard(rows);
    
    for (string& row : gameBoard) {
        cin >> row;
        for (char cell : row) {
            if (cell == '.') freeCellsCount++;
        }
    }

    int remainingMoves = freeCellsCount - initialK;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (gameBoard[i][j] == '.' && visited[i][j] == 0) { // Add condition to check visit count
                explore(i, j, rows, cols, remainingMoves, gameBoard);
            }
        }
    }

    printBoard(gameBoard);

    return 0;
}