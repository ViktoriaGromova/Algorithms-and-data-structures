# Binary Search  

## Description  
Binary search works on sorted arrays. Binary search begins by comparing an element in the middle of the array with the target value. If the target value matches the element, its position in the array is returned. If the target value is less than the element, the search continues in the lower half of the array. If the target value is greater than the element, the search continues in the upper half of the array. By doing this, the algorithm eliminates the half in which the target value cannot lie in each iteration.  

Average Time Complexity: O(log n)  
Data Structure: Array  
Space Complexity: O(1)  

## Build 
```bash
mkdir build
cmake ..
make --jobs=$(nproc --all)
```

## Test  

To build and run tests, add the `-DENABLE_TESTS=ON` flag when building. 
