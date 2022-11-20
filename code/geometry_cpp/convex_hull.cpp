auto convexHull(vector<ipoint> pts) {
	if (pts.size() <= 1) return pts;
	sort(all(pts));
	decltype(pts) h;
	auto f = [&] (ll s) {
		for (auto p : pts) {
			while ((ll)h.size() >= s + 2 && h.back().cross(p, h[h.size() - 2]) <= 0)
				h.pop_back();
			h.push_back(p);
		}
		h.pop_back();
	};
	f(0);
	reverse(all(pts));
	f(h.size());
	if (h.size() == 2 && h[0] == h[1]) h.pop_back();
	return h;
}
