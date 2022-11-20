def intersectCL(c, r, a, b):
	ab = vecsub(b, a)
	ps = dot(vecsub(c, a), ab) / len2(ab)
	p = (a[0] + ab[0] * ps, a[1] + ab[1] * ps)
	h2 = r ** 2 - cross(a, b, c) ** 2 / len2(ab)
	if h2 < 0: return []
	if h2 == 0: return [p]
	h2 = sqrt(h2 / ab.len2())
	h = (ab[0] * h2, ab[1] * h2);
	return [vecsub(p, h), vecadd(p, h)]
