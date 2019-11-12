ll crt(const vector<pair<ll, ll>>& eq) {
	ll p = 1, res = 0;
	for (auto e : eq) p *= e.second;
	for (auto e : eq) {
		ll pp = p / e.second, ppi, y;
		extEuclid(pp, e.second, ppi, y);
		res = (res + e.first * ppi * pp) % p;
	}
	return res;
}
