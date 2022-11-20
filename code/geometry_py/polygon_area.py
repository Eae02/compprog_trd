def polygonArea2(v):
	return sum(map(lambda i: cross(v[i - 1], v[i]), range(len(v))))
