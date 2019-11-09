struct Treap {
	Treap *l = 0, *r = 0;
	int y, c = 1;
	
	int val;
	Treap(int val) : y(rand()), val(val) { }
};

// returns the number of nodes in treap n
int trCount(Treap* n) {
	return n ? n->c : 0;
}
void trRecount(Treap* n) {
	n->c = trCount(n->l) + trCount(n->r) + 1;
}

// returns the treap node at the specified index
Treap* trAt(Treap* n, int idx) {
	if (!n || idx == trCount(n->l)) return n;
	if (idx > trCount(n->l))
		return trAt(n->r, idx - trCount(n->l) - 1);
	return trAt(n->l, idx);
}

// invokes f for every item in the treap n, ordered by index
template<class F> void trForeach(Treap* n, F f) {
	if (n) { trForeach(n->l, f); f(n->val); trForeach(n->r, f); }
}

// splits the treap n on index k, returning the left and right treap respectively
pair<Treap*, Treap*> trSplit(Treap* n, int k) {
	if (!n) return {};
	if (trCount(n->l) >= k) { // use "if (n->val >= k) {" to split on value instead of index
		auto pa = trSplit(n->l, k);
		n->l = pa.second;
		trRecount(n);
		return {pa.first, n};
	} else {
		// use "auto pa = trSplit(n->r, k);" to split on value instead of index
		auto pa = trSplit(n->r, k - trCount(n->l) - 1); 
		n->r = pa.first;
		trRecount(n);
		return {n, pa.second};
	}
}

Treap* trJoin(Treap* l, Treap* r) {
	if (!l) return r;
	if (!r) return l;
	if (l->y > r->y) {
		l->r = trJoin(l->r, r);
		trRecount(l);
		return l;
	} else {
		r->l = trJoin(l, r->l);
		trRecount(r);
		return r;
	}
}

// inserts the treap n into t at index pos (or value pos, depending on implementation of trSplit)
Treap* trInsert(Treap* t, Treap* n, int pos) {
	auto pa = trSplit(t, pos);
	return trJoin(trJoin(pa.first, n), pa.second);
}
