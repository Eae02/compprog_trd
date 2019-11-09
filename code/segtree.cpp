struct SegTree {
	using T = ll;
	static constexpr T unit = 0;
	T f(T a, T b) { return a + b; }
	vector<T> s; ll n;
	SegTree(ll n) : s(2*n, unit), n(n) {}
	void set(ll pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(ll lo, ll hi) { // query lo to hi (hi not included)
		T ra = unit, rb = unit;
		for (lo += n, hi += n; lo < hi; lo /= 2, hi /= 2) {
			if (lo % 2) ra = f(ra, s[lo++]);
			if (hi % 2) rb = f(s[--hi], rb);
		}
		return f(ra, rb);
	}
};
