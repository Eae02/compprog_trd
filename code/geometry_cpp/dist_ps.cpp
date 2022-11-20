double distPS(ipoint s, ipoint e, ipoint p) {
	if (s == e)
		return sqrt((p - s).len2());
	auto se = e - s;
	auto sp = p - s;
	ll d = se.len2();
	ll t = min(d, max(0LL, (p - s).dot(e - s)));
	return sqrt((sp * d - se * t).len2()) / d;
}
