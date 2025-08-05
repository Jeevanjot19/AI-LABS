#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
#include <set>
using namespace std;

struct State {
    vector<vector<int>> board;
    int emptyX, emptyY;
    string path;  // stores moves to reach this state
};

bool isGoal(const vector<vector<int>> &board) {
    vector<vector<int>> goal = {{1, 2, 3},
                                {4, 5, 6},
                                {7, 8, 0}};
    return board == goal;
}

string serialize(const vector<vector<int>> &board) {
    string s;
    for (auto &row : board)
        for (int val : row) {
            stringstream ss;
            ss << val;
            s += ss.str() + ",";
        }
    return s;
}

bool isValid(int x, int y) {
    return (x >= 0 && x < 3 && y >= 0 && y < 3);
}

// Move directions and corresponding chars
vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};
vector<char> moveChar = {'U', 'D', 'L', 'R'};

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
            next.path = curr.path + moveChar[i];  // add move to path
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

void DFS(vector<vector<int>> startBoard) {
    stack<State> st;
    set<string> visited;

    int emptyX, emptyY;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (startBoard[i][j] == 0) { emptyX = i; emptyY = j; }

    State start = {startBoard, emptyX, emptyY, ""};
    st.push(start);

    while (!st.empty()) {
        State curr = st.top();
        st.pop();

        string hash = serialize(curr.board);
        if (visited.count(hash)) continue;
        visited.insert(hash);

        // Print each visited board
        printBoard(curr.board);

        if (isGoal(curr.board)) {
            cout << "Goal reached!\nMoves: " << curr.path << "\n";
            return;
        }

        vector<State> nextStates = getNextStates(curr);
        for (auto &s : nextStates) st.push(s);
    }
    cout << "No solution found.\n";
}

int main() {
    vector<vector<int>> start(3, vector<int>(3));
    cout << "Enter initial 3x3 puzzle (use 0 for empty):\n";
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> start[i][j];

    DFS(start);
    return 0;
}
