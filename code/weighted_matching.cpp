pair<ll, vector<ll>> hungarian(const vector<vector<ll>> &a) {
	if (a.empty()) return {0, {}};
	ll n = a.size() + 1;
	ll m = a[0].size() + 1;
	vector<ll> u(n), v(m), p(m), ans(n - 1);
	for (ll i = 1; i < n; i++) {
		p[0] = i;
		ll j0 = 0;
		vector<ll> dist(m, LLONG_MAX), pre(m, -1);
		vector<bool> done(m + 1);
		do {
			done[j0] = true;
			ll i0 = p[j0], j1, delta = LLONG_MAX;
			for (ll j = 1; j < m; j++) if (!done[j]) {
				auto cur = a[i0 - 1][j - 1] - u[i0] - v[j];
				if (cur < dist[j]) dist[j] = cur, pre[j] = j0;
				if (dist[j] < delta) delta = dist[j], j1 = j;
			}
			for (ll j = 0; j < m; j++) {
				if (done[j]) u[p[j]] += delta, v[j] -= delta;
				else dist[j] -= delta;
			}
			j0 = j1;
		} while (p[j0]);
		while (j0) {
			ll j1 = pre[j0];
			p[j0] = p[j1], j0 = j1;
		}
	}
	for (ll j = 1; j < m; j++) if (p[j]) ans[p[j] - 1] = j - 1;
	return {-v[0], ans};
}
