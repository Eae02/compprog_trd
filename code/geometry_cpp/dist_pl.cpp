double distPL(ipoint a, ipoint b, ipoint p) {
	return b.cross(p, a) / sqrt((a - b).len2());
}
