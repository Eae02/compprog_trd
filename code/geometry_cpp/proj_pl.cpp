dpoint projPL(ipoint a, ipoint b, ipoint p, bool refl = false) {
	auto v = b - a;
	double s = (1 + refl) * b.cross(p, a) / v.len2();
	return { p.x + v.y * s, p.y - v.x * s };
}
