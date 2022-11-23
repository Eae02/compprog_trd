pair<dpoint, double> circumcirle(array<dpoint,3> p) {
	auto b = p[2] - p[0], c = p[1] - p[0];
	double bc = b.cross(c);
	assert(!zero(bc)); // collinear
	auto x = b * c.len2() - c * b.len2();
	dpoint rc = dpoint(-x.y, x.x) / bc;
	return { p[0] + rc, sqrt(rc.len2()) };
}
