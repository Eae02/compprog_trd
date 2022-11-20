template<class F>
ll ternarySearch(ll a, ll b, F f) {
	assert(a <= b);
	while (b - a >= 5) {
		ll mid = (a + b) / 2;
		if (f(mid) < f(mid+1)) // <= for last index
			a = mid;
		else
			b = mid+1;
	}
	//for (ll i = b; i > a; i--) to get last index
	for (ll i = a + 1; i <= b; i++)
		if (f(a) < f(i))
			a = i;
	return a;
}
