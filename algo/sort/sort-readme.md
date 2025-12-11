# Sorting Algo

## Bubble Sort

### Pseudocode
```
Algorithm: BubbleSort(A)
    Input: An array A of n elements
    Output: The array A sorted in ascending order
    n ← length(A)
    for i ← 0 to n - 2 do
        swapped ← false
        for j ← 0 to n - i - 2 do
            if A[j] > A[j + 1] then
                swap A[j] and A[j + 1]
                swapped ← true
        if swapped = false then
            break
    return A
```

## Insertion Sort

### Pseudocode
```
Algorithm: InsertionSortWithForLoop(A)
    Input: An array A of n elements
    Output: The array A sorted in ascending order
    n ← length(A)
    for i ← 1 to n-1 do
        for j ← i down to 0 do
            if A[j-1] > A[j] then
                swap A[j-1], A[j]
            else
                break
    return A

Algorithm: InsertionSortWithShift(A)
    for i ← 1 to n
        key = A[i]
        j = i-1
        while j >= 0 and A[j] > key do
            A[j+1] ← A[j]
            j ← j - 1
        A[j+1] ← key
    return A
```

## Selection Sort

### Pseudocode
```
Algorithm: SelectionSort(A)
    n ← length(A)
    for i ← 0 to n-1 do
        indexMin ← i
        for j ← i+1 to n-1 do
            if A[j] < A[indexMin] do
                indexMin = j
        if indexMin !=  i do
            swap A[i], A[indexMin]
            

```
