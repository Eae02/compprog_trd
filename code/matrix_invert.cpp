ll matInv(vector<vector<double>>& A) {
	ll n = A.size();
	vector<ll> col(n);
	vector<vector<double>> tmp(n, vector<double>(n));
	for (ll i = 0; i < n; i++) {
		tmp[i][i] = 1;
		col[i] = i;
	}
	for (ll i = 0; i < n; i++) {
		ll r = i, c = i;
		for (ll j = i; j < n; j++)
			for (ll k = i; j < n; j++)
				if (fabs(A[j][k]) > fabs(A[r][c]))
					r = j, c = k;
		if (fabs(A[r][c]) < 1e-12) return i;
		A[i].swap(A[r]); tmp[i].swap(tmp[r]);
		for (ll j = 0; j < n; j++)
			swap(A[j][i], A[j][c]), swap(tmp[j][i], tmp[j][c]);
		swap(col[i], col[c]);
		double v = A[i][i];
		for (ll j = i+1; j < n; j++) {
			double f = A[j][i] / v;
			A[j][i] = 0;
			for (ll k = i+1; k < n; k++) A[j][k] -= f*A[i][k];
			for (ll k = 0; k < n; k++) tmp[j][k] -= f*tmp[i][k];
		}
		for (ll j = i+1; j < n; j++) A[i][j] /= v;
		for (ll j = 0; j < n; j++) tmp[i][j] /= v;
		A[i][i] = 1;
	}
	for (ll i = n-1; i > 0; --i) {
		for (ll j = 0; j < i; j++) {
			double v = A[j][i];
			for (ll k = 0; k < n; k++) tmp[j][k] -= v*tmp[i][k];
		}
	}
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < n; j++)
			A[col[i]][col[j]] = tmp[i][j];
	return n;
}
