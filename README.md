Here's a `README.md` file formatted for GitHub with the provided content:

---

# Numerical Methods Console Application

This project implements various numerical methods for solving non-linear equations, linear equations, differential equations, and matrix inversion. Each algorithm is encapsulated in a dedicated class, with methods to handle solution approximation, convergence, and error tolerance.

## Table of Contents
1. [Non-linear Equations](#non-linear-equations)
2. [Linear Equations](#linear-equations)
3. [Differential Equations](#differential-equations)
4. [Matrix Inversion](#matrix-inversion)

---

## Non-linear Equations

### Algorithm-01: Bi-Section Method
**File**: `bi_section.hpp`  
The Bi-Section method finds roots of non-linear equations using interval bisection.
- **Initial Range Calculation**: Determines an initial maximum range \((-|xmax|, |xmax|)\) for root existence.
- **Calculation Method**: Iteratively narrows the range until the difference is within a specified error tolerance or 100 iterations are complete.
Details-
# Algorithm-01: Bi-Section Method
`bi_section.hpp`

The Bi-section method is used to find solutions for **non-linear equations**. This implementation of the Bi-section method finds the roots of a polynomial equation given specific degree, coefficients, and error/tolerance level. 

**`BiSection`** is the class inherited from the class **`NonLinear`**.

## Initial Range Calculation
An initial maximum value, `xmax`, is determined by estimating the range where roots might exist. This is calculated by the formula:

\[
|x_{\text{max}}| = \sqrt{\left(\frac{a_{n-1}}{a_n}\right)^2 - 2 \left(\frac{a_{n-2}}{a_n}\right)}
\]

The search interval is defined as \( (-|x_{\text{max}}|, |x_{\text{max}}|) \), where the polynomial is represented as:

\[
f(x) = a_n x^n + a_{n-1} x^{n-1} + \dots + a_1 x + a_0 = 0
\]

## Calculation Method
1. **Initial Range Check:**
   - After finding the initial range, for each \( i \) (where \( i \) is incremented by 0.5 for more precision) within the interval \( -|x_{\text{max}}| \leq i \leq |x_{\text{max}}| \):
     - Check if \( f(i) \times f(i + 1) \leq 0 \).
       - **If the condition is satisfied:** set `a = i` and `b = i + 1`.
       - **Otherwise:** continue to the next \( i \).

2. **Bisection Method:**
   - After finding values `a` and `b`, an iterative approach is used to approximate the root:
     - Calculate midpoint:
       \[
       c = \frac{a + b}{2}
       \]
     - Evaluate `f(c)`:
       - **If** \( f(c) = 0 \): set `root = c`.
       - **Else if** \( f(c) \times f(a) < 0 \): update `b = c`.
       - **Otherwise:** update `a = c`.

3. **Termination Conditions:**
   - The process continues until:
     - \( b - a \leq \text{error} \) (tolerance level).
     - Or 100 iterations are completed.

All roots found are displayed at runtime with minimal error.

### Algorithm-02: False Position Method
**File**: `false_position.hpp`  
The False Position method refines interval boundaries using linear interpolation.
- **Initial Range Calculation**: Similar to the Bi-Section method, determining \((-|xmax|, |xmax|)\).
- **Calculation Method**: Uses a linear approximation and iterates until the desired error tolerance or a maximum of 100 iterations is met.

### Algorithm-03: Secant Method
**File**: `secant.hpp`  
The Secant method uses two initial guesses and does not require the derivative of the function.
- **Initial Range Calculation**: Starts at an estimated maximum range.
- **Calculation Method**: Updates approximations iteratively until the desired tolerance is achieved.

### Algorithm-04: Newton-Raphson Method
**File**: `newton_raphson.hpp`  
This method uses the function's derivative to achieve fast convergence.
- **Derivative Calculation**: Calculates \(f'(x)\) for precise results.
- **Calculation Method**: Updates using Newton's formula until the error tolerance or 100 iterations is reached.

---

## Linear Equations

### Algorithm-05: Jacobi Iterative Method
**File**: `Jacobi_iterative.hpp`  
A method for solving linear equations, iterating values until convergence.
- **Row Swapping for Dominant Diagonal**: Ensures the matrix is diagonally dominant for convergence.
- **Iteration**: Runs up to 100 times or until the convergence threshold is achieved.

### Algorithm-06: Gauss-Seidel Iterative Method
**File**: `gauss_seidel_iterative.hpp`  
An improvement over Jacobi, updating values in-place for faster convergence.
- **Row Swapping for Dominant Diagonal**: Ensures convergence.
- **Iteration**: Uses previous step values immediately for each calculation.

### Algorithm-07: Gauss Elimination Method
**File**: `gauss_jordan_elimination.hpp`  
Transforms a matrix into upper triangular form for solving linear systems.
- **swapp Function**: Ensures non-zero diagonal entries for stability.
- **gauss_elimination Function**: Solves the system using elimination followed by back-substitution.

### Algorithm-08: Gauss-Jordan Elimination Method
**File**: `gauss_jordan_elimination.hpp`  
Extends Gaussian elimination to row-reduced echelon form.
- **Row Reduction**: Converts the matrix into RREF.
- **Solution Check**: Identifies if a system has unique, infinite, or no solutions.

### Algorithm-09: LU Factorization Method
**File**: `lu_factorization.hpp`  
Decomposes a matrix into lower (L) and upper (U) matrices for efficient solving.
- **LU Decomposition**: Generates L and U matrices.
- **Forward and Backward Substitution**: Solves the system using L and U.

---

## Differential Equations

### Algorithm-10: Runge-Kutta Method
**File**: `runge_kutta.hpp`  
The 4th-order Runge-Kutta method for solving differential equations.
- **Equation Choices**: Offers four different differential equations for demonstration.
- **Step Calculation**: Calculates new values of \(y\) at each step using four slopes.

---

## Matrix Inversion

### Algorithm-11: Matrix Inversion
**File**: `matrix_inversion.hpp`  
Implements matrix inversion using the Gauss-Jordan elimination method.
- **Matrix Augmentation**: Creates an augmented matrix \([A | I]\).
- **Gaussian and Gauss-Jordan Elimination**: Transforms the matrix to find the inverse.

---

## Running the Application
Compile the application with a compatible C++ compiler. Each method outputs results to the console, allowing for easy verification and debugging.

## License
This project is open-source and available under the MIT License.

---

This `README.md` can be saved directly in your GitHub repository for detailed documentation.
