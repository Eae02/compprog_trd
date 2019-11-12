ll extEuclid(ll a, ll b, ll& x, ll& y) {
	if (b) {
		ll d = extEuclid(b, a % b, y, x);
		return y -= a / b * x, d;
	}
	return x = 1, y = 0, a;
}
