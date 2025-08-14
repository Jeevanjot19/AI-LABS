# Universal Magic Square Generator

## **Aim**
To design and implement a C++ program that generates a Magic Square of any given size \( n \geq 3, n \neq 2 \) and prints it along with its magic constant.  
The program should handle:
- **Odd order** magic squares (\(n = 3, 5, 7, ...\))  
- **Doubly even order** magic squares (\(n\) divisible by 4, e.g., 4, 8, 12)  
- **Singly even order** magic squares (\(n\) divisible by 2 but not by 4, e.g., 6, 10, 14)

---

## **Theory**
A **Magic Square** is a \(n \times n\) matrix containing distinct integers from \(1\) to \(n^2\), arranged such that the sum of the elements in every row, every column, and both main diagonals is the same.  
This sum is called the **Magic Constant** and is given by:  

\[
M = \frac{n(n^2 + 1)}{2}
\]

Depending on \(n\), magic squares are classified into:
1. **Odd order** – Constructed using the **Siamese method**.
2. **Doubly even order** (\(n \% 4 == 0\)) – Constructed using the **Strachey method**.
3. **Singly even order** (\(n \% 2 == 0\) and \(n \% 4 \neq 0\)) – Constructed using a combination of the odd-order method and block interchanges.

---

## **Approach**
1. **Input**: Read \(n\) from the user and validate it (\(n \geq 3\), \(n \neq 2\)).
2. **Check type**:
   - If \(n\) is odd → call `generateOdd()`
   - If \(n\) is doubly even → call `generateDoublyEven()`
   - If \(n\) is singly even → call `generateSinglyEven()`
3. **Generate matrix** according to the selected method.
4. **Display** the matrix in a formatted manner.
5. **Calculate and print** the magic constant.

---

## **Implementation Details**

### **1. `generateOdd(int n)`**
**Purpose:** Generates an odd-order magic square using the **Siamese method**.  
**Logic:**
- Start from the middle of the top row.
- Place numbers sequentially, moving up and right after each placement.
- Wrap around the grid if out of bounds.
- If the calculated position is already filled, move down one row instead.  
**Time Complexity:** \(O(n^2)\)  
**Space Complexity:** \(O(n^2)\)

---

### **2. `generateDoublyEven(int n)`**
**Purpose:** Generates a doubly even order magic square using the **Strachey method**.  
**Logic:**
- Fill the square sequentially from 1 to \(n^2\).
- Invert certain cells according to the pattern:
  - If `(i % 4 == j % 4)` or `(i % 4 + j % 4 == 3)`, replace value with \((n^2 + 1) - value\).  
**Time Complexity:** \(O(n^2)\)  
**Space Complexity:** \(O(n^2)\)

---

### **3. `generateSinglyEven(int n)`**
**Purpose:** Generates singly even order magic squares using the **Strachey + Interchange** method.  
**Logic:**
- Divide the square into four \(n/2 \times n/2\) sub-squares.
- Generate an odd-order magic square in the top-left sub-square.
- Fill remaining sub-squares with adjusted values from the base square.
- Swap specific columns between top and bottom halves.  
**Time Complexity:** \(O(n^2)\)  
**Space Complexity:** \(O(n^2)\)

---

## **Algorithm Flow**
1. Start  
2. Input \(n\)  
3. Validate \(n\)  
4. If \(n\) odd → `generateOdd()`  
5. Else if \(n \% 4 == 0) → `generateDoublyEven()`  
6. Else → `generateSinglyEven()`  
7. Print the magic square  
8. Print magic constant  
9. End

---

---

## **Time Complexity Analysis**
- **Each method** involves filling exactly (n x n) cells once → **O(n²)**.  
- Index calculations, swaps, and wraps are constant-time operations → no effect on order.

## **Space Complexity Analysis**
- A 2D vector of size (n x n) → **O(n²)** auxiliary space.

---

## **Conclusion**
This program successfully generates magic squares of **any valid size** using the appropriate mathematical method for:
- Odd order
- Doubly even order
- Singly even order  
The implementation ensures correctness, handles all valid cases, and efficiently computes the magic constant.
