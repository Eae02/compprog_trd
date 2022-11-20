from math import gcd
def pollard(n):
	f = lambda x: x * x % n + 1
	x, y, t, prd, i = 0, 0, 30, 2, 1
	while t % 40 or gcd(prd, n) == 1:
		if x == y:
			i += 1
			x, y = i, f(i)
		if q := prd * (max(x,y) - min(x,y)) % n:
			prd = q
		x, y = f(x), f(f(y))
		t += 1
	return gcd(prd, n)
def factor(n):
	if n == 1: return []
	if isPrime(n): return [n]
	x = pollard(n)
	return factor(x) + factor(n // x)
