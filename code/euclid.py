def extEuclid(a, b):
	if b:
		d, x, y = extEuclid(b, a % b)
		return (d, y, x - a // b * y)
	return (a, 1, 0)
