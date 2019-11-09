using Point = pair<ll, ll>;
ll cross(Point a, Point b, Point c) {
	return (a.first - c.first) * (b.second - c.second) -
	       (b.first - c.first) * (a.second - c.second);
}
vector<Point> convexHull(vector<Point> pts) {
	if (pts.size() <= 1) return pts;
	sort(all(pts));
	vector<Point> h(pts.size() + 1);
	ll t = 0, s = 0;
	for (ll i = 0; i < 2; i++) {
		for (Point p : pts) {
			while (t >= s + 2 && cross(h[t - 1], p, h[t - 2]) <= 0)
				t--;
			h[t++] = p;
		}
		s = --t;
		reverse(all(pts));
	}
	h.erase(h.begin() + t - (t == 2 && h[0] == h[1]), h.end());
	return h;
}
