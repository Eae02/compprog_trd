def crt(eq):
	p, res = 1, 0
	for rem, md in eq:
		p *= md
	for rem, md in eq:
		pp = p // md
		res = (res + rem * extEuclid(pp, md)[1] * pp) % p
	return res
