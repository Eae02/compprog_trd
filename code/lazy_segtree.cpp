struct LazyST {
	using T = ll;
	
	T fUpdate(T a, T b) { return a + b; }
	T fQuery(T a, T b) { return min(a, b); }
	static const T UPDATE_UNIT = 0;        // neutral value or fUpdate
	static const T QUERY_UNIT = LLONG_MAX; // neutral value for fQuery
	
	struct Node {
		T val = QUERY_UNIT; // current value of this segment
		T p = UPDATE_UNIT; // value being pushed down into this segment
	};
	int len; vector<Node> nodes;
	
	LazyST(int l) : len(pow(2, ceil(log2(l)))), nodes(len * 2) { }
	void update(int lo, int hi, T val) { u(lo, hi, val, 1, 0, len); }
	T query(int lo, int hi) { return q(lo, hi, 1, 0, len); }
	
private:
	#define LST_NEXT int l = n * 2; int r = l + 1; int mid = (nlo + nhi) / 2
	void push(int n, int nlo, int nhi) {
		if (nodes[n].p == UPDATE_UNIT) return;
		LST_NEXT;
		u(nlo, nhi, nodes[n].p, l, nlo, mid);
		u(nlo, nhi, nodes[n].p, r, mid, nhi);
		nodes[n].p = UPDATE_UNIT;
	}
	void u(int qlo, int qhi, T val, int n, int nlo, int nhi) {
		if (nhi <= qlo || nlo >= qhi) return;
		if (nlo >= qlo && nhi <= qhi) {
			nodes[n].p = fUpdate(nodes[n].p, val);
			nodes[n].val = fUpdate(nodes[n].val, val);
		} else {
			push(n, nlo, nhi); LST_NEXT;
			u(qlo, qhi, val, l, nlo, mid);
			u(qlo, qhi, val, r, mid, nhi);
			nodes[n].val = fQuery(nodes[l].val, nodes[r].val);
		}
	}
	T q(int qlo, int qhi, int n, int nlo, int nhi) {
		if (nhi <= qlo || nlo >= qhi) return QUERY_UNIT;
		if (nlo >= qlo && nhi <= qhi) return nodes[n].val;
		push(n, nlo, nhi); LST_NEXT;
		return fQuery(q(qlo, qhi, l, nlo, mid), q(qlo, qhi, r, mid, nhi));
	}
};
