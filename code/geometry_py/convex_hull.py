def convexHull(pts):
	if len(pts) <= 1:
		return pts
	pts.sort()
	t, s, h = 0, 0, [0] * (len(pts) + 1)
	for i in range(2):
		for p in pts:
			while t >= s + 2 and cross(h[t - 1], p, h[t - 2]) <= 0:
				t -= 1
			h[t], t = p, t + 1
		s = t = t - 1
		pts.reverse()
	return h[:t - (t == 2 and h[0] == h[1])]
