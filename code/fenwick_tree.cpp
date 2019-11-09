struct FenwickTree {
	FenwickTree(ll n) : v(n + 1, 0) { }
	ll lsb(ll x) { return x & (-x); }
	ll prefixSum(ll n) { //sum of the first n items (nth not included)
		ll sum = 0;
		for (; n; n -= lsb(n))
			sum += v[n];
		return sum;
	}
	void adjust(ll i, ll delta) {
		for (i++; i < v.size(); i += lsb(i))
			v[i] += delta;
	}
	vector<ll> v;
};
