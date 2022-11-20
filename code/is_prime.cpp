#include "modmul.cpp"
bool isPrime(ull n) {
	if (n < 2 || n % 6 % 4 != 1)
		return (n | 1) == 3;
	ull s = __builtin_ctzll(n-1);
	for (ull a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
		ull p = modpow(a % n, n >> s, n), i = s;
		while (p != 1 && p != n - 1 && a % n && i--)
			p = modmul(p, p, n);
		if (p != n-1 && i != s) return 0;
	}
	return 1;
}
