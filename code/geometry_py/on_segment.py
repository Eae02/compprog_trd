def onSegment(s, e, p):
	# return zero(distPS(s, e, p))   if floating-point is OK
	return cross(s, e, p) == 0 and dot(vecsub(s, p), vecsub(e, p)) <= 0
