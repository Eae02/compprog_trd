def intersectSS(s1, e1, s2, e2):
	oa = cross(e2, s1, s2)
	ob = cross(e2, e1, s2)
	oc = cross(e1, s2, s1)
	od = cross(e1, e2, s1)
	if sign(oa)*sign(ob)<0 and sign(oc)*sign(od)<0:
		div = ob - oa
		return [(
			(s1[0] * ob - e1[0] * oa) / div,
			(s1[1] * ob - e1[1] * oa) / div
		)]
	s = set()
	if onSegment(s2, e2, s1): s.add(s1)
	if onSegment(s2, e2, e1): s.add(e1)
	if onSegment(s1, e1, s2): s.add(s2)
	if onSegment(s1, e1, e2): s.add(e2)
	return list(s)
