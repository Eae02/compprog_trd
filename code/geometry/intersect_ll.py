def intersectLL(s1, e1, s2, e2):
	d = cross(vecsub(e1, s1), vecsub(e2, s2))
	if zero(d): # parallel
		return (-zero(cross(e1, s2, s1)), (0, 0))
	p, q = cross(e1, e2, s2), cross(e2, s1, s2)
	return (1, ((s1[0] * p + e1[0] * q) / d, (s1[1] * p + e1[1] * q) / d))
