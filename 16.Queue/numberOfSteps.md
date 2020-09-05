## Minimum steps to reach end from start by performing multiplication and mod operations with array elements

Given start, end and an array of N numbers. At each step, start is multiplied with any number in the array and then mod operation with 100000 is done to get the new start. The task is to find the minimum steps in which end can be achieved starting from start.

link: https://www.geeksforgeeks.org/minimum-steps-to-reach-end-from-start-by-performing-multiplication-and-mod-operations-with-array-elements/

```
Examples:

Input: start = 3 end = 30 a[] = {2, 5, 7}
Output: 2
Step 1: 3*2 = 6 % 100000 = 6
Step 2: 6*5 = 30 % 100000 = 30

Input: start = 7 end = 66175 a[] = {3, 4, 65}
Output: 4
Step 1: 7*3 = 21 % 100000 = 21
Step 2: 21*3 = 6 % 100000 = 63
Step 3: 63*65 = 4095 % 100000 = 4095
Step 4: 4095*65 = 266175 % 100000 = 66175
```
