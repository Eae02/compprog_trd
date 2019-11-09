#include "common.hpp"

template <typename T, typename C = less<T>>
class SegTreeIdx {
public:
	SegTreeIdx(vector<T> v) : val(move(v)), nodes(val.size() * 2 + 1) {
		for (ll i = val.size() - 1; i >= 0; i--)
			update(i, 1, 0, val.size());
	}
	void set(ll i, T v) {
		val[i] = v;
		update(i, 1, 0, val.size());
	}
	ll query(ll lo, ll hi) { return query(1, 0, val.size(), lo, hi); }
	vector<T> val;
private:
	void update(ll i, ll n, ll nLo, ll nHi) {
		if (nLo == nHi - 1) { nodes[n] = i; return; }
		ll mid = nLo + (nHi - nLo) / 2;
		if (i < mid)
			update(i, n * 2, nLo, mid);
		else
			update(i, n * 2 + 1, mid, nHi);
		ll* np = &nodes[n * 2];
		nodes[n] = C()(val[*np], val[np[1]]) ? *np : np[1];
	}
	ll query(ll n, ll nLo, ll nHi, ll qLo, ll qHi) {
		if (nHi <= qLo || nLo >= qHi) return -1;
		if (nLo >= qLo && nHi <= qHi) return nodes[n];
		ll mid = nLo + (nHi - nLo) / 2;
		ll ql = query(n * 2, nLo, mid, qLo, qHi);
		ll qr = query(n * 2 + 1, mid, nHi, qLo, qHi);
		if (ql == -1) return qr;
		if (qr == -1) return ql;
		return C()(val[ql], val[qr]) ? ql : qr;
	}
	vector<ll> nodes;
};
