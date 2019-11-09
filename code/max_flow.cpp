struct Dinic {
	struct Edge { ll to, rev, cap, flow; };
	vector<vector<Edge>> adj;
	Dinic(ll n) : lvl(n), ptr(n), q(n), adj(n) {}
	void addEdge(ll a, ll b, ll cap, ll rcap = 0) {
		adj[a].push_back({b, adj[b].size(), cap, 0});
		adj[b].push_back({a, adj[a].size() - 1, rcap, 0});
	}
	ll calc(ll src, ll snk) {
		ll flow = 0; q[0] = src;
		for(ll L = 0; L < 31; L++) do {
			lvl = ptr = vector<ll>(q.size());
			ll qi = 0, qe = lvl[src] = 1;
			while (qi < qe && !lvl[snk]) {
				ll v = q[qi++];
				for(auto& e : adj[v])
					if (!lvl[e.to] && (e.cap - e.flow) >> (30 - L))
						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
			}
			while (ll p = dfs(src, snk, LLONG_MAX)) flow += p;
		} while (lvl[snk]);
		return flow;
	}
	vector<ll> lvl, ptr, q;
	ll dfs(ll v, ll t, ll f) {
		if (v == t || !f) return f;
		for (ll& i = ptr[v]; i < adj[v].size(); i++) {
			Edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (ll p = dfs(e.to, t, min(f, e.cap - e.flow))) {
					e.flow += p, adj[e.to][e.rev].flow -= p;
					return p;
				}
		}
		return 0;
	}
};
