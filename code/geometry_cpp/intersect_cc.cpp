template <typename T> optional<array<dpoint, 2>>
intersectCC(point<T> c1, point<T> c2, T r1, T r2) {
	if (c1 == c2) {
		assert(r1 != r2);
		return { };
	}
	auto vec = c2 - c1;
	T d2 = vec.len2(), sm = r1 + r2, dif = r1 - r2;
	if (sm * sm < d2 || dif * dif > d2)
		return { };
	double p = double(d2 + r1*r1 - r2*r2) / (d2 * 2);
	dpoint mid(c1.x + vec.x * p, c1.y + vec.y * p);
	dpoint per = dpoint(-vec.y, vec.x) * sqrt(max(0.0, r1 * r1 - p * p * d2) / d2);
	return { { mid+per, mid-per } };
}
