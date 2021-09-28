vector<int> val, comp, z, cont; int Time, ncomps;
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
	val.assign(g.size(), 0);
	comp.assign(g.size(), -1);
	Time = ncomps = 0;
	for(size_t i = 0; i < g.size(); i++)
		if (comp[i] < 0) dfs(i, g, f);
}
