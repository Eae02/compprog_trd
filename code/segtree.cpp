struct SegTree {
	using T = ll;
	T f(T a, T b) { return a + b; }
	static constexpr T UNIT = 0;//neutral value for f
	
	vector<T> s; ll n;
	SegTree(ll len) : s(2 * len, UNIT), n(len) {}
	void set(ll pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(ll lo, ll hi) { // hi not included
		T ra = UNIT, rb = UNIT;
		for (lo+=n, hi+=n; lo < hi; lo/=2, hi/=2) {
			if (lo % 2) ra = f(ra, s[lo++]);
			if (hi % 2) rb = f(s[--hi], rb);
		}
		return f(ra, rb);
	}
};
