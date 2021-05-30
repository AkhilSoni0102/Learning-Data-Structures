# BackTracking
Backtracking is a method/ approach to solve problems by making a series of choices that we can return or backtrack to.


### There are 3 Key things you need to consider while doing the Backtracking problem:
    1. Our Choice: 
        - What choice do we make at each call of the function?
        - Recursion expresses decision.
    2. Our Constraints:
        - When do we stop following a certain path?
        - When do we not even go on a particular path? 
    3. Our Goal:( Base Case Comes from this)
        - What's our target?
        - What are we trying to find? 

While doing the problem we should not change the value present in the location which we have not yet visited. Because, when we understand that it wasn't the right path and we need to take some steps back we cannot undo the changes done explicitly by the current step. 
(Last Paragraph is quite vague but you'll get it while solving the N_Queen Problem)