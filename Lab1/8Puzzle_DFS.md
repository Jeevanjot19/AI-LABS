## Problem Statement
Solve the 8-puzzle problem using the Depth-First Search (DFS) algorithm.  
The 8-puzzle consists of a 3x3 grid with 8 numbered tiles and one empty space.  
The objective is to reach the goal configuration:
1 2 3  
4 5 6  
7 8 0  
(0 denotes the empty space).

---

## Approach
```
- Use Depth-First Search (DFS) to explore states along one branch deeply before backtracking.
- At each step:
  - Identify the empty tile position.
  - Generate all valid moves (up, down, left, right).
  - Push them on the stack.
- Use a visited set to avoid infinite loops.
- DFS may not give the shortest path but will find a solution if one exists.
```

---

## Implementation
```
- State Representation: vector<vector<int>> for board.
- Data Structures Used:
  - std::stack → for DFS traversal.
  - std::set → to track visited states.
- Move Path Storage: Each state carries its path string ("UDLR...").
```

---

## Code
```cpp
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
    string path;
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
            next.path = curr.path + moveChar[i];
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
```

---

## Time Complexity
```
DFS explores states deeply and may backtrack multiple times.
Worst case: explores all possible states.
Time Complexity: O(9!)
```

---

## Space Complexity
```
Visited set + stack memory: O(9!)
```

---

## Use Case
```
Puzzle Solvers: Quick to find a solution (not necessarily shortest).
Path finding in large state spaces where memory is limited compared to BFS.
```
