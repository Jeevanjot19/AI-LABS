# 8-Puzzle Solver using Best First Search & DFS in C++

## Overview
This program solves the **8-puzzle problem** (sliding puzzle) using:
- **Best First Search (BFS)**: Uses a heuristic to choose the next promising state.
- **Depth-First Search (DFS)**: Explores possible moves in a depth-first manner.

The 8-puzzle consists of a 3×3 board with tiles numbered `1` to `8` and one empty space (`0`). The objective is to reach the goal state


---

## Algorithms

### 1. Best First Search (Heuristic-based)
- Uses a **priority queue** to explore the most promising states first.
- Heuristic used: **Number of mismatched tiles** compared to the goal.
- At each step:
  1. Remove the state with the lowest heuristic value.
  2. If it’s the goal, stop.
  3. Otherwise, expand to possible next states by moving the empty tile.
  4. Push them into the priority queue.

### 2. DFS (Depth First Search)
- Explores one branch of moves as deep as possible before backtracking.
- Implemented here using a priority queue but without a heuristic (behaves like DFS with a stack).

---

## Function Descriptions

### `isGoal(board)`
- Checks if the given board matches the goal state.

### `serialize(board)`
- Converts the board into a string format (for storing visited states).

### `isValid(x, y)`
- Checks if coordinates `(x, y)` are inside the board boundaries.

### `heuristicMismatch(board)`
- Counts how many tiles are out of place compared to the goal.

### `BestFirstSearch(startBoard)`
- Implements the Best First Search algorithm.
- Uses the mismatch heuristic to decide search order.
- Stops when the goal is reached.

### `DFS(startBoard)`
- Implements DFS for solving the puzzle.
- Searches deeply before backtracking.

### `getNextStates(curr)`
- Generates all possible next states by sliding the empty tile in four directions.

### `printBoard(board)`
- Prints the current state of the board.

---

## Pseudocode for Best First Search

function BEST_FIRST_SEARCH(start):
pq ← priority queue ordered by heuristic value
visited ← empty set
find empty tile position in start
push start into pq with heuristic value

while pq not empty:
    curr ← pq.pop()

    if curr already visited:
        continue

    mark curr as visited
    print curr.board

    if curr is goal:
        print solution path
        return

    for each possible move from curr:
        generate new state
        compute heuristic
        push into pq

print "No solution found"

---

## Time Complexity
- **Best First Search**:  
  Worst case — `O(b^d)` where:
  - `b` = branching factor (up to 4 moves per state)
  - `d` = depth of solution
  Priority queue operations add an extra `O(log N)` factor.

- **DFS**:  
  Worst case — `O(b^d)` as well, but without priority queue overhead.

---

## Space Complexity
- **Best First Search**:  
  Can store many nodes in memory → `O(b^d)` space in the worst case.

- **DFS**:  
  Space proportional to depth → `O(d)`.

---

## Limitations
1. **Best First Search**:
   - May get stuck in local minima if heuristic is poor.
   - Large memory usage for big search spaces.

2. **DFS**:
   - May go very deep without finding a solution (can miss shorter paths).
   - Not guaranteed to find the shortest solution.

3. **General**:
   - Only works for solvable puzzle configurations.
   - Performance degrades for larger puzzles.

---
