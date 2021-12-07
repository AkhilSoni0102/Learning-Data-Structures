# Sorting
### What Does C++ use for Sorting:
    - Different languages have their own in-built functions for sorting, which are basically hybrid sorts that are a combination of different basic sorting algorithms. For example, C++ uses introsort,  which runs quicksort and switches to heapsort when the recursion gets too deep. This way, you get the fast performance of quicksort in practice while guaranteeing a worst-case time complexity of O(N*logN), where N is the number of elements.
    - We will be focusing mainly upon the following sorting algorithms:
        1. Selection Sort
        2. Bubble Sort
        3. Insertion Sort
        4. Merge Sort
        5. Quick Sort
        6. Counting Sort
# Classification of Sorting Algorithms:
### In-place and Out-place Sorting:
    -  In-place sorting:  In-place sorting does not require any extra space except the input space excluding the constant space which is used for variables or iterators. It also doesn’t include the space used for stack in the recursive algorithms. 
    For Example:
        1. Bubble Sort
        2. Selection Sort
        3. Insertion Sort
        4. Quicksort
    - Out-place sorting: Out-place sorting requires extra space to sort the elements. 
    For Example:
        1. Merge Sort
        2. Counting sort
    
### Stable and Unstable Sorting:
    - Stable sorting:  A sorting algorithm when two objects with equal keys appear in the same order in the sorted output as they appear in the unsorted input. 
    For Example:
        1. Insertion Sort
        2. Merge Sort
        3. Bubble Sort
        4. Counting sort
    - Unstable sorting: A sorting algorithm is called unstable sorting if there are two or more objects with equal keys which don’t appear in the same order before and after sorting. 
    For Example:
        1. Quick Sort
        2. Heap Sort
        3. Selection Sort
### Adaptive and Non-adaptive sorting
    - Adaptive sorting: When the order of occurrence of elements in an array affects the time complexity of a sorting algorithm, then such an algorithm is known as an adaptive sorting algorithm. 
    For Example:
        1. Bubble sort
        2. Insertion Sort
        3. Quick Sort
    - Non-adaptive sorting: When the order of occurrence of elements in an array does not affect the time complexity of a sorting algorithm, then such an algorithm is known as a non-adaptive sorting algorithm. 
    For Example:
        1. Selection Sort
        2. Heap Sort
        3. Merge Sort

# Selection Sort:
### Complexities:
    - Time: O(N^2)
    - Space: O(1)
### Algorithm:
    - Steps: (sorting in increasing order)
        1. First-of-all, we will find the smallest element of the array and swap it with index 0.
        2. Similarly, we will find the second smallest and swap that with the element at index 1 and so on…
        3. Ultimately, we will be getting a sorted array in increasing order only. 

# Bubble Sort:
### Complexities:
    - Time: O(N^2)
    - Space: O(1)

### Algorithm:
    - In this technique, we just compare the two adjacent elements of the array and then sort them manually by swapping if not sorted. Similarly, we will compare the next two elements (one from the previous position and the corresponding next) of the array and sort them manually. This way the elements from the last get placed in their correct position. This is the difference between selection sort and bubble sort.

# Insertion Sort:
### Complexities:
    - Time: O(N^2)
    - Space: O(1)
### Algorithm:
    - Insertion Sort works similar to how we sort a hand of playing cards.
    - Imagine that you are playing a card game. You're holding the cards in your hand, and these cards are sorted. The dealer hands you exactly one new card. You have to put it into the correct place so that the cards you're holding are still sorted. In selection sort, each element that you add to the sorted subarray is no smaller than the elements already in the sorted subarray. 
    - But in our card example, the new card could be smaller than some of the cards you're already holding, and so you go down the line, comparing the new card against each card in your hand until you find the place to put it. You insert the new card in the right place, and once again, your hand holds fully sorted cards. Then the dealer gives you another card, and you repeat the same procedure. - Then another card, and another card, and so on, until the dealer stops giving you cards. This is the idea behind the insertion sort. Loop over positions in the array, starting with index 1. Each new position is like the new card handed to you by the dealer, and you need to insert it into the correct place in the sorted subarray to the left of that position.
    - Insertion sort is a sorting algorithm that places an unsorted element at its suitable place in each iteration.


# Merge Sort Algorithm:
### Complexities:
    - Time: O(N*log(N))
    - Space: O(N)
### Algorithm:
    - Merge sort requires dividing a given list into equal halves until it can no longer be divided. By definition, if it is only one element in the list, it is sorted. Then, merge sort combines/merges the smaller sorted lists keeping the new list sorted too.
        1. If it is only one element in the list it is already sorted, return.
        2. Divide the list recursively into two halves until it can’t be divided further.
        3. Merge the smaller lists into a new list in sorted order.
    It has just one disadvantage that it creates a copy of the array and then works on that copy.

# Quick Sort:
### Complexities:
    - Time: O(N^2), in the worst case.
    But as this is a randomized algorithm, its time complexity fluctuates between O(N2) and O(N*log N) and mostly it comes out to be O(N*logN).
    - Space: O(1)
### Algorithm:
    - Divide: The array is divided into subparts taking pivot as the partitioning point. The elements smaller than the pivot are placed to the left of the pivot and the elements greater than the pivot are placed to the right side.
    - Conquer: The left and right sub-parts are again partitioned using the by selecting pivot elements for them. This can be achieved by recursively passing the subparts into the algorithm.
    - Combine: This part does not play a significant role in quicksort. The array is already sorted at the end of the conquer step.
    The advantage of quicksort over merge sort is that it does not require any extra space to sort the given array.
    There are many ways to pick a pivot element:
        1. Always pick the first element as the pivot.
        2. Always pick the last element as the pivot.
        3. Pick a random element as the pivot.
        4. Pick the middle element as the pivot.