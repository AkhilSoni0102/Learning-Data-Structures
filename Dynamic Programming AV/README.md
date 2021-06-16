# Identification of Knapsack Problem:
### 0/1 Knapsack Problem:
    Given:
        Two arrays: weight[] and Value[].
        an integer: W - capacity of the sack.
    
    o/p: max value possible in the sack considering the max capacity of the sack(W)

    Approach:
        we have a choice for every item:
        if( w1 <= W ) - take it or leave it.
        else - leave it.
    
### Generalizing it:
    Given an array having two properties: weight and value. 
    Capacity is given: W
