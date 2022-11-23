def circleTangents(c1, r1, c2, r2):
	d = vecsub(c2, c1)
	dr, d2 = r1 - r2, len2(d)
	h2, s1, s2 = d2 - dr**2, r1 / d2, r2 / d2
	if d2 == 0 or h2 < 0: return []
	out = []
	for s in [-1, 1]:
		vx = d[0] * dr - d[1] * sqrt(h2) * s
		vy = d[1] * dr + d[0] * sqrt(h2) * s
		out.append((vecadd(c1, (vx*s1, vy*s1)),
		            vecadd(c2, (vx*s2, vy*s2))))
	if h2 == 0: out.pop()
	return out
