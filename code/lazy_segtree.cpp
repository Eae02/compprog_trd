struct LazyST {
	using T = ll;
	T f(T a, T b) { return min(a, b); }
	static const T QUERY_UNIT = LLONG_MAX; // neutral value for f
	
	struct Node {
		T val = QUERY_UNIT; // current value of this segment
		optional<T> p; // value being pushed down into this segment
	};
	int len; vector<Node> nodes;
	LazyST(int l) : len(pow(2, ceil(log2(l)))), nodes(len * 2) { }
	void update(int lo, int hi, T val) { u(lo, hi, val, 1, 0, len); }
	T query(int lo, int hi) { return q(lo, hi, 1, 0, len); }
private:
	#define LST_NEXT int l = n * 2; int r = l + 1; int mid = (nlo + nhi) / 2
	void push(int n, int nlo, int nhi) {
		if (!nodes[n].p) return;
		LST_NEXT;
		u(nlo, nhi, *nodes[n].p, l, nlo, mid);
		u(nlo, nhi, *nodes[n].p, r, mid, nhi);
		nodes[n].p = {};
	}
	void u(int qlo, int qhi, T val, int n, int nlo, int nhi) {
		if (nhi <= qlo || nlo >= qhi) return;
		if (nlo >= qlo && nhi <= qhi) {
			//for interval set:
			nodes[n].p = val;
			nodes[n].val = val; // val * (nhi - nlo) for sum queries
			//for interval add:
			nodes[n].p = nodes[n].p.get_or(0) + val;
			nodes[n].val += val; // val * (nhi - nlo) for sum queries
		} else {
			push(n, nlo, nhi); LST_NEXT;
			u(qlo, qhi, val, l, nlo, mid);
			u(qlo, qhi, val, r, mid, nhi);
			nodes[n].val = f(nodes[l].val, nodes[r].val);
		}
	}
	T q(int qlo, int qhi, int n, int nlo, int nhi) {
		if (nhi <= qlo || nlo >= qhi) return QUERY_UNIT;
		if (nlo >= qlo && nhi <= qhi) return nodes[n].val;
		push(n, nlo, nhi); LST_NEXT;
		return f(q(qlo, qhi, l, nlo, mid), q(qlo, qhi, r, mid, nhi));
	}
};
