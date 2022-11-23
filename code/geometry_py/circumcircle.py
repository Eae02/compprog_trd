def circumcirle(p1, p2, p3):
	b, c = vecsub(p3, p1), vecsub(p2, p1)
	bc, c2, b2 = cross(b, c) * 2, len2(c), len2(b)
	assert not zero(bc) # collinear
	rc = ((c[1]*b2 - b[1]*c2)/bc,
	      (b[0]*c2 - c[0]*b2)/bc)
	return (vecadd(p1,rc), sqrt(len2(rc)))
