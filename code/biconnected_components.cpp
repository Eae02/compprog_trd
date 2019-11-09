vector<int> num, st;
vector<vector<pair<int, int>>> ed;
int Time;
template<class F> int dfs(int at, int par, F& f) {
	int me = num[at] = ++Time, e, y, top = me;
	for(auto& pa : ed[at]) {
		if (pa.second == par) continue;
		tie(y, e) = pa;
		if (num[y]) {
			top = min(top, num[y]);
			if (num[y] < me)
				st.push_back(e);
		} else {
			int si = st.size();
			int up = dfs(y, e, f);
			top = min(top, up);
			if (up == me) {
				st.push_back(e);
				f(vector<int>(st.begin() + si, st.end()));
				st.resize(si);
			}
			else if (up < me) st.push_back(e);
			else { /* e is a bridge */ }
		}
	}
	return top;
}
template<class F>
void bicomps(F f) {
	num.assign(ed.size(), 0);
	for(int i = 0; i < (int)ed.size(); i++)
		if (!num[i]) dfs(i, -1, f);
}
