vector<int> val, comp, z, cont;
int Time, ncomps;
template<class G, class F> int dfs(int j, G& g, F& f) {
	int low = val[j] = ++Time, x; z.push_back(j);
	for(auto& e : g[j]) if (comp[e] < 0)
		low = min(low, val[e] ?: dfs(e,g,f));
	if (low == val[j]) {
		do {
			x = z.back(); z.pop_back();
			comp[x] = ncomps;
			cont.push_back(x);
		} while (x != j);
		f(cont); cont.clear();
		ncomps++;
	}
	return val[j] = low;
}
template<class G, class F> void scc(G& g, F f) {
	int n = g.size();
	val.assign(n, 0); comp.assign(n, -1);
	Time = ncomps = 0;
	for(int i = 0; i < n; i++)
		if (comp[i] < 0) dfs(i, g, f);
}
