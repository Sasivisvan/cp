def solve(n, m, p, k, j):
    ate = (m // k) + (p // j)
    if m % k != 0 or p % j != 0:
        ate += 1
        
    if n - ate < 0:
        return 0
    return n - ate

print(solve(20, 12, 12, 2, 3))
print(solve(20, 10, 10, 3, 2))
print(solve(10, 5, 5, 2, 2))