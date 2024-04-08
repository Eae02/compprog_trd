double rat(dpoint a, dpoint b) { return sign(b.x) ? a.x/b.x : a.y/b.y; }
double polyUnion(vector<vector<dpoint>>& poly) {
	double ret = 0;
	for (size_t i = 0; i < poly.size(); i++)
		for (size_t v = 0; v < poly[i].size(); v++) {
			dpoint A = poly[i][v], B = poly[i][(v + 1) % poly[i].size()];
			vector<pair<double, int>> segs = {{0, 0}, {1, 0}};
			for (size_t j = 0; j < poly.size(); j++) if (i != j) {
				for (size_t u = 0; u < poly[j].size(); u++) {
					dpoint C = poly[j][u], D = poly[j][(u + 1) % poly[j].size()];
					int sc = sign(B.cross(C, A)), sd = sign(B.cross(D, A));
					if (sc != sd) {
						double sa = C.cross(D, A), sb = C.cross(D, B);
						if (min(sc, sd) < 0)
							segs.emplace_back(sa / (sa - sb), sign(sc - sd));
					} else if (!sc && !sd && j<i && sign((B-A).dot(D-C))>0){
						segs.emplace_back(rat(C - A, B - A), 1);
						segs.emplace_back(rat(D - A, B - A), -1);
					}
				}
			}
			sort(all(segs));
			for (auto& s : segs) s.first = min(max(s.first, 0.0), 1.0);
			double sum = 0;
			int cnt = segs[0].second;
			for (ll j = 1; j < (ll)segs.size(); j++) {
				if (!cnt) sum += segs[j].first - segs[j - 1].first;
				cnt += segs[j].second;
			}
			ret += A.cross(B) * sum;
		}
	return ret / 2;
}
