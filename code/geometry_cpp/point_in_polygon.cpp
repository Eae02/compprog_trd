bool pointInPolygon(const vector<ipoint>& poly, ipoint p, bool strict = true) {
	bool c = false;
	auto prev = poly.back();
	for (auto cur : poly) {
		if (onSegment(prev, cur, p)) return !strict;
		c ^= ((p.y < prev.y) - (p.y < cur.y)) * prev.cross(cur, p) > 0;
		prev = cur;
	}
	return c;
}
