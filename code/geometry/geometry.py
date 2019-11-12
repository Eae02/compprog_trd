def vecsub(a, b):
	return (a[0] - b[0], a[1] - b[1])
def vecadd(a, b):
	return (a[0] + b[0], a[1] + b[1])
def dot(a, b):
	return a[0] * b[0] + a[1] * b[1]
def cross(a, b, o = (0, 0)):
	return (a[0] - o[0]) * (b[1] - o[1]) - (a[1] - o[1]) * (b[0] - o[0])
def len2(a):
	return a[0] ** 2 + a[1] ** 2
def dist2(a, b):
	return len2(vecsub(a, b))
def sign(x):
	return (x > 0) - (x < 0)
def zero(x):
	return abs(x) < 1E-9
