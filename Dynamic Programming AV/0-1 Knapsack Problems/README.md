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

### Subset Sum Problem:
    Given an array and an integer "Sum", check whether there exist a subset whose sum of elements equals "Sum".
#### Approach:
    It is the same problem as 0/1 knapsack as it has a choice for each element in the array, whether to take it or not. and the capacity of the sack here is "Sum".

    Code will be exactly same except: we don't have the value array in this question.

### Equal Sum Partition Problem:
    Given an array, check whether it is possible to divide this array into subsets whose sum of elements are equal.
#### Approach:
    To divide an array into two equal sums, the sum of all the elements needs to be an even number. Then only it would be possible to divide it into two equal parts.
    So, First we find the sum of all the elements: "Sum"
    if(sum % 2 != 0)
        it is not possible to find the ans
    else 
        it is possible.
    
    if the ans is possbile:
        both the subsets now should have the sum = Sum/2.
        so if we find one subset whose sum = Sum/2. the other subset will obviously have the sum = Sum/2
        Hence, it is same as Subset sum problem from here.

### Number of subsets with a given diff:
    Given an array and an intefer Diff. Count the number of subset pairs s1 and s2, whose absolute difference is equal to Diff.
#### Approach:
    we are given:     sum(s1) - sum(s2) = Diff --- (1)
    we can calculate: sum(s1) + sum(s2) = Sum  --- (2)
    Adding the above two equation we get, sum(s1) = (Diff + Sum) / 2
    So, the aim became to count the no. of subsets having sum = sum(s1)
