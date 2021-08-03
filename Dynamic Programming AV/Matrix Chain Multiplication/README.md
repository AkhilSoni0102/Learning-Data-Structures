# Matrix Chain Multiplication:
    1. MCM
    2. Printing MCM
    3. Evaluate expression to True / Boolean Parenthesis
    4. Min/ Max value of an expression
    5. Palindromic Partitioning
    6. Scramble string
    7. Egg Dropping Problem

## Identification + Format:
You will be given a string or an array.
we decide i and j at the end points. and another variable k will go from i to j in some way. 
So, the two problems will become solve(i -> k) and solve(k+1, j).
both of these subproblems will give us the temperory answers. 
We now need to calculate the final ans from these two temperory answers.
