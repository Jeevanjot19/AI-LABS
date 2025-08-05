## Problem Statement
Solve the 8-puzzle problem using the Breadth-First Search (BFS) algorithm.  
The 8-puzzle consists of a 3x3 grid with 8 numbered tiles and one empty space.  
The objective is to reach the goal configuration:
1 2 3  
4 5 6  
7 8 0  
(0 denotes the empty space).

---

## Approach
```
- Use Breadth-First Search (BFS) to explore states level by level.
- At each step:
  - Identify the empty tile position.
  - Generate all valid moves (up, down, left, right).
  - Push them in a queue.
- Use a visited set to avoid revisiting states.
- BFS guarantees the shortest path solution.
```

---

## Implementation
```
- State Representation: vector<vector<int>> for board.
- Data Structures Used:
  - std::queue → for BFS traversal.
  - std::set → to track visited states.
- Move Path Storage: Each state carries its path string ("UDLR...").
```

---

## Code
```cpp
#include <iostream>
#include <queue>
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

void BFS(vector<vector<int>> startBoard) {
    queue<State> q;
    set<string> visited;

    int emptyX, emptyY;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (startBoard[i][j] == 0) { emptyX = i; emptyY = j; }

    State start = {startBoard, emptyX, emptyY, ""};
    q.push(start);

    while (!q.empty()) {
        State curr = q.front();
        q.pop();

        string hash = serialize(curr.board);
        if (visited.count(hash)) continue;
        visited.insert(hash);

        printBoard(curr.board);

        if (isGoal(curr.board)) {
            cout << "Goal reached!\nShortest path (" << curr.path.size() << " moves): " << curr.path << "\n";
            return;
        }

        vector<State> nextStates = getNextStates(curr);
        for (auto &s : nextStates) q.push(s);
    }
    cout << "No solution found.\n";
}

int main() {
    vector<vector<int>> start(3, vector<int>(3));
    cout << "Enter initial 3x3 puzzle (use 0 for empty):\n";
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> start[i][j];

    BFS(start);
    return 0;
}
```

---

## Time Complexity
```
BFS explores each unique state once.
Maximum states for 8 puzzle: 9! = 362,880.
Each state generates at most 4 neighbors.
Time Complexity: O(9!)
```

---

## Space Complexity
```
Stores all visited states and queue frontier.
Space Complexity: O(9!)
```

---

## Use Case
```
Optimal Path Finding: BFS ensures the shortest solution path.
Useful in robotics, automated planning, and game solvers where optimal moves are needed.
```
