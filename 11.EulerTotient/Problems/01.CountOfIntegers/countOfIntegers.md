## Count of integers

You are given a positive integer n, for Q queries, You are required to determine the number of integers k (1≤k≤n) such that gcd(k,n)!=1 and gcd(k,n)!=k.

#### Input format

First line: Integer Q denoting the number of queries
Next Q lines: Integer n

#### Output format

Print Q lines each containing an integer that denotes the answer to that specific query.

```
Constraints

1≤Q≤105

1≤n≤106
```

```
SAMPLE INPUT
1
10

SAMPLE OUTPUT
3

Explanation
For c = {1,3,7,9} gcd(c,10) = 1

For c = {2,5,10} gcd(c,10) = c

gcd(4,10) = 2

gcd(6,10) = 2

gcd(8,10) = 2

So, answer is 3.
```

```
Time Limit: 1.0 sec(s) for each input file.
Memory Limit: 256 MB
Source Limit: 1024 KB
```
