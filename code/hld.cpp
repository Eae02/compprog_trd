struct HLD { /**
	 * depth[i] = depth of node i
	 * parent[i] = parent of node i, or -1 for i=0
	 * arridx[i] = array index of node i for range queries
	 * hpLeaf[i] = leaf node of the heavy path passing through node i
	 * hpRoot[i] = root node of the heavy path passing through node i
	 * hchild[i] = heavy child (as a node index) for node i, or -1 for leaf nodes
	 */
	vector<ll> depth, parent, arridx, hpLeaf, hpRoot, hchild;
	HLD(const vector<vector<ll>>& t) { // t is an adjacency list, or a child list for a tree rooted in node 0
		parent = hchild = vector<ll>(t.size(), -1);
		depth = arridx = hpLeaf = hpRoot = vector<ll>(t.size());
		vector<ll> sts(t.size(), 1), ci(t.size()), st{0}, trav{0};
		while (!st.empty()) {
			ll cur = st.back(), nx;
			if (ci[cur] == (ll)t[cur].size()) {
				st.pop_back();
				if (st.empty()) continue;
				sts[st.back()] += sts[cur];
				if (hchild[st.back()] == -1 || sts[cur] > sts[hchild[st.back()]])
					hchild[st.back()] = cur;
			} else if ((nx = t[cur][ci[cur]++]) != parent[cur]) {
				depth[nx] = depth[cur] + 1;
				parent[nx] = cur;
				st.push_back(nx);
				trav.push_back(nx);
			}
		}
		iota(all(hpRoot), 0);
		iota(all(hpLeaf), 0);
		ll nai = 0;
		for (ll cur : trav) {
			if (hchild[cur] == -1) {
				arridx[cur] = nai;
				nai += depth[cur] - depth[hpRoot[cur]] + 1;
			}
			else
				hpRoot[hchild[cur]] = hpRoot[cur];
		}
		for (ll i = trav.size() - 1; i >= 0; i--) {
			if (hchild[trav[i]] == -1) continue;
			arridx[trav[i]] = arridx[hchild[trav[i]]] + 1;
			hpLeaf[trav[i]] = hpLeaf[hchild[trav[i]]];
		}
	} /**
	 * Returns the lca of a and b. If intv is not null, *intv will receive up to
	 * 2log_2(n) intervals such that for all nodes x on the path between a and b,
	 * there is exactly one i where intv[i].first <= arridx[x] < intv[i].second.
	 * If intvIncludeLCA is false, the lca of a and b will not be included in these intervals.
	 */
	ll lca(ll a, ll b, vector<pair<ll, ll>>* intv = nullptr, bool intvIncludeLCA = true) {
		vector<ll> plo;
		auto sdepth = [&] (ll i) { return i == -1 ? -1 : depth[i]; };
		while (hpRoot[a] != hpRoot[b]) {
			ll nxa = parent[hpRoot[a]];
			ll nxb = parent[hpRoot[b]];
			if (sdepth(nxa) > sdepth(nxb)) {
				plo.push_back(a);
				a = nxa;
			} else {
				plo.push_back(b);
				b = nxb;
			}
		}
		if (depth[a] > depth[b])
			swap(a, b);
		auto addi = [&] (ll lo, ll hi) { if (intv && lo != hi) intv->emplace_back(lo, hi); };
		for (ll pl : plo)
			addi(arridx[pl], arridx[hpRoot[pl]] + (hpRoot[pl] != a));
		addi(arridx[b], arridx[a] + intvIncludeLCA);
		return a;
	}
};
