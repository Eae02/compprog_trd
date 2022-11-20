#include "is_prime.cpp"
ull pollard(ull n) {
	auto f = [n](ull x) {return modmul(x, x, n)+1;};
	ull x = 0, y = 0, t = 30, prd = 2, i = 1;
	while (t++ % 40 || gcd(prd, n) == 1) {
		if (x == y) x = ++i, y = f(x);
		ull q = modmul(prd, max(x,y)-min(x,y), n);
		if (q) prd = q;
		x = f(x), y = f(f(y));
	}
	return gcd(prd, n);
}
vector<ull> factor(ull n) {
	if (n == 1) return {};
	if (isPrime(n)) return {n};
	ull x = pollard(n);
	auto l = factor(x), r = factor(n / x);
	l.insert(l.end(), all(r));
	return l;
}
