const ll inf = 1LL << 62;
struct Ed {
	int a, b, w;
	int s() { return a < b ? a : -a; }
};
struct Node { ll dist = inf; int prev = -1; };
void bellmanFord(vector<Node>& nodes, vector<Ed>& eds, int s) {
	nodes[s].dist = 0;
	sort(all(eds), [] (Ed a, Ed b) { return a.s() < b.s(); });
	int lim = nodes.size() / 2 + 2;
	for(int i = 0; i < lim; i++)
		for(auto& ed : eds) {
			Node cur = nodes[ed.a], &dest = nodes[ed.b];
			if (abs(cur.dist) == inf) continue;
			ll d = cur.dist + ed.w;
			if (d < dest.dist) {
				dest.prev = ed.a;
				dest.dist = (i < lim - 1 ? d : -inf);
			}
		}
	for(int i = 0; i < lim; i++)
		for(auto& e : eds)
			if (nodes[e.a].dist == -inf)
				nodes[e.b].dist = -inf;
}
