int solveLinear(vector<vector<double>> A, vector<double> b, vector<double>& x) {
	const double eps = 1e-12;
	int n = A.size(), m = x.size(), rank = 0, br, bc;
	if (n) assert((int)A[0].size() == m);
	vector<int> col(m); iota(all(col), 0);
	for(int i = 0; i < n; i++) {
		double v, bv = 0;
		for(int r = i; r < n; ++r)
			for(int c = i; c < m; c++)
				if ((v = fabs(A[r][c])) > bv)
					br = r, bc = c, bv = v;
		if (bv <= eps) {
			for(int j = i; j < n; j++)
				if (fabs(b[j]) > eps) return -1;
			break;
		}
		swap(A[i], A[br]);
		swap(b[i], b[br]);
		swap(col[i], col[bc]);
		for(int j = 0; j < n; j++)
			swap(A[j][i], A[j][bc]);
		bv = 1 / A[i][i];
		// for all solutions do: for (ll j = 0; j < n; j++) { if (j != i) continue;
		for(int j = i + 1; j < n; j++) {
			double fac = A[j][i] * bv;
			b[j] -= fac * b[i];
			for(int k = i+1; k < (m); ++k)
				A[j][k] -= fac*A[i][k];
		}
		rank++;
	}
	// for all solutions do:
	// x.assign(m, undefined);
	// for(int i = 0; i < rank; i++) {
	//     for (int j = rank; j < m; j++)
	//         if (fabs(A[i][j]) > eps) goto fail;
	//     x[col[i]] = b[i] / A[i][i];
	//     fail:;
	// }
	x.assign(m, 0);
	for (int i = rank; i--;) {
		b[i] /= A[i][i];
		x[col[i]] = b[i];
		for (int j = 0; j < i; j++)
			b[j] -= A[j][i] * b[i];
	}
	return rank;
}
