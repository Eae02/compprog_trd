double circlePolyArea(dpoint c, double r, vector<dpoint> ps) {
	auto arg = [&](dpoint p, dpoint q) { return atan2(p.cross(q), p.dot(q)); };
	auto tri = [&](dpoint p, dpoint q) {
		double r2 = r * r / 2;
		dpoint d = q - p;
		double a = d.dot(p)/d.len2(), b = (p.len2()-r*r)/d.len2();
		double det = a * a - b;
		if (det <= 0) return arg(p, q) * r2;
		auto s = max(0., -a-sqrt(det)), t = min(1., -a+sqrt(det));
		if (t < 0 || 1 <= s) return arg(p, q) * r2;
		dpoint u = p + d * s, v = p + d * t;
		return arg(p,u) * r2 + u.cross(v)/2 + arg(v,q) * r2;
	};
	double sum = 0.0;
	for (size_t i = 0; i < ps.size(); i++)
		sum += tri(ps[i] - c, ps[(i + 1) % ps.size()] - c);
	return sum;
}
