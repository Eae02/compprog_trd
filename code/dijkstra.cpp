template<typename T> vector<T> dijkstra(ll start, const vector<vector<pair<ll, T>>>& adj) {
	vector<T> dist(adj.size(), numeric_limits<T>::max());
	dist[start] = 0;
	priority_queue<pair<T, ll>, vector<pair<T, ll>>, greater<>> pq;
	pq.emplace(dist[start], start);
	while (!pq.empty()) {
		ll cn = pq.top().second; pq.pop();
		for (auto [n, d] : adj[cn]) {
			T nd = dist[cn] + d;
			if (nd < dist[n]) pq.emplace(dist[n] = nd, n);
		}
	}
	return dist;
}
