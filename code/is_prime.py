def ctz(x): return (x & -x).bit_length() - 1
A = [2,325,9375,28178,450775,9780504,1795265022]
def isPrime(n):
	if n < 2 or n % 6 % 4 != 1:
		return (n | 1) == 3
	s = ctz(n-1)
	for a in A:
		p, i = pow(a % n, n >> s, n), s
		while p != 1 and p != n - 1 and a % n and i:
			p, i = p * p % n, i - 1
		if p != n-1 and i != s:
			return False
	return True
