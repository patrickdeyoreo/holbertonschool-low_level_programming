#!/usr/bin/python3

products = (n * m for n in range(999, 99, -1) for m in range(n, 99, -1))

print(sorted(filter(lambda n: str(n) == str(n)[::-1], products))[-1])
