const ll inf = 1LL << 62;
void floydWarshall(vector<vector<ll>>& m) {
	int n = m.size();
	for(int i = 0; i < n; i++)
		m[i][i] = min(m[i][i], 0LL);
	for(int k = 0; k < n; k++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if (m[i][k] != inf && m[k][j] != inf)
					m[i][j] = min(m[i][j], max(m[i][k] + m[k][j], -inf));
	//only needed if weights can be negative:
	for(int k = 0; k < n; k++)
		if (m[k][k] < 0)
			for(int i = 0; i < n; i++)
				for(int j = 0; j < n; j++)
					if (m[i][k] != inf && m[k][j] != inf)
						m[i][j] = -inf;
}
