struct BCC {
	const vector<vector<ll>>* adj;
	vector<ll> dfsNum;
	ll nnum = 0;
	vector<pair<ll, ll>> st;
	vector<vector<pair<ll, ll>>> bccs;
	ll dfs(ll cur, ll par) {
		ll top = dfsNum[cur] = ++nnum;
		for (ll nxt : (*adj)[cur]) {
			if (nxt == par) continue;
			if (dfsNum[nxt]) {
				top = min(top, dfsNum[nxt]);
				if (dfsNum[nxt] < dfsNum[cur])
					st.emplace_back(cur, nxt);
				continue;
			}
			ll si = st.size();
			ll up = dfs(nxt, cur);
			top = min(top, up);
			if (up == dfsNum[cur]) {
				bccs.emplace_back(st.begin() + si, st.end());
				bccs.back().emplace_back(cur, nxt);
				st.resize(si);
			} else if (up < dfsNum[cur]) {
				st.emplace_back(cur, nxt);
			} else { //the edge (cur,nxt) is a bridge
				bccs.push_back({make_pair(cur, nxt)}); //remove if bridges should not form BCCs
			}
		}
		return top;
	}
};
vector<vector<pair<ll, ll>>> findBCC(const vector<vector<ll>>& adj) {
	BCC bcc = { &adj, vector<ll>(adj.size()) };
	for (ll i = 0; i < (ll)adj.size(); i++)
		if (bcc.dfsNum[i] == 0)
			bcc.dfs(i, -1);
	return move(bcc.bccs);
}
