vector<dpoint> intersectSS(ipoint s1, ipoint e1, ipoint s2, ipoint e2) {
	auto oa = e2.cross(s1, s2);
	auto ob = e2.cross(e1, s2);
	auto oc = e1.cross(s2, s1);
	auto od = e1.cross(e2, s1);
	if (sign(oa)*sign(ob)<0 && sign(oc)*sign(od)<0) {
		return { dpoint(s1.x * ob - e1.x * oa,
		                s1.y * ob - e1.y * oa)
		          / double(ob - oa) };
	}
	set<ipoint> s;
	if (onSegment(s2, e2, s1)) s.insert(s1);
	if (onSegment(s2, e2, e1)) s.insert(e1);
	if (onSegment(s1, e1, s2)) s.insert(s2);
	if (onSegment(s1, e1, e2)) s.insert(e2);
	return {all(s)};
}
