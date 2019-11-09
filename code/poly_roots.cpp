struct Poly {
	vector<double> a;
	double operator()(double x) const {
		double val = 0;
		for(int i = a.size(); i--;)
			(val *= x) += a[i];
		return val;
	}
	void diff() {
		for (size_t i = 1; i < a.size(); i++)
			a[i - 1] = i * a[i];
		a.pop_back();
	}
};
vector<double> poly_roots(Poly p, double xmin, double xmax) {
	if (p.a.size() == 2) return { -p.a[0] / p.a[1] };
	vector<double> ret;
	Poly der = p;
	der.diff();
	auto dr = poly_roots(der, xmin, xmax);
	dr.push_back(xmin - 1);
	dr.push_back(xmax + 1);
	sort(all(dr));
	for (size_t i = 0; i < dr.size() - 1; i++) {
		double l = dr[i], h = dr[i + 1];
		bool sign = p(l) > 0;
		if (sign ^ (p(h) > 0)) {
			for (int it = 0; it < 60; it++) {
				double m = (l + h) / 2, f = p(m);
				if ((f <= 0) ^ sign) l = m;
				else h = m;
			}
			ret.push_back((l + h) / 2);
		}
	}
	return ret;
}
