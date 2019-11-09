def intersectCC(c1, c2, r1, r2):
	if c1 == c2:
		assert(r1 != r2)
		return None
	vec = vecsub(c2, c1)
	d2, sm, dif = len2(vec), r1 + r2, r1 - r2
	if sm ** 2 < d2 or dif ** 2 > d2:
		return None
	p = (d2 + r1 ** 2 - r2 ** 2) / (d2 * 2)
	h2 = r1 ** 2 - p * p * d2
	mid = (c1[0] + vec[0] * p, c1[1] + vec[1] * p)
	plen = sqrt(max(0, h2) / d2)
	per = (-vec[1] * plen, vec[0] * plen)
	return (vecadd(mid, per), vecsub(mid, per))
