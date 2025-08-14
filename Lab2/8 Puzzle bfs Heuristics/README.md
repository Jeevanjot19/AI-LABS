# 8-Puzzle Problem using Heuristic Best First Search (BFS)

## Introduction
The **8-puzzle** is a sliding puzzle consisting of a 3x3 grid containing 8 numbered tiles and one empty space (represented by 0).  
The goal is to reach a predefined target configuration (goal state) by sliding the tiles into the empty space.

In this implementation, we solve the puzzle using **Best First Search** guided by a **heuristic function** — the **number of misplaced tiles**.

---

## Problem Definition
We are given:
- An **initial 3x3 configuration** of the puzzle (with numbers 1–8 and 0 for the empty space).
- A **goal configuration**

We need to find the shortest path (sequence of moves) to reach the goal using a heuristic-driven search.

---

## Algorithm

### Heuristic: Number of Misplaced Tiles
This heuristic counts how many tiles are **not** in their goal position (ignoring the empty tile).

### Best First Search Steps:
1. **Input**: Read the starting puzzle configuration.
2. **Find the empty tile** position.
3. **Initialize a priority queue** (min-heap) ordered by the heuristic value.
4. **Push the starting state** into the queue.
5. **While the queue is not empty**:
    - Remove the state with the **lowest heuristic value**.
    - If it is the **goal state**, stop and print the solution path.
    - Else, generate all possible next states by moving the empty tile **up, down, left, or right**.
    - For each next state:
        - Compute its heuristic.
        - Add it to the queue if it hasn't been visited.
6. **If queue is exhausted without reaching goal**, report "No solution found."

---

## Function Descriptions

### `bool isGoal(const vector<vector<int>>& board)`
Checks if the current board matches the goal configuration.

### `string serialize(const vector<vector<int>>& board)`
Converts the board into a string format for storing in a `visited` set.

### `bool isValid(int x, int y)`
Checks if coordinates `(x, y)` are inside the 3x3 grid.

### `int heuristicMismatch(const vector<vector<int>>& board)`
Calculates the **misplaced tiles heuristic**.

### `vector<State> getNextStates(const State &curr)`
Generates all possible next moves from the current state.

### `void printBoard(const vector<vector<int>>& board)`
Prints the board in a readable format.

### `void BestFirstSearch(vector<vector<int>> startBoard)`
Runs the Best First Search algorithm using a priority queue.

---

## Time and Space Complexity

Let:
- **b** = branching factor (max possible moves from a state, ≤ 4)
- **d** = depth of solution
- **N** = total number of reachable states (≤ 9! = 362,880)

- **Time Complexity**:  
  In the worst case, Best First Search might explore all states:  
  **O(N log N)** because each insertion/removal from the priority queue is **O(log N)**.

- **Space Complexity**:  
  **O(N)** for storing visited states and the priority queue.

---
## **8. Limitations**
1. **Not Guaranteed to Find Shortest Path**  
   Since this is **Greedy Best First Search** (not A*), it chooses the best heuristic without considering the cost so far.  
   A suboptimal path may be found.

2. **Heuristic Can Mislead**  
   The "number of mismatched tiles" heuristic is simple and may not accurately represent actual distance to the goal, leading to extra expansions.

3. **May Not Solve Unsolvable Configurations**  
   8-puzzle has only 50% solvable initial configurations (based on parity of inversions). This algorithm doesn’t check solvability beforehand, so it may search indefinitely.

4. **Memory Usage**  
   Priority queue and visited set can grow large for deep searches.

---