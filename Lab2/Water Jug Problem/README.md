# Water Jug Problem with Drum Extension

## 📌 Aim
To implement the Water Jug Problem in C++ to measure a desired target amount of water using two jugs of given capacities.  
Additionally, extend the algorithm to handle cases where the target amount is greater than the capacity of both jugs by using a **drum** as an intermediate storage container.

---

## 📝 Problem Statement
Given two jugs with capacities `jug1` and `jug2`, and a target amount of water `target`, the task is to measure the exact target amount using the least number of steps.

**Rules:**
1. A jug can be filled completely.
2. A jug can be emptied completely.
3. Water can be transferred from one jug to another until one jug is either full or empty.
4. If the target is greater than the capacity of both jugs, water can be collected in a **drum** until the remaining amount can be measured using the original water jug method.

---

## 💡 Approach
### **Case 1:** Target ≤ Max(Jug1, Jug2)  
- Use the **normal water jug algorithm** to measure the target directly.

### **Case 2:** Target > Max(Jug1, Jug2)  
- Fill `jug1` repeatedly and pour into the **drum** until the **remaining amount** is ≤ max(jug1, jug2).
- Use the normal water jug algorithm to measure the remaining water and pour it into the drum.

---

## ⚙️ Algorithm
1. **Input** the capacities of `jug1`, `jug2`, and the `target`.
2. If `target` is equal to the capacity of any jug, print the result and exit.
3. Swap jug capacities if `jug2 > jug1` to simplify processing.
4. If `target > jug1`:
   - Keep filling `jug1` and pouring into the drum until the remaining target ≤ jug1.
   - Use the normal algorithm to get the remaining water.
5. Else:
   - Use the normal algorithm directly.
6. Print the steps and the final result.

---

## 🖥️ Function Descriptions

### `void waterjug(int jug1, int jug2, int target)`
- **Purpose:** Implements the **classic water jug problem** using two jugs.
- **Parameters:**
  - `jug1` → Capacity of jug 1
  - `jug2` → Capacity of jug 2
  - `target` → Target water amount to be measured
- **Working:**
  - Repeatedly fill, empty, and transfer water between jugs until one jug contains the target amount.
  - Prints each step for clarity.

---

### `int main()`
- **Purpose:** Handles input, determines the case type (normal or drum mode), and calls the appropriate logic.
- **Working:**
  - Reads `jug1`, `jug2`, and `target` from the user.
  - Checks if the target equals any jug capacity.
  - Swaps jug sizes so `jug1` ≥ `jug2`.
  - If `target > jug1`:
    - Fills drum directly from `jug1` until remaining ≤ jug1.
    - Calls `waterjug()` to measure the remaining amount.
  - Else:
    - Directly calls `waterjug()`.

---
---

## 📊 Time Complexity

### **Case 1:** Target ≤ Max(Jug1, Jug2)  
- Each operation (fill, empty, transfer) takes **O(1)** time.
- Maximum number of operations is bounded by `O(jug1 + jug2)` because each state `(x, y)` is visited at most once.
- **Time Complexity:** `O(jug1 + jug2)`

### **Case 2:** Target > Max(Jug1, Jug2)  
- First phase (filling drum):  
  - `target / jug1` fills required → **O(target / jug1)** time.
- Second phase (measuring remainder):  
  - Same as Case 1 → **O(jug1 + jug2)** time.
- **Total Time Complexity:** `O(target / jug1 + jug1 + jug2)`

---

## 🗂️ Space Complexity
- Uses only a constant number of variables (`x`, `y`, `drum`, `remaining`, etc.).
- No additional data structures required.
- **Space Complexity:** **O(1)**

---

## 🧾 Conclusion
This implementation extends the classical Water Jug Problem to handle larger target amounts by introducing a drum.  
The algorithm ensures efficiency by:
1. Quickly reducing the target via drum fills.
2. Using the optimized original jug algorithm for the remainder.
3. Maintaining constant space usage.

---
