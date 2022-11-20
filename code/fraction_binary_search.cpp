struct Frac { ll p, q; };
template<class F> Frac fractionBinarySearch(F f, ll N) {
	bool dir = 1, A = 1, B = 1;
	Frac lo{0, 1}, hi{1, 1}; // Set hi to 1/0 to search (0, N]
	if (f(lo)) return lo;
	assert(f(hi));
	while (A || B) {
		ll adv = 0, step = 1; // move hi if dir, else lo
		for (ll si = 0; step; (step *= 2) >>= si) {
			adv += step;
			Frac mid{lo.p * adv + hi.p, lo.q * adv + hi.q};
			if (abs(mid.p) > N || mid.q > N || dir == !f(mid))
				adv -= step; si = 2;
		}
		hi.p += lo.p * adv;
		hi.q += lo.q * adv;
		dir = !dir;
		swap(lo, hi);
		A = B; B = !!adv;
	}
	return dir ? hi : lo;
}
