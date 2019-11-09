def pointInPolygon(poly, pt, strict = True):
	c = False
	for i in range(len(poly)):
		q = poly[i - 1]
		if onSegment(q, poly[i], pt):
			return not strict
		c ^= ((pt[1] < q[1]) - (pt[1] < poly[i][1])) * cross(q, poly[i], pt) > 0
	return c
