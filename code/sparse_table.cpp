struct SparseTable {
	using T = ll;
	T f(T a, T b) { return min(a, b); }
	ll node(ll l, ll i) { return i + l * n; }
	ll n; vector<T> v;
	SparseTable(vector<T> values) : n(values.size()), v(move(values)) {
		ll d = log2(n);
		v.resize((d + 1) * n);
		for (ll L = 0, s = 1; L < d; L++, s *= 2) {
			for (ll i = 0; i < n; i++) {
				v[node(L + 1, i)] = f(v[node(L, i)], v[node(L, min(i + s, n - 1))]);
			}
		}
	}
	T query(ll lo, ll hi) { assert(hi > lo);
		ll l = (ll)log2(hi - lo);
		return f(v[node(l, lo)], v[node(l, hi - (1 << l))]);
	}
};
