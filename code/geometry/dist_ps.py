def distPS(s, e, p):
	if s == e:
		return sqrt(dist2(p, s))
	se, sp = vecsub(e, s), vecsub(p, s)
	d = len2(se)
	t = min(d, max(0, dot(vecsub(p, s), vecsub(e, s))))
	return sqrt(dist2((sp[0] * d, sp[1] * d), (se[0] * t, se[1] * t))) / d
