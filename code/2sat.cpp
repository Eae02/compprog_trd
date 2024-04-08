struct TwoSat {
int N;
vector<vector<int>> gr;
vector<int> values; // 0 = false, 1 = true
TwoSat(int n = 0) : N(n), gr(2 * n) {}
void either(int f, int j) {
	f = max(2 * f, -1-2*f);
	j = max(2 * j, -1-2*j);
	gr[f].push_back(j ^ 1);
	gr[j].push_back(f ^ 1);
}
void set_value(int x) { either(x, x); }
vector<int> val, comp, z; int time = 0;
int dfs(int i) {
	int low = val[i] = ++time, x;
	z.push_back(i);
	for(auto& e : gr[i])
		if (!comp[e])
			low = min(low, val[e] ?: dfs(e));
	if (low == val[i]) do {
		x = z.back(); z.pop_back();
		comp[x] = low;
		if (values[x>>1] == -1)
			values[x>>1] = x&1;
	} while (x != i);
	return val[i] = low;
}
bool solve() {
	values.assign(N, -1);
	val.assign(2 * N, 0); comp = val;
	for (int i = 0; i < 2 * N; ++i)
		if (!comp[i])
			dfs(i);
	for (int i = 0; i < N; ++i)
		if (comp[2 * i] == comp[2 * i + 1])
			return 0;
	return 1;
}
int add_var() { //optional
	gr.emplace_back();
	gr.emplace_back();
	return N++;
}
void at_most_one(const vector<int>& li) { //optional
	if (li.size() <= 1) return;
	int cur = ~li[0];
	for(size_t i = 2; i < li.size(); i++) {
		int next = add_var();
		either(cur, ~li[i]);
		either(cur, next);
		either(~li[i], next);
		cur = ~next;
	}
	either(cur, ~li[1]);
}
};
