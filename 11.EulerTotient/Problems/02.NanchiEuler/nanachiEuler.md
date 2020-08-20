## Nanachi and Euler function

Living alone with Mitty in the Abyss, Nanachi has developed an interest in number theory problems. Nanachi recently came up with the following problem but is unable to solve it.

Let ϕ(n) denote the count of positive integers up to n which are coprime with n. Since summations bore our Nanachi, Nanachi decided to evaluate the function f(n) instead which is defined as:

f(n)= ∏d|n ϕ(d)

where a|b mean a divides b. Nanachi seeks your help in finding the value of f(n).

#### INPUT

A single integer n

#### OUTPUT

Value of f(n). Since this value can be large, output it modulo 109+7.

```
CONSTRAINTS
1≤n≤1012

For 10% of the testcases, n≤106
```

```
SAMPLE INPUT
12

SAMPLE OUTPUT
32

Explanation
The divisors of 12 are 1,2,3,4,6 and 12 i.e f(n)=ϕ(1)⋅ϕ(2)⋅ϕ(3)⋅ϕ(4)⋅ϕ(6)⋅ϕ(12)

⇒f(n)=1⋅1⋅2⋅2⋅2⋅4=32
```

```
Time Limit: 1.0 sec(s) for each input file.
Memory Limit: 256 MB
Source Limit: 1024 KB
```
