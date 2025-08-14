#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct State {
    vector<vector<int>> board;
    int emptyX, emptyY;
    string path;
    int heuristic; // mismatched tiles
};

vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};
vector<char> moveChar = {'U', 'D', 'L', 'R'};

bool isValid(int x, int y) {
    return (x >= 0 && x < 3 && y >= 0 && y < 3);
}

bool isGoal(const vector<vector<int>> &board) {
    vector<vector<int>> goal = {{1, 2, 3},
                                {4, 5, 6},
                                {7, 8, 0}};
    return board == goal;
}

int heuristicMismatch(const vector<vector<int>> &board) {
    int mismatches = 0;
    vector<vector<int>> goal = {{1, 2, 3},
                                {4, 5, 6},
                                {7, 8, 0}};
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 0 && board[i][j] != goal[i][j])
                mismatches++;
    return mismatches;
}

vector<State> getNextStates(const State &curr) {
    vector<State> nextStates;
    for (int i = 0; i < 4; i++) {
        int nx = curr.emptyX + dx[i];
        int ny = curr.emptyY + dy[i];
        if (isValid(nx, ny)) {
            State next = curr;
            swap(next.board[curr.emptyX][curr.emptyY], next.board[nx][ny]);
            next.emptyX = nx;
            next.emptyY = ny;
            next.path = curr.path + moveChar[i];
            next.heuristic = heuristicMismatch(next.board);
            nextStates.push_back(next);
        }
    }
    return nextStates;
}

void printBoard(const vector<vector<int>> &board) {
    for (auto &row : board) {
        for (int v : row) cout << v << " ";
        cout << "\n";
    }
    cout << "------\n";
}

void hillClimbing(vector<vector<int>> startBoard) {
    int emptyX, emptyY;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (startBoard[i][j] == 0) { emptyX = i; emptyY = j; }

    State current = {startBoard, emptyX, emptyY, "", heuristicMismatch(startBoard)};

    while (true) {
        printBoard(current.board);
        cout << "Current heuristic: " << current.heuristic << "\n";

        if (isGoal(current.board)) {
            cout << "Goal reached!\nPath (" << current.path.size() << " moves): " << current.path << "\n";
            return;
        }

        vector<State> neighbors = getNextStates(current);
        State bestNeighbor = current;

        for (auto &n : neighbors) {
            if (n.heuristic < bestNeighbor.heuristic) {
                bestNeighbor = n;
            }
        }

        if (bestNeighbor.heuristic >= current.heuristic) {
            cout << "No better neighbor found. Stopping.\n";
            return;
        }

        current = bestNeighbor;
    }
}

int main() {
    vector<vector<int>> start(3, vector<int>(3));
    cout << "Enter initial 3x3 puzzle (use 0 for empty):\n";
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> start[i][j];

    hillClimbing(start);
    return 0;
}
