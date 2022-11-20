vector<dpoint> intersectCL(dpoint c, double r, dpoint a, dpoint b) {
	dpoint ab = b - a;
	dpoint p = a + ab * (c-a).dot(ab) / ab.len2();
	double s = a.cross(b, c);
	double h2 = r*r - s*s / ab.len2();
	if (h2 < 0) return {};
	if (h2 == 0) return {p};
	dpoint h = ab * sqrt(h2 / ab.len2());
	return {p - h, p + h};
}
