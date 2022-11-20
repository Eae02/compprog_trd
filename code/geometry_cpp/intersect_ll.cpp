pair<int, dpoint> intersectLL(ipoint s1, ipoint e1, ipoint s2, ipoint e2) {
	auto d = (e1 - s1).cross(e2 - s2);
	if (zero(d)) # parallel
		return { -int(zero(e1.cross(s2, s1))), {} };
	auto p = e1.cross(e2, s2);
	auto q = e2.cross(s1, s2);
	return { 1, dpoint(
		(s1.x * p + e1.x * q),
		(s1.y * p + e1.y * q)
	) / d };
}
