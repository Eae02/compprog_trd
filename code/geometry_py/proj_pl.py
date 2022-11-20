def projPL(a, b, p, refl = False):
	v = vecsub(b, a)
	s = (1 + refl) * cross(b, p, a) / len2(v)
	return (p[0] + v[1] * s, p[1] - v[0] * s)
