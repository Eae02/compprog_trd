ll polygonArea2(const vector<ipoint>& v) {
	ll a = 0;
	for (ll i = 0; i < (ll)v.size(); i++)
		a += v[i].cross(v[(i+1) % v.size()]);
	return a;
}
