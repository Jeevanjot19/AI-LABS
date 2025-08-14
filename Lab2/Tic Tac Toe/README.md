# Tic Tac Toe – Three AI Approaches

---

## **Code 1 – Multiplication Pattern Recognition (Prime Number Product Method)**

### **Aim**
To implement a Tic Tac Toe AI using prime number representation of board cells and multiplication pattern recognition to detect winning and blocking moves.

---

### **Approach**
- Board cells are assigned values:
  - Empty = 2
  - Player X = 3
  - Player O = 5
- Any winning line’s product for:
  - X → `3 × 3 × 3 = 27`
  - O → `5 × 5 × 5 = 125`
- AI logic:
  1. Use **hardcoded moves** for initial turns (to control opening strategy).
  2. Check if AI can win immediately.
  3. If not, check if the opponent can win next turn → block them.
  4. Otherwise, choose strategic squares (center, corners, edges).

---

### **Implementation Details**
- The board is stored as a 1D array of 9 integers.
- Prime numbers make win detection easier using multiplication.
- Program flow:
  1. Initialize the board with `2` (empty value).
  2. Alternate between player and computer turns.
  3. On computer’s turn:
     - Try to win (`Posswin()`).
     - Try to block.
     - Use `Make2()` for strategic placement.
  4. Check for winner or draw after each move.

---

### **Function Descriptions**
- `display()`: Prints the current state of the board in 3×3 format.
- `Go(n)`: Marks square `n` with current player’s symbol.
- `Posswin(p)`: Checks if player with prime `p` can win in the next move and returns the winning position if possible.
- `Make2()`: Returns the best strategic position when no immediate win/block is needed (center, corners, edges).
- `main()`: Controls overall game loop, player inputs, and AI decisions.

---

### **Time Complexity**
- Win/block check: **O(1)** (only 8 possible lines to check).
- Full game: **O(1)** (constant board size).

### **Space Complexity**
- **O(1)** (fixed-size board and constants).

---

### **Drawbacks**
- Early moves are **hardcoded** → predictable AI.
- Only looks 1 move ahead.
- Can be beaten by experienced players.

---

### **Verdict**
Fast and efficient, but limited intelligence due to fixed opening strategy and no multi-turn planning.

---

## **Code 2 – Magic Square Approach**

### **Aim**
To implement Tic Tac Toe AI using the mathematical property of the 3×3 magic square, where all winning lines sum to 15.

---

### **Approach**
- Assign each cell a **magic number**:
- Any winning combination → sum = **15**.
- AI logic:
1. If it can win this turn → make that move.
2. If opponent can win → block them.
3. Otherwise, pick the first available square.

---

### **Implementation Details**
- Board is stored as a character array (`'X'`, `'O'`, or space `' '`).
- `magicMap[]` array maps board positions to magic numbers.
- Program flow:
1. Player and AI alternate turns.
2. On AI’s turn:
   - Check for a winning move using `findWinningMove()`.
   - If none, block opponent.
   - If none, pick the first empty cell.
3. Check for win/draw after each move.

---

### **Function Descriptions**
- `displayBoard()`: Prints the current state of the board.
- `findWinningMove(sym)`: Finds a move that would complete a winning line for the symbol `sym`.
- `isWinner(sym)`: Checks if the given symbol has a winning combination.
- `main()`: Handles turn-taking and decision-making loop.

---

### **Time Complexity**
- Win/block check: **O(1)** (8 possible lines).
- Game: **O(1)**.

### **Space Complexity**
- **O(1)**.

---

### **Drawbacks**
- Picks the **first empty cell** if no win/block → not optimal for positioning.
- Only 1-move lookahead.
- Predictable mid-game play.

---

### **Verdict**
Clean and mathematical, but lacks deeper tactical play and positional advantage.

---

## **Code 3 – Scoring-Based Evaluation Approach**

### **Aim**
To implement a Tic Tac Toe AI that scores each available move based on positional value and line potential, choosing the highest-scoring move.

---

### **Approach**
- Board uses prime number encoding:
- Empty = 2
- X = 3
- O = 5
- For each empty square:
1. Add points for positional value:
   - Center = +1
   - Corner = +0.5
2. Add points for potential wins:
   - If the line is open for AI → +3 points.
   - If the line is open for opponent → +2 points.
- Choose move with **highest total score**.

---

### **Implementation Details**
- Board stored as 1D integer array.
- Predefined winning lines array for evaluation.
- Program flow:
1. Alternate between human and computer turns.
2. On computer’s turn:
   - Evaluate all empty cells with `evaluateSquare()`.
   - Choose the cell with the maximum score.
3. Place move and check for win/draw.

---

### **Function Descriptions**
- `displayBoard()`: Prints the board in 3×3 format.
- `checkWin(player)`: Returns true if given player has a winning combination.
- `evaluateSquare(pos, player)`: Scores a square based on position and open lines.
- `computerMove()`: Finds the highest-scoring empty square and plays there.
- `main()`: Controls input/output and game loop.

---

### **Time Complexity**
- Evaluating all squares: **O(1)** (max 9 squares).
- Full game: **O(1)**.

### **Space Complexity**
- **O(1)**.

---

### **Drawbacks**
- No multi-move simulation.
- Fixed scoring weights may not always produce perfect play.

---

### **Verdict**
More adaptive and positional than Codes 1 & 2, but still beatable by perfect play.

---

## **Overall Comparison**

| Feature             | Code 1 (Product)     | Code 2 (Magic Square) | Code 3 (Scoring)  |
|--------------------|---------------------|-----------------------|-------------------|
| Win detection      | Multiplication      | Sum = 15              | Line check        |
| Positional play    | Basic (hardcoded)   | None                  | Weighted scoring  |
| Depth of AI        | 1-move lookahead    | 1-move lookahead      | 1-move lookahead  |
| Predictability     | High                | Medium                | Lower             |
| Complexity         | Very Low            | Low                   | Low               |

---

**Final Note:**  
If your goal is **speed & simplicity**, use **Code 1**.  
If you like **mathematical elegance**, use **Code 2**.  
If you want **slightly more intelligent play**, use **Code 3**.

