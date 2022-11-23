vector<pair<dpoint, dpoint>> circleTangents(dpoint c1, double r1, dpoint c2, double r2) {
	dpoint d = c2 - c1, dp = {-d.y, d.x};
	double dr = r1 - r2, d2 = d.len2();
	double h2 = d2 - dr * dr;
	if (d2 == 0 || h2 < 0)  return {};
	vector<pair<dpoint, dpoint>> out;
	for (double s : {-1, 1}) {
		dpoint v = (d * dr + dp * sqrt(h2) * s) / d2;
		out.push_back({c1 + v * r1, c2 + v * r2});
	}
	if (h2 == 0) out.pop_back();
	return out;
}
