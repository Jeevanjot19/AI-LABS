# Hill Climbing Algorithm for 8-Puzzle Problem

## Problem Statement
Implement the **Hill Climbing** algorithm to solve the 8-puzzle problem. The 8-puzzle consists of a `3×3` grid containing tiles numbered from `1` to `8` and one empty space represented by `0`. The objective is to move the tiles by sliding them into the empty space until the configuration matches the goal state

The algorithm uses **heuristic evaluation** (number of misplaced tiles) to guide the search toward the goal.

---

## Understanding the Puzzle Size
In this program, the puzzle is fixed at size **3×3** (which means `n = 3`):
- **n** → number of rows = number of columns in the puzzle
- Total cells = `n × n = 9`
- Only one cell contains `0` (empty space)  
- The size `n` determines:
  - The board dimensions
  - Valid movement directions
  - Heuristic calculation scope

---

## Algorithm (Hill Climbing with Mismatched Tiles Heuristic)

1. **Input initial board** configuration from the user.
2. **Locate the empty tile (0)** and store its coordinates.
3. **Evaluate heuristic**: Count how many tiles are misplaced compared to the goal state.
4. **Repeat** until:
   - The current board is the goal state → success
   - No better neighbor exists → stop (local maximum)
5. **Generate neighbors** by moving the empty tile in all possible directions (`Up`, `Down`, `Left`, `Right`).
6. **Choose the best neighbor**:
   - The neighbor with the **lowest heuristic value** is selected.
   - If no neighbor has a better heuristic → stop.
7. **Update current state** to this best neighbor and repeat the process.

---

## Function Descriptions

### `bool isValid(int x, int y)`
Checks if `(x, y)` is within the board boundaries.

### `bool isGoal(const vector<vector<int>> &board)`
Returns `true` if the board matches the goal configuration.

### `int heuristicMismatch(const vector<vector<int>> &board)`
Counts the number of misplaced tiles (excluding the empty space).

### `vector<State> getNextStates(const State &curr)`
Generates all valid next states by moving the empty tile in each possible direction.

### `void printBoard(const vector<vector<int>> &board)`
Displays the board in a 3×3 format.

### `void hillClimbing(vector<vector<int>> startBoard)`
Implements the hill climbing algorithm:
- Prints the current state and heuristic
- Checks for the goal state
- Chooses the best neighbor with a lower heuristic
- Stops if no better neighbor exists

---

## Time Complexity
Let `n` be the board size (here fixed at 3), and `b` be the branching factor (possible moves from a state, ≤ 4).  
- **Heuristic calculation:** `O(n^2)`  
- **Generating neighbors:** `O(b × n^2)`  
- **Total runtime:** In the worst case, the algorithm explores a sequence of improving states:O(d × b × n^2)
where `d` is the number of moves until termination.  
Since `n = 3`, this becomes effectively constant time for each step, but the number of steps depends on the starting state.

---

## Space Complexity
- Storing the board: `O(n^2)`
- Neighbor states: up to `O(b × n^2)`
- Overall: `O(n^2)`

---

